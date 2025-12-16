#include "saw.h"

Saw::Saw() : Saw(440, 44100) {
  std::cout << "Saw Default Constructor\n";
};

Saw::Saw(float frequency, float samplerate) : Oscillator(frequency, samplerate) {
  std::cout << "Saw constructed\n";
};

Saw::~Saw() {
  std::cout << "Saw destructed\n";
};

void Saw::calculate() {
  //Saw this in example earlier and remembered (i think correctly)
  sample = phase * 2 - 1.0f;
};
