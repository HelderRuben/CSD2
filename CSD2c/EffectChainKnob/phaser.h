#pragma once
#include <effect.h>
#include <iostream>
#include "allPassFilter.h"

class Phaser : public Effect
{
public:
  Phaser(
    float feedback = 0.0,
    float gainIncrement = 0.06,
    float LFOSpeed = 0.5,
    float LFODepth = 0.8
  );
  ~Phaser();

  void applyEffect(const float &input, float &output) override;
  void setFeedback(float feedback);
  void setLFOSpeed(float LFOSpeed);
  void setLFODepth(float LFODepth);
  void logThings();

private:
  //AllPassFilters
  AllPassFilter apf1;
  AllPassFilter apf2;
  AllPassFilter apf3;
  AllPassFilter apf4;
  AllPassFilter apf5;
  AllPassFilter apf6;
  AllPassFilter apfArray[6] = {apf1, apf2, apf3, apf4, apf5, apf6};
  //Members
  float m_feedback;
  float m_LFOSpeed;
  float m_LFODepth;

  //Samples
  float apf1output = 0.0f;
  float apf2output = 0.0f;
  float apf3output = 0.0f;
  float apf4output = 0.0f;
  float apf5output = 0.0f;
  float apf6output = 0.0f;
  float feedbackSample = 0.0f;

};
