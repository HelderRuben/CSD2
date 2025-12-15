//Including header
#include "square.h"

//Default Constructor
Square::Square() : Square(440, 44100) {
  std::cout << "Square Default Constructor\n";
}
//Constructor and initialiser list
Square::Square(float frequency, float samplerate) : Oscillator(frequency, samplerate) {
  std::cout << "Square - Constructor\n";
};

//Destructor
Square::~Square() {
  std::cout << "Square - Destructor\n";
};

//Tick
void Square::calculate() {
  //SQUARE CALCULATION
  if (phase < 0.5) {
    sample = -1.0;
  } else sample = 1.0;
};
