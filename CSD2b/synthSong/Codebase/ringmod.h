#ifndef _RINGMOD_H_
#define _RINGMOD_H_

#include "synth.h"

class Ringmod : public Synth {
public:
  //Constructor
  Ringmod();
  //Constructor looking like Synth Constructor
  Ringmod(float frequency, float ratio, std::string chosenCarrWaveform, std::string chosenModWaveform);
  //Destructor
  ~Ringmod();

  //RM
  float modulate(float carrierSample, float modulatorSample);

};

#endif
