//This is synth class.
  //Its devided into 2 different synths:
    //FM
    //RM
  //And it is connected to the melody.
  ////
  //It has oscillators and their ratios,
    // and possibly calculations of these which will be done in the derived classes.

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
  Synth(float frequency, float ratio, std::string chosenCarrWaveform, std::string chosenModWaveform);
  //destructor
  ~Synth();

  //Member functions which ... can access
    //ticks oscs
  void tick();
    //sets osc samplerate
  void setSamplerate(float samplerate);
    //gets osc sample
  float getSample();

  //In the future: Function to set waveform with user input

  //2 Pointers pointing to oscillators (but now empty)
  Oscillator* CarrAndMod[2];

  //Fields for userinput: STANDARD VALUES
  std::string chosenSynth = "FM";
  std::string chosenCarrWaveform = "saw";
  std::string chosenModWaveform = "saw";
  float chosenRatio = 1.4f;
  float chosenModAmount = 1;
};

#endif
