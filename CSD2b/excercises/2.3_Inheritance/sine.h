//If not defined, define sine header
#ifndef _SINE_H_
#define _SINE_H_
//Including basic utility libraries
#include <iostream>
#include <cmath>
#include "oscillator.h"

class Sine : Oscillator {
public:
  //Constructor
  Sine(float frequency, float samplerate = 44100);
  //Destructor
  ~Sine();

  //Sine-Calculation, overridden from base class
  void calculate();
private:
  //Used for Sine-calculation
  const float pi = acos (-1);
};

#endif
