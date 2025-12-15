//If not defined, define square header
#ifndef _SQUARE_H_
#define _SQUARE_H_
//Including basic utility libraries
#include <iostream>
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

  //Override bass class calculate by calculating squarewave position
  void calculate();
};

#endif
