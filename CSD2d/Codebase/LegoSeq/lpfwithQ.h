#pragma once
#include <effect.h>
#include <cmath>

//Second Order LPF with naming according to Pirkle
class LPFwithQ : public Effect
{
public:
  LPFwithQ(float breakFreq = 440.0f, float Q = 2.5, int sampleRate = 44100);
  ~LPFwithQ();

  void applyEffect(const float &input, float &output) override;

  void setFreqAndQ(float breakFreq, float Q);
  float getBreakFreq() {return breakFreq_;};
  void calcBreakFreq(float knobParam);

private:
    float breakFreq_, sampleRate_;
    float theta_, beta_, gamma_, d_, Q_;
    float a0_, a1_, b1_, b2_;
    float xn1_ = 0;
    float xn2_ = 0;
    float yn1_ = 0;
    float yn2_ = 0;
};
