//If not defined, define osc header
#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_

#include <iostream>

class Oscillator {
  public:
    //Constructor
    Oscillator(float frequency = 440, float samplerate = 44100);
    //Destructor
    ~Oscillator();

    //Freq setter
    void setFrequency(float frequency);
    //Freq getter
    float getFrequency();
    //Samplerate setter
    void setSamplerate(float samplerate);
    //Sample getter (current sample)
    float getSample();
    //Updating tick (next sample)
    void tick();

  //can be overridden in subclasses
  protected:
    //member function for calculating sample
    virtual void calculate() = 0;
    float amplitude;
    float phase;
    float sample;
  //can't be overridden
  private:
    float frequency;
    float samplerate;
};

#endif
