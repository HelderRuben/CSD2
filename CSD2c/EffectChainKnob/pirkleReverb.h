#pragma once
#include <effect.h>
#include "allPassFilter.h"
#include "nestedAPFOne.h"
#include "nestedAPFTwo.h"

class PirkleReverb : public Effect
{
public:
  PirkleReverb(
    int valueSet
  );
  ~PirkleReverb();

void applyEffect(const float &input, float &output) override;

private:
  AllPassFilter *apf1;
  AllPassFilter *apf2;
  NestedAPFOne *napf1;
  NestedAPFTwo *napf2;

  float m_line1Sample = 0.0f;
  float m_line2Sample = 0.0f;
  float m_line3Sample = 0.0f;
  float m_line1Gain = 0.0f;
  float m_line2Gain = 0.0f;
  float m_line3Gain = 0.0f;
  float m_feedbackSample = 0.0f;
};
