#include "pirkleReverb.h"

PirkleReverb::PirkleReverb(
  int valueSet)
{
  if(valueSet == 0) {
    apf1 = new AllPassFilter{0.35, 384, 512};
    apf2 = new AllPassFilter{0.3, 576, 600};
    napf1 = new NestedAPFOne{
      0.5, 1200, 1250,
      0.25, 2976, 3000};
    napf2 = new NestedAPFTwo{
      0.5, 672, 680,
      0.25, 3648, 3700,
      0.25, 1440, 1500};
    m_line1Gain = 0.5;
    m_line2Gain = 0.3;
    m_line3Gain = 0.5;
  }
  if(valueSet == 1) {
    apf1 = new AllPassFilter{0.4, 413, 512};
    apf2 = new AllPassFilter{0.35, 534, 600};
    napf1 = new NestedAPFOne{
      0.3, 1134, 1250,
      0.45, 3197, 3200};
    napf2 = new NestedAPFTwo{
      0.6, 649, 660,
      0.45, 3856, 3900,
      0.15, 1340, 1500};
    m_line1Gain = 0.6;
    m_line2Gain = 0.4;
    m_line3Gain = 0.55;
  }
  if(valueSet == 2) {
    apf1 = new AllPassFilter{0.3, 367, 512};
    apf2 = new AllPassFilter{0.4, 614, 630};
    napf1 = new NestedAPFOne{
      0.6, 1236, 1250,
      0.2, 2743, 3000};
    napf2 = new NestedAPFTwo{
      0.45, 699, 710,
      0.15, 3578, 3700,
      0.45, 1540, 1550};
    m_line1Gain = 0.9;
    m_line2Gain = 0.5;
    m_line3Gain = 0.4;
  }
}

PirkleReverb::~PirkleReverb() {
  delete apf1;
  apf1 = nullptr;
  delete apf2;
  apf2 = nullptr;
  delete napf1;
  napf1 = nullptr;
  delete napf2;
  napf2 = nullptr;
}

void PirkleReverb::applyEffect(const float &input, float &output) {
  float tempSample = 0.0f;
  apf1->processFrame(input + m_feedbackSample, tempSample);
  apf2->processFrame(tempSample, tempSample);
  m_line1Sample = tempSample * m_line1Gain;
  napf1->processFrame(tempSample, tempSample);
  m_line2Sample = tempSample * m_line2Gain;
  napf2->processFrame(tempSample, tempSample);
  m_line3Sample = tempSample * m_line3Gain;
  m_feedbackSample = tempSample * 0.45;
  output = m_line1Sample + m_line2Sample + m_line3Sample;
}

// void PirkleReverb::setLineGain(float line1Gain, float line2Gain, float line3gain) {

// }
