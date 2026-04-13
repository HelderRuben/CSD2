#pragma once
#include <effect.h>
#include <iostream>
#include "simpleAPF.h"
#include <sine.h>

class Phaser : public Effect
{
public:
  Phaser(
    float feedback = 0.0,
    float LFOSpeed = 0.0,
    float LFODepth = 0.05,
    float LFODirection = 0.0f
  );
  ~Phaser();

  void applyEffect(const float &input, float &output) override;
  void setFeedback(float feedback);
  void setLFOSpeed(float LFOSpeed);
  void setLFODepth(float LFODepth);

private:
  SimpleAPF *apfArray[6];
  Sine *LFO;

  float m_feedback;
  float m_LFOSpeed;
  float m_LFODepth = 0.05;

  float filterSample;
  float feedbackSample = 0.0f;
  float LFOModifier = 0.0f;
  int m_LFODirection;
};
