#include "simpleAPF.h"

SimpleAPF::SimpleAPF(float feedback) {
  setFeedback(feedback);
}

float SimpleAPF::process(float input, float LFOModifier) {
  m_output = (m_feedback + LFOModifier) * input + m_x1 - (m_feedback + LFOModifier) * m_y1;
  m_x1 = input;
  m_y1 = m_output;
  return m_output;
}

void SimpleAPF::setFeedback(float feedback) {
  m_feedback = feedback;
}
