#include "oscillator.h"

//Constructor and initialising list
Oscillator::Oscillator (float frequency, float samplerate) :
  frequency(frequency),
  samplerate(samplerate),
  amplitude(1.0f),
  phase(0),
  sample(0)
  {
  std::cout << "Oscillator constructed\n";
};

//Destructor
Oscillator::~Oscillator() {
  std::cout << "Oscillator destructed\n";
};

//Function Members
void Oscillator::tick() {
  //Phase update: Next Sample
  phase += frequency / samplerate;
  //Phase correction
  if (phase > 1.0f) phase -= 1.0f;
  //calculate sample of correct waveform
  calculate();
};

//Returns frequency
float Oscillator::getFrequency() {
  return frequency;
};

//Changes frequency value
void Oscillator::setFrequency (float frequency) {
  this->frequency = frequency;
};

//Changes samplerate value
void Oscillator::setSamplerate (float samplerate) {
  this->samplerate = samplerate;
};

//Returns current sample
float Oscillator::getSample() {
  return sample;
};
