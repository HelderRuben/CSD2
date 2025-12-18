#ifndef _SYNTH_H_
#define _SYNTH_H_

#include <iostream>
#include "oscillator.h"
#include "saw.h"
#include "sine.h"
#include "square.h"

class Synth {
public:
  //constructor
  Synth();
  //constructor
  Synth(float frequency, float ratio, std::string chosenCarrWaveform, std::string chosenModWaveform);
  //destructor
  ~Synth();

  //ticks oscs
  void tick();
  //sets osc samplerate
  void setSamplerate(float samplerate);
  //sets frequency of note
  void setFrequency(float frequency, float ratio);
  //gets osc sample
  float getSample();
  //gets ratio
  float getRatio();
  //setting the oscillators with waveforms and ratio
  void setOscs(std::string carrWaveform, std::string modWaveform, float ratio);

  //2 Pointers pointing to oscillators (but now empty)
  Oscillator* CarrAndMod[2];
  float ratio;
  protected:
    float virtual modulate(float carrierSample, float modulatorSample) = 0;
    float modAmount;
};

#endif
