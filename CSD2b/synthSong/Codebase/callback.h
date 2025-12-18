#ifndef _CALLBACK_H_
#define _CALLBACK_H_

#include "audiocomponent.h"
#include "synth.h"
#include "ringmod.h"
#include "userinput.h"
#include "melody.h"

//Making Callback class, derived class from Audiocallback class in audiocomponent
class Callback : public AudioCallback {
public:
  //Constructor with samplerate
  Callback(float samplerate);

  //Destructor for deleting synthPtr
  ~Callback();

  //Member functions
  void prepare (int sampleRate) override;
  void process (AudioBuffer buffer) override;

    //options lists
  std::string synthOptions[2] = {"FM", "RM"};
  std::string waveforms[3] = {"sine", "saw", "square"};

private:
  //Pointer to Synth
  Ringmod* synthPtr = nullptr;

  //Adding melody
  Melody melody;

  //Functions that are linked back to Synth class
    //SETTING WAVEFORMS
  void setOscs(std::string waveform, std::string modWaveform, float ratio);
};
#endif
