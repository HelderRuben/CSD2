#include "circularBuffer.h"

//standard constructor
CircularBuffer::CircularBuffer() : CircularBuffer(0, 256) {};

CircularBuffer::CircularBuffer(uint size, uint delayLength) :
  bufferSize(size),
  RHPosition(0),
  WHPosition(0)
{
    //making space for the buffer and then making it
    allocateBuffer();
    setDelayLength(delayLength);
};

CircularBuffer::~CircularBuffer() {
  releaseBuffer();
};

void CircularBuffer::resetSize(uint size) {
  releaseBuffer();
  allocateBuffer();
};

void CircularBuffer::setDelayLength(uint delayLength) {
  delayLength = delayLength;
};

uint CircularBuffer::getDelayLength() {
  return delayLength;
};

void CircularBuffer::allocateBuffer() {
  //do smth with memory
  buffer = (float*)malloc(bufferSize * sizeof(float));
  memset(buffer, 0, bufferSize * sizeof(float));
};

void CircularBuffer::releaseBuffer() {
  free(buffer);
};
