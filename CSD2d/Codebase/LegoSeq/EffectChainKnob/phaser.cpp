#include "phaser.h"

Phaser::Phaser(
  float feedback,
  float LFOSpeed,
  float LFODepth,
  float LFODirection)
  : m_feedback(0), m_LFODepth(0), m_LFODirection(LFODirection)
{
  for (int i = 0; i < 6; i++) {
    apfArray[i] = new SimpleAPF(-0.706730);
  }
  LFO = new Sine(0.5f, 48000);
  setFeedback(feedback);
  setLFOSpeed(LFOSpeed);
  setLFODepth(LFODepth);
}

Phaser::~Phaser() {
  for (int i = 0; i < 6; i++) {
    delete apfArray[i];
    apfArray[i] = nullptr;
  }
  delete LFO;
  LFO = nullptr;
};

void Phaser::applyEffect(const float &input, float &output) {
  LFOModifier = LFO->getSample() * m_LFODirection * m_LFODepth;
  filterSample = input;
  for(int i = 0; i < 6; i++) {
    if(i == 0) {
    filterSample = apfArray[i]->process(filterSample + feedbackSample, LFOModifier);
    } else {
      filterSample = apfArray[i]->process(filterSample, LFOModifier);
    }
  }
  feedbackSample = filterSample * m_feedback;
  LFO->tick();
  output = filterSample * 0.5 + input * 0.5;
}

void Phaser::setFeedback(float feedback) {
  m_feedback = feedback;
}

void Phaser::setLFOSpeed(float LFOSpeed) {
  if(LFOSpeed >= 0.0 && LFOSpeed < 0.6) {
    LFO->setFrequency(LFOSpeed);
  } else {
    LFO->setFrequency(0.0);
  }
}

void Phaser::setLFODepth(float LFODepth) {
  m_LFODepth = LFODepth;
}
