#include "nestedAPFTwo.h"

NestedAPFTwo::NestedAPFTwo(
  float feedback,
  uint delayLength,
  uint bufferSize,
  float nestedFeedback1,
  uint nestedDelayLength1,
  uint nestedBufferSize1,
  float nestedFeedback2,
  uint nestedDelayLength2,
  uint nestedBufferSize2)
  : m_feedback(0), m_delayLength(0), m_bufferSize(bufferSize),
    m_RHPosition(0), m_WHPosition(0)
{
    allocateBuffer();
    setDelayLength(delayLength);
    setFeedback(feedback);

    APFInsideThisOne = new AllPassFilter{nestedFeedback1, nestedDelayLength1, nestedBufferSize1};
    APFInsideThisTwo = new AllPassFilter{nestedFeedback2, nestedDelayLength2, nestedBufferSize2};
};

NestedAPFTwo::~NestedAPFTwo() {
  APFInsideThisOne->releaseBuffer();
  delete APFInsideThisOne;
  APFInsideThisOne = nullptr;
  APFInsideThisTwo->releaseBuffer();
  delete APFInsideThisTwo;
  APFInsideThisTwo = nullptr;
  releaseBuffer();
};

void NestedAPFTwo::applyEffect(const float &input, float &output)
{
  m_feedbackSample = m_buffer[m_RHPosition++];
  wrapHead(m_RHPosition);

  const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;
  float NestedAPF1Output = 0.0f;
  float NestedAPF2Output = 0.0f;
  APFInsideThisOne->applyEffect(inputPlusFeedback, NestedAPF1Output);
  APFInsideThisTwo->applyEffect(NestedAPF1Output, NestedAPF2Output);
  m_buffer[m_WHPosition++] = NestedAPF2Output;
  wrapHead(m_WHPosition);

  m_feedforwardSample = inputPlusFeedback * -m_feedback;
  output = (m_feedbackSample + m_feedforwardSample) * m_makeUpGain;
}

void NestedAPFTwo::resetSize(uint bufferSize) {
  releaseBuffer();
  allocateBuffer();
};

void NestedAPFTwo::setDelayLength(int delayLength) {
  m_delayLength = delayLength;
  m_RHPosition = (int)m_WHPosition - m_delayLength + m_bufferSize;
  wrapHead(m_RHPosition);
};

uint NestedAPFTwo::getDelayLength() {
  return m_delayLength;
};

void NestedAPFTwo::setFeedback(float feedback)
{
  m_feedback = -feedback;
}

float NestedAPFTwo::readCubic(int RHPosition){
  int y0, y1, y2, y3;
  float mu;

  y0 = floor(RHPosition - 1);
  y1 = floor(RHPosition);
  y2 = floor(RHPosition);
  y3 = floor(RHPosition + 1);
  mu = RHPosition - y1;

  return cubicInterpolation(getReadValue(y0), getReadValue(y1), getReadValue(y2), getReadValue(y3), mu);
}

float NestedAPFTwo::cubicInterpolation(float y0, float y1, float y2, float y3, float mu){
  double a0, a1, a2, a3, mu2;

  mu2 = mu * mu;
	a0 = -0.5 * y0 + 1.5 * y1 - 1.5 * y2 + 0.5 * y3;
	a1 = y0 - 2.5 * y1 + 2 * y2 - 0.5 * y3;
	a2 = -0.5 * y0 + 0.5 * y2;
	a3 = y1;

  return(a0 * mu * mu2 + a1 * mu2 + a2 * mu + a3);
}

void NestedAPFTwo::allocateBuffer() {
  m_buffer = (float*)malloc(m_bufferSize * sizeof(float));
  memset(m_buffer, 0, m_bufferSize * sizeof(float));
};

void NestedAPFTwo::releaseBuffer() {
  free(m_buffer);
};
