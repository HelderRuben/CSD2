#pragma once

#include <iostream>

class CircularBuffer {
public:
  //constructor
  CircularBuffer();
  CircularBuffer(uint size, uint delayLength);
  //destructor
  ~CircularBuffer();

  void resetSize(uint size);

  //delaylength set/get
  void setDelayLength(uint delayLength);
  uint getDelayLength();

  //functions for read/write values
  inline float getReadValue() {return buffer[RHPosition];};
  inline void setWriteValue(float inputSample) {buffer[WHPosition] = inputSample;};

  //take step in time
  inline void tick() {
    incrRead();
    incrWrite();
  }


private:
  inline void incrRead() {
    RHPosition++;
    wrapHead(RHPosition);
  };

  inline void incrWrite() {
    WHPosition++;
    wrapHead(WHPosition);
  };

  //wrapping the head if nessecary
  inline void wrapHead(uint& head) {
    if (head >= bufferSize) head -= bufferSize;
  };

  //methods with buffer size things
  void allocateBuffer();
  void releaseBuffer();
  //not very sure why, but the buffer is a pointer now
  float* buffer;
  //private members
  uint bufferSize;
  uint RHPosition;
  uint WHPosition;
  uint delayLength;
};
