#pragma once

#include <iostream>
#define SIZE_ARRAY 512

class CircularBuffer {
public:
  //constructor
  CircularBuffer();
  CircularBuffer(int size, int delayLength);
  //destructor
  ~CircularBuffer();

  //members
  float getReadValue();
  void setWriteValue(float inputSample);

  void setBufferSize(int buffSize);

  //take step in time
  void tick()


private:
  //with pointer towards the correct head to increment
  void incrementHead(int& head);
  //heads positions
  int RHPosition;
  int WHPosition;
  float buffer[SIZE_ARRAY];
};
