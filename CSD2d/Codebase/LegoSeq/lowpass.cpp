#include "lowpass.h"

Lowpass::Lowpass(float breakFreq, int sampleRate) : sampleRate_(sampleRate) {
  setBreakFreq(breakFreq);
}
Lowpass::~Lowpass() {}

void Lowpass::applyEffect(const float &input, float &output) {
  output = a_ * input + a_ * xn1_ - b_ * yn1_;

  xn1_ = input;
  yn1_ = output;
}

void Lowpass::setBreakFreq(float breakFreq){
  breakFreq_ = breakFreq;

  theta_ = 2 * M_PI * (breakFreq_ / sampleRate_);
  gamma_ = cos(theta_) / (1 + sin(theta_));

  a_ = (1 - gamma_) / 2;
  b_ = -gamma_;
}
