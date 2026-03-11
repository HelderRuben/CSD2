#pragma once
#include "effect.h"

#define BUFFER_SIZE 512

class WaveShaper : public Effect{
public:
  WaveShaper(float dryWet = 0.5);
  ~WaveShaper();

  // override base class method
  // applies tremolo effect to the input frame
  void applyEffect(const float& input, float& output) override;

private:
  float buffer[BUFFER_SIZE];
};
