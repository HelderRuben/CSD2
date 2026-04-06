#include "allPassFilter.h"

AllPassFilter::AllPassFilter(float feedback, uint delayLength,
  uint bufferSize)
  : m_feedback(0), m_delayLength(0), m_bufferSize(bufferSize),
    m_RHPosition(0), m_WHPosition(0)
{
    allocateBuffer();
    setDelayLength(delayLength);
    setFeedback(feedback);
};

AllPassFilter::~AllPassFilter() {
  releaseBuffer();
};


void AllPassFilter::applyEffect(const float &input, float &output)
{
  m_feedbackSample = readCubic(m_RHPosition);
  m_RHPosition++;
  wrapHead(m_RHPosition);

  // const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;
  // m_buffer[m_WHPosition++] = inputPlusFeedback;
  // wrapHead(m_WHPosition);
  // m_feedforwardSample = inputPlusFeedback * -m_feedback;

  m_buffer[m_WHPosition++] = m_feedbackSample * m_feedback + input;
  wrapHead(m_WHPosition);
  m_feedforwardSample = input * -m_feedback;

  output = (m_feedbackSample + m_feedforwardSample) * m_makeUpGain;
}

void AllPassFilter::applyEffect(const float &input, float &output, float LFOModifier)
{
  //CUBIC INTERPOLATION
  // m_feedbackSample = readCubic(m_RHPosition);
  // m_RHPosition++;
  // wrapHead(m_RHPosition);
  //WITHOUT CUBIC INTERPOLATION
  m_feedbackSample = m_buffer[m_RHPosition++];
  wrapHead(m_RHPosition);

  // const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;
  // m_buffer[m_WHPosition++] = inputPlusFeedback;
  // wrapHead(m_WHPosition);
  // m_feedforwardSample = inputPlusFeedback * -m_feedback;

  m_buffer[m_WHPosition++] = m_feedbackSample * (m_feedback + LFOModifier) + input;
  wrapHead(m_WHPosition);
  m_feedforwardSample = input * -(m_feedback + LFOModifier);

  output = (m_feedbackSample + m_feedforwardSample) * m_makeUpGain;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void AllPassFilter::resetSize(uint bufferSize) {
  releaseBuffer();
  allocateBuffer();
};

void AllPassFilter::setSize(uint bufferSize) {
  m_bufferSize = bufferSize;
};

void AllPassFilter::setDelayLength(int delayLength) {
  m_delayLength = delayLength;
  m_RHPosition = (int)m_WHPosition - m_delayLength + m_bufferSize;
  wrapHead(m_RHPosition);
};

uint AllPassFilter::getDelayLength() {
  return m_delayLength;
};


void AllPassFilter::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = -feedback;
}

// void AllPassFilter::setBreakFrequency(float fB, float fS) {
//   float fBfS = fB / fS;
//   float temp = tan(M_PI * fBfS);
//   float coefficient = (temp -1)/(temp + 1);
//   m_feedback = -coefficient;
// }

float AllPassFilter::readCubic(int RHPosition){
  int y0, y1, y2, y3;
  float mu;

  y0 = floor(RHPosition - 1);
  y1 = floor(RHPosition);
  y2 = floor(RHPosition);
  y3 = floor(RHPosition + 1);
  mu = RHPosition - y1;

  return cubicInterpolation(getReadValue(y0), getReadValue(y1), getReadValue(y2), getReadValue(y3), mu);
}

float AllPassFilter::cubicInterpolation(float y0, float y1, float y2, float y3, float mu){
  double a0, a1, a2, a3, mu2;

  mu2 = mu * mu;
	a0 = -0.5 * y0 + 1.5 * y1 - 1.5 * y2 + 0.5 * y3;
	a1 = y0 - 2.5 * y1 + 2 * y2 - 0.5 * y3;
	a2 = -0.5 * y0 + 0.5 * y2;
	a3 = y1;

  return(a0 * mu * mu2 + a1 * mu2 + a2 * mu + a3);
}

void AllPassFilter::allocateBuffer() {
  m_buffer = (float*)malloc(m_bufferSize * sizeof(float));
  memset(m_buffer, 0, m_bufferSize * sizeof(float));
};

void AllPassFilter::releaseBuffer() {
  free(m_buffer);
};
