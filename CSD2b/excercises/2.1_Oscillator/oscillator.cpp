#include <iostream>
#include "oscillator.h"

//Default Constructor
Osc::Osc() : Osc(440) {
  std::cout << "Default constructor\n";
};

//Frequency Constructor
Osc::Osc(float frequency) : Osc(frequency, 1) {
  std::cout << "Constructor with Frequency, Frequency = " << freq << "\n";
};

//Amplitude Constructor
Osc::Osc(float frequency, float amplitude) : freq(frequency), amp(amplitude) {
  std::cout << "Constructor with Freq&Amp, Freq = " << frequency << " and Amplitude = " << amplitude << "\n";
};

//Getter
float Osc::getFreq() {
  return freq;
}

//Setter
void Osc::setFreq(float newFreq) {
  this->freq = newFreq;
}

//Destructor
Osc::~Osc() {
  std::cout << "Destructing Osc...\n";
};
