//Including things
#include "sine.h"
#include "math.h"

//Default Constructor
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
  //SINE CALCULATION
  sample = sin(pi * 2 * phase) * amplitude;
};
