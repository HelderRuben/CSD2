#pragma once
#include <effect.h>
#include <cmath>

//LPF with naming according to Pirkle
class Lowpass : public Effect
{
public:
  Lowpass(float breakFreq = 440.0f, int sampleRate = 44100);
  ~Lowpass();

  void applyEffect(const float &input, float &output) override;

  void setBreakFreq(float breakFreq);
  float getBreakFreq() {return breakFreq_;};

private:
    float breakFreq_, sampleRate_;
    float theta_, gamma_;
    float a_, b_;
    float xn1_ = 0;
    float yn1_ = 0;
};
