#include "roomReverb.h"

RoomReverb::RoomReverb() {
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

RoomReverb::~RoomReverb() {
  delete apf1;
  apf1 = nullptr;
  delete apf2;
  apf2 = nullptr;
  delete napf1;
  napf1 = nullptr;
  delete napf2;
  napf2 = nullptr;
}

void RoomReverb::applyEffect(const float &input, float &output) {
  float tempSample = 0.0f;
  apf1->processFrame(input + (m_feedbackSample * m_feedback), tempSample);
  apf2->processFrame(tempSample, tempSample);
  m_line1Sample = tempSample * m_line1Gain;
  napf1->processFrame(tempSample, tempSample);
  m_line2Sample = tempSample * m_line2Gain;
  napf2->processFrame(tempSample, tempSample);
  m_line3Sample = tempSample * m_line3Gain;
  m_feedbackSample = tempSample * 0.45;
  output = m_line1Sample + m_line2Sample + m_line3Sample;
}

void RoomReverb::setFeedback(float feedback) {
  m_feedback = feedback;
}
