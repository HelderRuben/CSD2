//Including things
#include "sine.h"
#include "math.h"

//Constructor and initialiser list
Sine::Sine(float frequency, float samplerate) : frequency(frequency), amplitude(1.0), phase(0), sample(0), samplerate(samplerate) {
  std::cout << "Sine - constructor\n";
};

//Destructor
Sine::~Sine() {
  std::cout << "Sine - destructor\n";
};

//Setter for samplerate
void Sine::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
};

//getter for sample
  // Sample = number speaker position at certain phase
float Sine::getSample() {
  return sample;
};

//Setter for Frequency
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
};

//Getter for Frequency
float Sine::getFrequency()
{
  return frequency;
};

//Tick
void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;

  //Correction for phase
  if(phase > 1.0f) {
  phase -= 1.0f;
  };
  //SINE CALCULATION
  sample = sin(pi * 2 * phase) * amplitude;
};
