#ifndef _CALLBACK_H_
#define _CALLBACK_H_

//Including thing that connects audio
#include "audiocomponent.h"
//including things that calculate samples
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "synth.h"
#include "userinput.h"

//Making Callback class, derived class from Audiocallback class in audiocomponent
class Callback : public AudioCallback {
public:
  //constructor with samplerate
  Callback(float samplerate);

  //Neede destructor for deleting synthPtr
  ~Callback();

  //Member functions
  void prepare (int sampleRate) override;
  void process (AudioBuffer buffer) override;

    //options lists
  std::string synthOptions[2] = {"FM", "RM"};
  std::string waveforms[3] = {"sine", "saw", "square"};
private:
  //Pointer to Synth
  Synth* synthPtr = new Synth();
};
#endif
