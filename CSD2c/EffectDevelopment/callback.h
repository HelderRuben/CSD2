#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>
#include "osc_server.h"
#include <sine.h>
#include <waveShaper.h>

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float sampleRate = 44100.f;
  float targetParameter { 440.f };

  Sine sine;
  WaveShaper waveShaper;

  LocalOSC oscServer { targetParameter };
  std::string serverport {"7777"};

};

#endif //CALLBACK_H
