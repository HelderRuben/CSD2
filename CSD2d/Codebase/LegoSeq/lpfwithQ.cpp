#include "lpfwithQ.h"

LPFwithQ::LPFwithQ(float breakFreq, float Q, int sampleRate) : Q_(Q), sampleRate_(sampleRate) {
  calcBreakFreq(breakFreq);
}
LPFwithQ::~LPFwithQ() {}

void LPFwithQ::applyEffect(const float &input, float &output) {
  output = a0_*input + a1_*xn1_ + a0_*xn2_ - b1_*yn1_ - b2_*yn2_;

  xn2_ = xn1_;
  yn2_ = yn1_;
  xn1_ = input;
  yn1_ = output;
}

void LPFwithQ::setFreqAndQ(float breakFreq, float Q){
  breakFreq_ = breakFreq;
  Q_ = Q;
  theta_ = M_PI * breakFreq_ / sampleRate_;
  d_ = 1 / Q_;
  beta_ = 0.5 * (1 - (d_ / 2) * sin(theta_)) / (1 + (d_ / 2) * sin(theta_));
  gamma_ = (0.5 + beta_) * cos(theta_);

  a0_ = (0.5 + beta_ - gamma_) / 2;
  a1_ = 0.5 + beta_ - gamma_;
  b1_ = -2 * gamma_;
  b2_ = 2 * beta_;
}

void LPFwithQ::calcBreakFreq(float knobParam) {
    breakFreq_ = 100 * pow((35000/100), knobParam);
    setFreqAndQ(breakFreq_, Q_);
}
