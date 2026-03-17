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

    APFInsideThisOne.setSize(nestedBufferSize1);
    APFInsideThisOne.allocateBuffer();
    APFInsideThisOne.setDelayLength(nestedDelayLength1);
    APFInsideThisOne.setFeedback(nestedFeedback1);

    APFInsideThisTwo.setSize(nestedBufferSize2);
    APFInsideThisTwo.allocateBuffer();
    APFInsideThisTwo.setDelayLength(nestedDelayLength2);
    APFInsideThisTwo.setFeedback(nestedFeedback2);
};

NestedAPFTwo::~NestedAPFTwo() {
  APFInsideThisOne.releaseBuffer();
  APFInsideThisTwo.releaseBuffer();
  releaseBuffer();
};


void NestedAPFTwo::applyEffect(const float &input, float &output)
{
  m_feedbackSample = m_buffer[m_RHPosition++];
  wrapHead(m_RHPosition);

  const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;
  float NestedAPF1Output = 0.0f;
  float NestedAPF2Output = 0.0f;
  APFInsideThisOne.applyEffect(inputPlusFeedback, NestedAPF1Output);
  APFInsideThisTwo.applyEffect(NestedAPF1Output, NestedAPF2Output);
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
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = -feedback;
}

void NestedAPFTwo::allocateBuffer() {
  m_buffer = (float*)malloc(m_bufferSize * sizeof(float));
  memset(m_buffer, 0, m_bufferSize * sizeof(float));
};

void NestedAPFTwo::releaseBuffer() {
  free(m_buffer);
};

//-----------------DEBUG METHODS-----------------

void NestedAPFTwo::logReadValues() {
  std::cout << "RH: "<< getReadValue() << "||  Nest1RH: " << APFInsideThisOne.getReadValue() << "|| Nest2RH: " << APFInsideThisTwo.getReadValue() << "||";
}

void NestedAPFTwo::logFeedback() {
  std::cout << "Feedback member: "<< -m_feedback << "\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logFeedback();
  APFInsideThisTwo.logFeedback();
}

void NestedAPFTwo::logRWPos()
{
  std::cout << "RHPos: " << m_RHPosition << ", WHPos: " << m_WHPosition;
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logRWPos();
  APFInsideThisTwo.logRWPos();
}

void NestedAPFTwo::logDistanceRW()
{
  std::cout << "\n______________________ NestedAPFTwo______________________________\n";
  std::cout << "Distance between read and write head: " << m_delayLength << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logDistanceRW();
  APFInsideThisTwo.logDistanceRW();
}

void NestedAPFTwo::logSize()
{
  std::cout << "\n______________________ NestedAPFTwo______________________________\n";
  std::cout << "Buffer size: " << m_bufferSize << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logSize();
  APFInsideThisTwo.logSize();
}

void NestedAPFTwo::logAllSettings()
{
  std::cout << "\n______________________ NestedAPFTwo______________________________\n";
  std::cout << "Read head position: " << m_RHPosition << "\n";
  std::cout << "Write head position: " << m_WHPosition << "\n";
  std::cout << "Distance between read and write head: " << m_delayLength << "\n";
  std::cout << "Buffer size: " << m_bufferSize << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logAllSettings();
  APFInsideThisTwo.logAllSettings();
}

void NestedAPFTwo::logAllValues()
{
  std::cout << "\n______________________ NestedAPFTwo______________________________\n";
  std::cout << "NestedAPFTwo - buffer contains: \n";
  for (int i = 0; i < m_bufferSize - 1; i++)
	{
    std::cout << m_buffer[i] << ", ";
	}
  std::cout << m_buffer[m_bufferSize - 1] << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logAllValues();
  APFInsideThisTwo.logAllValues();
}
