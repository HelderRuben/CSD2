#include "linkRileyLPF.h"

LinkRileyLPF::LinkRileyLPF(float breakFreq, int sampleRate) : sampleRate_(sampleRate) {
  setBreakFreq(breakFreq);
}
LinkRileyLPF::~LinkRileyLPF() {}

void LinkRileyLPF::applyEffect(const float &input, float &output) {
  output = a0_*input + a1_*xn1_ + a0_*xn2_ - b1_*yn1_ - b2_*yn2_;

  xn2_ = xn1_;
  yn2_ = yn1_;
  xn1_ = input;
  yn1_ = output;
}

void LinkRileyLPF::setBreakFreq(float breakFreq){
  breakFreq_ = breakFreq;
  theta_ = M_PI * breakFreq_ / sampleRate_;
  omega_ = M_PI * breakFreq_;
  kappa_ = omega_ / tan(theta_);
  kappa2_ = kappa_ * kappa_;
  omega2_ = omega_ * omega_;
  delta_ = kappa2_ + omega2_ + 2 * kappa_ * omega_;

  a0_ = omega2_ / delta_;
  a1_ = 2 * a0_;
  b1_ = (-2 * kappa2_ + 2 * omega2_) / delta_;
  b2_ = (-2 * kappa_ * omega_ + kappa2_ + omega2_) / delta_;
}

void LinkRileyLPF::calcBreakFreq(float knobParam) {
    breakFreq_ = 100 * pow((19000/100), knobParam);
    setBreakFreq(breakFreq_);
}
