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
  setLFODepth(LFODepth); //?????

  for (int i = 0; i < 6; i++) {
    apfArray[i] = new SimpleAPF((i+1) * gainIncrement);
  }
  LFO = new Sine(0.5f, 48000);
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
  LFOModifier = LFO->getSample() * 0.05;
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
  if(LFOSpeed < 0.25 || LFOSpeed > 10) {
    throw "Delay::setLFOSpeed - LFOSpeed exceeds range [0.25, 10]";
  }
  m_LFOSpeed = LFOSpeed;
}




//TODO: Set LFO Depth
//TODO: Set LFO Depth
//TODO: Set LFO Depth
//TODO: Set LFO Depth
//TODO: Set LFO Depth

//TODO: Set LFO FREQ
//TODO: Set LFO FREQ
//TODO: Set LFO FREQ
//TODO: Set LFO FREQ
//TODO: Set LFO FREQ


void Phaser::setLFODepth(float LFODepth) {
  if(LFODepth < 0.25 || LFODepth > 10) {
    throw "Delay::setLFODepth - LFODepth exceeds range [NO IDEA]"; ///THIS
  }
  m_LFODepth = LFODepth;
}
