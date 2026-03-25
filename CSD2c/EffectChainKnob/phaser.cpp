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
  //for now simply like this:


  apf1.processFrame(input + feedbackSample, apf1output);
  apf2.processFrame(apf1output, apf2output);
  apf3.processFrame(apf2output, apf3output);
  apf4.processFrame(apf3output, apf4output);
  apf5.processFrame(apf4output, apf5output);
  apf6.processFrame(apf5output, apf6output);
  feedbackSample = apf6output * m_feedback;
  output = apf6output * 0.5 + input * 0.5;
}

void Phaser::setFeedback(float feedback) {
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = -feedback;
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

//LOGGING THINGS
void Phaser::logThings() {
  std::cout << "Phaser m_feedback: " << m_feedback << "\n";
  std::cout << "\nPhaser LFOSpeed: " << m_LFOSpeed << "\n";
  std::cout << "Phaser LFODepth: " << m_LFODepth << "\n";
  std::cout << "----Phaser apf's feedback----\n";
  for (int i = 0; i < 6; i++) {
    std::cout << i + 1 << ": ";
    apfArray[i].logFeedback();
  }
}
