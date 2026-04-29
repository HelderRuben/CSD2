#pragma once
#include <effect.h>
#include <cmath>

//Linkwitz-Riley LPF with naming according to Pirkle
class LinkRileyLPF : public Effect
{
public:
  LinkRileyLPF(float breakFreq = 440.0f, int sampleRate = 44100);
  ~LinkRileyLPF();

  void applyEffect(const float &input, float &output) override;

  void setBreakFreq(float breakFreq);
  float getBreakFreq() {return breakFreq_;};
  void calcBreakFreq(float knobParam);

private:
    float breakFreq_, sampleRate_;
    float theta_, kappa_, omega_, delta_;
    float kappa2_, omega2_;
    float a0_, a1_, b1_, b2_;
    float xn1_ = 0;
    float xn2_ = 0;
    float yn1_ = 0;
    float yn2_ = 0;
};
