#include <iostream>
#include "oscillator.h"

int main() {
  //Oscillator with freq = 220
  Osc newOsc(220);

  //Using the setter and the getter 
  std::cout << "Get freq from main: " << newOsc.getFreq() << "\n";
  newOsc.setFreq(450);
  std::cout << "Get freq from main after setFreq: " << newOsc.getFreq() << "\n";

  //Oscillator with freq = 1234.5 and amp = 0.75
  Osc anotherOsc(1234.5, 0.75);
  return 0;
};
