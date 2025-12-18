#include "synth.h"


Synth::Synth() : Synth(440.0f, 1.5f, "sine", "sine") {};
//constructor
Synth::Synth(float frequency, float ratio, std::string chosenCarrWaveform, std::string chosenModWaveform) {
  //something with oscillators and ratios
  std::cout << "Synth - Constructor\n";
  //Linking to correct osc type
  // if(chosenCarrWaveform == "saw") {CarrAndMod[0] = new Saw(frequency);};
  // if(chosenCarrWaveform == "sine") {CarrAndMod[0] = new Sine(frequency);};
  // if(chosenCarrWaveform == "square") {CarrAndMod[0] = new Square(frequency);};
  // if(chosenModWaveform == "saw") {CarrAndMod[1] = new Saw(frequency * ratio);};
  // if(chosenModWaveform == "sine") {CarrAndMod[1] = new Sine(frequency * ratio);};
  // if(chosenModWaveform == "square") {CarrAndMod[1] = new Square(frequency * ratio);};
};

Synth::~Synth() {
  std::cout << "Synth - Destructor\n";
  //Deleting the set oscillators
  delete CarrAndMod[0];
  delete CarrAndMod[1];
};

void Synth::tick() {
  CarrAndMod[0]->tick();
  CarrAndMod[1]->tick();
};

//Something with amplitude? halving
float Synth::getSample() {
  float carrierSample = CarrAndMod[0]->getSample();
  float modulatorSample = CarrAndMod[1]->getSample();
  float sample = (carrierSample + modulatorSample) * 0.5; //2 oscs with amplitude
  return sample;
};

void Synth::setSamplerate(float samplerate = 44100) {
  CarrAndMod[0]->setSamplerate(samplerate);
  CarrAndMod[1]->setSamplerate(samplerate);
};

void Synth::setWaveforms(std::string carrWaveform, std::string modWaveform, float ratio) {
  if(carrWaveform == "saw") {
    CarrAndMod[0] = new Saw();
    std::cout << "CARRIER IS SAWWWW\n";
  } else if(carrWaveform == "sine") {
    CarrAndMod[0] = new Sine();
  } else if(carrWaveform == "square") {CarrAndMod[0] = new Square();};
  std::cout << "CARRIER IS DONE\n";
  if(modWaveform == "saw") {
    CarrAndMod[1] = new Saw(440 * ratio, 44100);
  } else if(modWaveform == "sine") {
    CarrAndMod[1] = new Sine(440 * ratio, 44100);
  } else if(modWaveform == "square") {
    CarrAndMod[1] = new Square(440 * ratio, 44100);
  };
  std::cout << "MODULATOR IS DONE\n";
}

// void Synth::setModWaveform(std::string waveform, float ratio) {
//   if(waveform == "saw") {CarrAndMod[1] = new Saw(440 * ratio);};
//   if(waveform == "sine") {CarrAndMod[1] = new Sine(440 * ratio);};
//   if(waveform == "square") {CarrAndMod[1] = new Square(440 * ratio);};
// }

// void Synth::setOscs(float frequency) {
//   CarrAndMod[0] = new Saw(frequency);
//   CarrAndMod[1] = new Square(frequency * ratio);
// }
//To set ratio of oscs
// void Synth::setRatio(float ratio) {
  // float baseFreq = sawOsc.getFrequency();
  // squareOsc.setFrequency(baseFreq * ratio);
// };
