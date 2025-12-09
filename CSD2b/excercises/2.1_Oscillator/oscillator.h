#pragma once
#include <iostream>


class Osc {
public:
  //constructor
  Osc();
  //other constructors
  Osc(float frequency);
  Osc(float frequency, float amplitude);
  //destructor
  ~Osc();

//methods
  //Getter: Returns frequency in oscillator
  float getFreq();
  //Setter: Changes frequency
  void setFreq(float newFreq);

private:
  //fields
  float freq;
  float amp;
};
