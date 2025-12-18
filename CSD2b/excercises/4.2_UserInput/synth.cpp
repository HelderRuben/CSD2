#include "synth.h"

//constructor
Synth::Synth(float frequency, float ratio) {
  //something with oscillators and ratios
  std::cout << "Synth - Constructor\n";
  CarrAndMod[0] = new Saw(frequency);
  CarrAndMod[1] = new Square(frequency * ratio);
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



// void Synth::setOscs(float frequency) {
//   CarrAndMod[0] = new Saw(frequency);
//   CarrAndMod[1] = new Square(frequency * ratio);
// }
//To set ratio of oscs
// void Synth::setRatio(float ratio) {
  // float baseFreq = sawOsc.getFrequency();
  // squareOsc.setFrequency(baseFreq * ratio);
// };
