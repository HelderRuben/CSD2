#pragma once
#include <effect.h>
#include "pirkleReverb.h"

class ReverbILike : public Effect
{
public:
  ReverbILike();
  ~ReverbILike();

void applyEffect(const float &input, float &output) override;

private:
  PirkleReverb *rev1;
  PirkleReverb *rev2;
  PirkleReverb *rev3;
  float rev1out = 0.0f;
  float rev2out = 0.0f;
  float rev3out = 0.0f;
};
