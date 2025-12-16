#ifndef _CALLBACK_H_
#define _CALLBACK_H_

//Including thing that connects audio
#include "audiocomponent.h"
//including things that calculate samples
#include "sine.h"
#include "square.h"
#include "saw.h"

//Making Callback class, derived class from Audiocallback class in audiocomponent
class Callback : public AudioCallback {
public:
  //constructor with samplerate
  Callback(float samplerate);

  //Member functions
  void prepare (int sampleRate) override;
  void process (AudioBuffer buffer) override;

//Making oscillators for Synth
private:
  Saw sawOsc;
  Square squareOsc;
};
#endif
