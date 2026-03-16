#pragma once
#include <effect.h>

#include <iostream>

class AllPassFilter : public Effect
{
public:
  AllPassFilter(float feedback = 0.7, uint delayLength = 3, uint bufferSize = 256, float dryWet = 1.0);
  ~AllPassFilter();

  void applyEffect(const float &input, float &output) override;

  void resetSize(uint size);
  void setDelayLength(uint delayLength);
  uint getDelayLength();

  void setFeedback(float feedback);
  void logFeedback();

  inline float getReadValue() {return m_buffer[m_RHPosition];};
  inline void setWriteValue(float inputSample) {m_buffer[m_WHPosition] = inputSample;};
  //
  // inline void tick() {
  //   incrRead();
  //   incrWrite();
  // }

  // debug methods
  void logRWPos();
  void logDistanceRW();
  void logSize();
  void logAllSettings();
  void logAllValues();

private:
  // inline void incrRead() {
  //   RHPosition++;
  //   wrapHead(RHPosition);
  // };
  //
  // inline void incrWrite() {
  //   WHPosition++;
  //   wrapHead(WHPosition);
  // };

  inline void wrapHead(uint& head) {
    if (head >= m_bufferSize) head -= m_bufferSize;
  };

  float m_feedback = 0.0f;

  float m_feedbackSample = 0;
  float m_feedforwardSample = 0;

  //methods with buffer size things
  void allocateBuffer();
  void releaseBuffer();
  //not very sure why, but the buffer is a pointer now
  float* m_buffer;
  //private members
  uint m_bufferSize;
  uint m_RHPosition;
  uint m_WHPosition;
  uint m_delayLength;
};
