//Including header
#include "square.h"

//Constructor and initialiser list
Square::Square(float frequency, float samplerate) : frequency(frequency), amplitude(1.0), phase(0), sample(0), samplerate(samplerate) {
  std::cout << "Square - constructor\n";
};

//Destructor
Square::~Square() {
  std::cout << "Square - destructor\n";
};

//Setter for samplerate
void Square::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
};

//getter for sample
  // Sample = number speaker position at certain phase
float Square::getSample() {
  return sample;
};

//Setter for Frequency
void Square::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
};

//Getter for Frequency
float Square::getFrequency()
{
  return frequency;
};

//Tick
void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;

  //Correction for phase
  if(phase > 1.0f) {
  phase -= 1.0f;
  };
  //SQUARE CALCULATION
  if (phase < 0.5) {
    sample = -1.0;
  } else sample = 1.0;
};
