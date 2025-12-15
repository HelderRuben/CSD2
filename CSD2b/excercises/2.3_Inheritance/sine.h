//If not defined, define sine header
#ifndef _SINE_H_
#define _SINE_H_
//Including basic utility libraries
#include <iostream>
#include <cmath>

class Sine
{
public:
  //Constructor
  Sine(float frequency, float samplerate = 44100);
  //Destructor
  ~Sine();
  void setSamplerate(float samplerate);
  //return current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;
};

#endif
