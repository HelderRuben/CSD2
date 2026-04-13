#include "phaser.h"

Phaser::Phaser(
  float feedback,
  float gainIncrement,
  float LFOSpeed,
  float LFODepth)
  : m_feedback(0),
    m_LFODepth(0)
{
  for (int i = 0; i < 6; i++) {
    apfArray[i] = new SimpleAPF((i+1) * gainIncrement);
  }
  LFO = new Sine(0.5f, 48000);
  setFeedback(feedback);
  setLFOSpeed(LFOSpeed);
  setLFODepth(LFODepth);
}

Phaser::~Phaser()
{
  for (int i = 0; i < 6; i++) {
    delete apfArray[i];
    apfArray[i] = nullptr;
  }
  delete LFO;
  LFO = nullptr;
};

void Phaser::applyEffect(const float &input, float &output) {
  LFOModifier = LFO->getSample() * m_LFODepth;
  filterSample = input;
  for(int i = 0; i < 6; i++) {
    filterSample = apfArray[i]->process(filterSample, LFOModifier);
  }
  LFO->tick();
  output = filterSample * 0.5 + input * 0.5;
}

void Phaser::setFeedback(float feedback) {
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = feedback;
}

void Phaser::setLFOSpeed(float LFOSpeed) {
  if(LFOSpeed < 0.1 || LFOSpeed > 3.5) {
    LFO->setFrequency(LFOSpeed);
  }
  LFO->setFrequency(0.5);
}

void Phaser::setLFODepth(float LFODepth) {
  // if(LFODepth < 0.25 || LFODepth > 10) {
  //   throw "Delay::setLFODepth - LFODepth exceeds range [NO IDEA]";
  // }
  m_LFODepth = LFODepth;
}
