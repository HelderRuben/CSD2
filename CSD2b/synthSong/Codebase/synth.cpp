#include "synth.h"


Synth::Synth() : Synth(440.0f, 1.5f, "sine", "sine") {};
//constructor
Synth::Synth(
  float frequency,
  float ratio,
  std::string chosenCarrWaveform,
  std::string chosenModWaveform)
{
  std::cout << "\n\nSynth - Constructor\n";
  this->ratio = ratio;
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

void Synth::setSamplerate(float samplerate = 44100) {
  CarrAndMod[0]->setSamplerate(samplerate);
  CarrAndMod[1]->setSamplerate(samplerate);
};

void Synth::setFrequency(float frequency, float ratio) {
  CarrAndMod[0]->setFrequency(frequency);
  CarrAndMod[1]->setFrequency(frequency * ratio);
};

float Synth::getSample() {
  float carrierSample = CarrAndMod[0]->getSample();
  float modulatorSample = CarrAndMod[1]->getSample();
  float sample = modulate(carrierSample, modulatorSample) * 0.5f; //FM/RM and normalisation
  return sample;
};

float Synth::getRatio() {
  return this->ratio;
}

//setting waveforms and osc ratio to user's choice
void Synth::setOscs(
  std::string carrWaveform,
  std::string modWaveform,
  float ratio)
{
  if(carrWaveform == "saw") {
    CarrAndMod[0] = new Saw();
  } else if(carrWaveform == "sine") {
    CarrAndMod[0] = new Sine();
  } else if(carrWaveform == "square") {CarrAndMod[0] = new Square();};
  if(modWaveform == "saw") {
    CarrAndMod[1] = new Saw(440 * ratio, 44100);
  } else if(modWaveform == "sine") {
    CarrAndMod[1] = new Sine(440 * ratio, 44100);
  } else if(modWaveform == "square") {
    CarrAndMod[1] = new Square(440 * ratio, 44100);
  };
}
