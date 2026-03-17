#include "nestedAPFOne.h"

NestedAPFOne::NestedAPFOne(
  float feedback,
  uint delayLength,
  uint bufferSize,
  float nestedFeedback,
  uint nestedDelayLength,
  uint nestedBufferSize)
  : m_feedback(0), m_delayLength(0), m_bufferSize(bufferSize),
    m_RHPosition(0), m_WHPosition(0)
{
    allocateBuffer();
    setDelayLength(delayLength);
    setFeedback(feedback);

    APFInsideThisOne.setSize(nestedBufferSize);
    APFInsideThisOne.allocateBuffer();
    APFInsideThisOne.setDelayLength(nestedDelayLength);
    APFInsideThisOne.setFeedback(nestedFeedback);
};

NestedAPFOne::~NestedAPFOne() {
  APFInsideThisOne.releaseBuffer();
  releaseBuffer();
};


void NestedAPFOne::applyEffect(const float &input, float &output)
{
  m_feedbackSample = m_buffer[m_RHPosition++];
  wrapHead(m_RHPosition);

  const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;
  float NestedAPFOutput = 0.0f;
  APFInsideThisOne.applyEffect(inputPlusFeedback, NestedAPFOutput);
  m_buffer[m_WHPosition++] = NestedAPFOutput;
  wrapHead(m_WHPosition);

  m_feedforwardSample = inputPlusFeedback * -m_feedback;
  output = (m_feedbackSample + m_feedforwardSample) * m_makeUpGain;
}

void NestedAPFOne::resetSize(uint bufferSize) {
  releaseBuffer();
  allocateBuffer();
};

void NestedAPFOne::setDelayLength(int delayLength) {
  m_delayLength = delayLength;
  m_RHPosition = (int)m_WHPosition - m_delayLength + m_bufferSize;
  wrapHead(m_RHPosition);
};

uint NestedAPFOne::getDelayLength() {
  return m_delayLength;
};


void NestedAPFOne::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = -feedback;
}

void NestedAPFOne::allocateBuffer() {
  m_buffer = (float*)malloc(m_bufferSize * sizeof(float));
  memset(m_buffer, 0, m_bufferSize * sizeof(float));
};

void NestedAPFOne::releaseBuffer() {
  free(m_buffer);
};

//-----------------DEBUG METHODS-----------------

void NestedAPFOne::logReadValues() {
  std::cout << "RH: "<< getReadValue() << "||  NestRH: " << APFInsideThisOne.getReadValue() << "|| ";
}

void NestedAPFOne::logFeedback() {
  std::cout << "Feedback member: "<< -m_feedback << "\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logFeedback();
}

void NestedAPFOne::logRWPos()
{
  std::cout << "RHPos: " << m_RHPosition << ", WHPos: " << m_WHPosition;
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logRWPos();
}

void NestedAPFOne::logDistanceRW()
{
  std::cout << "\n______________________ NestedAPFOne______________________________\n";
  std::cout << "Distance between read and write head: " << m_delayLength << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logDistanceRW();
}

void NestedAPFOne::logSize()
{
  std::cout << "\n______________________ NestedAPFOne______________________________\n";
  std::cout << "Buffer size: " << m_bufferSize << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logSize();
}

void NestedAPFOne::logAllSettings()
{
  std::cout << "\n______________________ NestedAPFOne______________________________\n";
  std::cout << "Read head position: " << m_RHPosition << "\n";
  std::cout << "Write head position: " << m_WHPosition << "\n";
  std::cout << "Distance between read and write head: " << m_delayLength << "\n";
  std::cout << "Buffer size: " << m_bufferSize << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logAllSettings();
}

void NestedAPFOne::logAllValues()
{
  std::cout << "\n______________________ NestedAPFOne______________________________\n";
  std::cout << "NestedAPFOne - buffer contains: \n";
  for (int i = 0; i < m_bufferSize - 1; i++)
	{
    std::cout << m_buffer[i] << ", ";
	}
  std::cout << m_buffer[m_bufferSize - 1] << "\n";
	std::cout << "_________________________________________________________________\n";
  std::cout << "NESTEDAPF: ";
  APFInsideThisOne.logAllValues();
}
