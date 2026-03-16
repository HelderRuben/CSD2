#include "allPassFilter.h"

AllPassFilter::AllPassFilter(float feedback, uint delayLength,
  uint bufferSize, float dryWet) : Effect(dryWet),
  m_feedback(0), m_delayLength(0),
  m_bufferSize(bufferSize), m_RHPosition(0), m_WHPosition(0)
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
  //Delayed Sample
  m_feedbackSample = m_buffer[m_RHPosition++];
  wrapHead(m_RHPosition);
  const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;
  m_buffer[m_WHPosition++] = inputPlusFeedback;
  wrapHead(m_WHPosition);

  //Feedforward Sample
  m_feedforwardSample = inputPlusFeedback * -m_feedback;

  output = (m_feedbackSample + m_feedforwardSample) * makeUpGain;
}

void AllPassFilter::resetSize(uint bufferSize) {
  releaseBuffer();
  allocateBuffer();
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

void AllPassFilter::logFeedback() {
  std::cout << "Feedback member: "<< m_feedback << "\n";
}


void AllPassFilter::allocateBuffer() {
  m_buffer = (float*)malloc(m_bufferSize * sizeof(float));
  memset(m_buffer, 0, m_bufferSize * sizeof(float));
};

void AllPassFilter::releaseBuffer() {
  free(m_buffer);
};

//Debug Methods
void AllPassFilter::logRWPos()
{
  std::cout << "RHPos: " << m_RHPosition << ", WHPos: " << m_WHPosition;
}

void AllPassFilter::logDistanceRW()
{
  std::cout << "\n______________________ AllPassFilter:CB ______________________________\n";
  std::cout << "Distance between read and write head: " << m_delayLength << "\n";
	std::cout << "_________________________________________________________________\n";
}


void AllPassFilter::logSize()
{
  std::cout << "\n______________________ AllPassFilter:CB ______________________________\n";
  std::cout << "Buffer size: " << m_bufferSize << "\n";
	std::cout << "_________________________________________________________________\n";
}

void AllPassFilter::logAllSettings()
{
  std::cout << "\n______________________ AllPassFilter:CB ______________________________\n";
  std::cout << "Read head position: " << m_RHPosition << "\n";
  std::cout << "Write head position: " << m_WHPosition << "\n";
  std::cout << "Distance between read and write head: " << m_delayLength << "\n";
  std::cout << "Buffer size: " << m_bufferSize << "\n";
	std::cout << "_________________________________________________________________\n";
}


void AllPassFilter::logAllValues()
{
  std::cout << "\n______________________ AllPassFilter:CB ______________________________\n";
  std::cout << "AllPassFilter - buffer contains: \n";
  for (int i = 0; i < m_bufferSize - 1; i++)
	{
    std::cout << m_buffer[i] << ", ";
	}
  std::cout << m_buffer[m_bufferSize - 1] << "\n";
	std::cout << "_________________________________________________________________\n";
}
