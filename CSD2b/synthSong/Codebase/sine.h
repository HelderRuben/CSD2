#ifndef _SINE_H_
#define _SINE_H_
#include <cmath>
#include "oscillator.h"

class Sine : public Oscillator {
public:
  //Default Constructor
  Sine();
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
