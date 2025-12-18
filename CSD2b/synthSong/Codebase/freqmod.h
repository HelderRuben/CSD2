#ifndef _Freqmod_H_
#define _Freqmod_H_

#include "synth.h"
#include <iostream>

class Freqmod : public Synth {
public:
  //Constructor
  Freqmod();
  //Constructor looking like Synth constructor
  Freqmod(
    float frequency,
    float ratio,
    std::string chosenCarrWaveform,
    std::string chosenModWaveform);
  //Destructor
  ~Freqmod();

  //Freqmod overridden from base class
  float modulate(float carrierSample, float modulatorSample);
};

#endif
