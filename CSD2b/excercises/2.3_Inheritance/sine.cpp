//Including things
#include "sine.h"
#include "math.h"

//Constructor and initialiser list
Sine::Sine(float frequency, float samplerate) : Oscillator(frequency, samplerate) {
  std::cout << "Sine constructed\n";
};

//Destructor
Sine::~Sine() {
  std::cout << "Sine destructed \n";
};

//Calculation but ALSO STILL PHASE UPDATE
void Sine::calculate() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;

  //Correction for phase
  if(phase > 1.0f) {
  phase -= 1.0f;
  };
  //SINE CALCULATION
  sample = sin(pi * 2 * phase) * amplitude;
};
