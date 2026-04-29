#pragma once

class SimpleAPF {
public:
  SimpleAPF(float feedback);

  float process(float input, float LFOModifier);
  void setFeedback(float feedback);

private:
  float m_feedback;
  float m_x1;
  float m_y1;
  float m_output;
};
