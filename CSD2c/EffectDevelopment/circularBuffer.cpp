#include "circularBuffer.h"

CircularBuffer::CircularBuffer(int size, int delayLength) :
  RHPosition(0),
  WHPosition(size)
{
    //yay constructed
};

CircularBuffer::~CircularBuffer()
{
  //release allocated memory or smth
}:

float CircularBuffer::getReadValue() {
  return buffer[RHPosition];
};

void CircularBuffer::setWriteValue(float inputSample) {
  buffer[WHPosition] = inputSample;
};

void CircularBuffer::tick() {
  incrementHead(RHPosition);
  incrementHead(WHPosition);
};

void CircularBuffer::incrementHead(int& head) {
  head++;
  if(head >= SIZE_ARRAY) {
    head -= SIZE_ARRAY;
  };
};
