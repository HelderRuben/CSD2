#include "phaser.h"

Phaser::Phaser(
  float feedback,
  float gainIncrement,
  float LFOSpeed,
  float LFODepth)
  : m_feedback(0),
    m_LFODepth(0), m_LFOSpeed(0)
{
  setFeedback(feedback);
  setLFOSpeed(LFOSpeed);
  setLFODepth(LFODepth);
  for (int i = 0; i < 6; i++) {
    apfArray[i].setSize(8);
    apfArray[i].allocateBuffer();
    apfArray[i].setDelayLength(1);
    apfArray[i].setFeedback(gainIncrement * (i + 1));
  }
}

Phaser::~Phaser()
{
  for (int i = 0; i < 6; i++) {
    apfArray[i].releaseBuffer();
  }
};

void Phaser::applyEffect(const float &input, float &output) {
  LFOModifier = LFO.getSample() * 0.05;
  apf1.applyEffect(input + feedbackSample, apf1output, LFOModifier);
  apf2.applyEffect(apf1output, apf2output, LFOModifier);
  apf3.applyEffect(apf2output, apf3output, LFOModifier);
  apf4.applyEffect(apf3output, apf4output, LFOModifier);
  apf5.applyEffect(apf4output, apf5output, LFOModifier);
  apf6.applyEffect(apf5output, apf6output, LFOModifier);
  feedbackSample = apf3output * m_feedback;
  LFO.tick();
  output = apf6output * 0.5 + input * 0.5;
}

void Phaser::setFeedback(float feedback) {
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = feedback;
}

void Phaser::setLFOSpeed(float LFOSpeed) {
  if(LFOSpeed < 0.25 || LFOSpeed > 10) {
    throw "Delay::setLFOSpeed - LFOSpeed exceeds range [0.25, 10]";
  }
  m_LFOSpeed = LFOSpeed;
}

//TODO: Set LFO Depth
void Phaser::setLFODepth(float LFODepth) {
  if(LFODepth < 0.25 || LFODepth > 10) {
    throw "Delay::setLFODepth - LFODepth exceeds range [NO IDEA]"; ///THIS
  }
  m_LFODepth = LFODepth;
}
