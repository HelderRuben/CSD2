#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <cmath>
#include "oscillator.h"

class Square : public Oscillator{
public:
  //Default Constructor
  Square();
  //Constructor
  Square(float frequency, float samplerate = 44100);
  //Destructor
  ~Square();

  //Square calculation, overridden from base class
  void calculate();
};

#endif
