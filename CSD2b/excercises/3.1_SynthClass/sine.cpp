//Including things
#include "sine.h"
#include "math.h"

//Default Constructor Test
Sine::Sine() : Sine(440, 44100) {
  std::cout << "Sine Default Constructor\n";
};
//Constructor and initialiser list
Sine::Sine(float frequency, float samplerate) : Oscillator(frequency, samplerate) {
  std::cout << "Sine constructed\n";
};

//Destructor
Sine::~Sine() {
  std::cout << "Sine destructed\n";
};

//Calculation but ALSO STILL PHASE UPDATE
void Sine::calculate() {
  //Correction for phase
  if(phase > 1.0f) {
  phase -= 1.0f;
  };
  //SINE CALCULATION
  sample = sin(pi * 2 * phase) * amplitude;
};
