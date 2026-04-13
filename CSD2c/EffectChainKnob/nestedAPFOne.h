#pragma once
#include <effect.h>
#include "allPassFilter.h"
#include <iostream>

class NestedAPFOne : public Effect
{
public:
  NestedAPFOne(
    float feedback = 0.7,
    uint delayLength = 20,
    uint bufferSize = 512,
    float nestedFeedback = 0.7,
    uint nestedDelayLength = 20,
    uint nestedBufferSize = 512
  );
  ~NestedAPFOne();

  void applyEffect(const float &input, float &output) override;

  void resetSize(uint size);
  void setDelayLength(int delayLength);
  uint getDelayLength();
  void setFeedback(float feedback);
  float cubicInterpolation(float y0, float y1, float y2, float y3, float mu);
  float readCubic(int RHPosition);

  inline float getReadValue(int RHPosition) {return m_buffer[RHPosition];};
  inline void setWriteValue(float inputSample) {m_buffer[m_WHPosition] = inputSample;};

  void allocateBuffer();
  void releaseBuffer();
  
private:
  AllPassFilter *APFInsideThisOne;

  inline void wrapHead(uint& head) {
    if (head >= m_bufferSize) head -= m_bufferSize;
    else if (head < 0) head += m_bufferSize;
  };

  float m_feedback = 0.0f;
  float m_feedbackSample = 0;
  float m_feedforwardSample = 0;
  const float m_makeUpGain = 0.95;

  float* m_buffer;
  uint m_bufferSize;
  uint m_RHPosition;
  uint m_WHPosition;
  uint m_delayLength;
};
