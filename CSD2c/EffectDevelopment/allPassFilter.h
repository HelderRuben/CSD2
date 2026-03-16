#pragma once
#include <effect.h>

#include <iostream>

class AllPassFilter : public Effect
{
public:
  AllPassFilter(
    float feedback = 0.9,
    uint delayLength = 20,
    uint bufferSize = 512,
    float makeUpGain = 0.9
  );
  ~AllPassFilter();

  void applyEffect(const float &input, float &output) override;

  void resetSize(uint size);
  void setDelayLength(int delayLength);
  uint getDelayLength();
  void setFeedback(float feedback);
  void logFeedback();

  inline float getReadValue() {return m_buffer[m_RHPosition];};
  inline void setWriteValue(float inputSample) {m_buffer[m_WHPosition] = inputSample;};

  void logRWPos();
  void logDistanceRW();
  void logSize();
  void logAllSettings();
  void logAllValues();

private:

  inline void wrapHead(uint& head) {
    if (head >= m_bufferSize) head -= m_bufferSize;
    else if (head < 0) head += m_bufferSize;
  };

  void allocateBuffer();
  void releaseBuffer();

  float m_feedback = 0.0f;
  float m_feedbackSample = 0;
  float m_feedforwardSample = 0;
  float m_makeUpGain = 0.9;

  float* m_buffer;
  uint m_bufferSize;
  uint m_RHPosition;
  uint m_WHPosition;
  uint m_delayLength;
};
