#include "effect.h"
#include <iostream>

Effect::Effect(float dryWet) {
  setDryWet(dryWet);
}

Effect::~Effect() {}

void Effect::processFrame(const float& input, float& output) {
  applyEffect(input, output);
  output = input * wetDry + output * dryWet;
  m_sample = output;
}

float Effect::getSample() {return m_sample;}

void Effect::setDryWet(float dryWet) {
  if(dryWet < 0) {dryWet = 0;};
  this->dryWet = dryWet;
  wetDry = 1.0f - dryWet;
}
