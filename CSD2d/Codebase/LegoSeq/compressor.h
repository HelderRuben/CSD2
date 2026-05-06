#pragma once
#include <effect.h>
#include <cmath>

class Compressor : public Effect
{
public:
  Compressor(
    float att = 15,
    float dec = 200,
    float thresh = 6,
    float ratio = 4);
  ~Compressor();

  void applyEffect(const float &input, float &output) override;

  void setAttDec(float att, float dec);

  float calcAttDec(float attDec);
  float calcRMS(float x, float a);
  float calcGain(float indB);

  float linTodB(float lin);
  float dBToLin(float dB);
  float clamp(float gain);

private:
  // static const float DC_OFFSET = 1.0E-25f;
  int sampleRate_ = 44100;
  float att_a_, dec_a_;

  float inRMS_;

  float yn0_ = 0;
  float abs_x_, yn1_, a_;

  float indB_, outdB_, outG_;

  float thresh_, ratio_, makeUp_;
};
