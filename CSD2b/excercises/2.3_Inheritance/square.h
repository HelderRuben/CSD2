//If not defined, define square header
#ifndef _SQUARE_H_
#define _SQUARE_H_
//Including basic utility libraries
#include <iostream>
#include <cmath>

class Square
{
public:
  //Constructor
  Square(float frequency, float samplerate = 44100);
  //Destructor
  ~Square();
  void setSamplerate(float samplerate);
  //return current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;
};

#endif
