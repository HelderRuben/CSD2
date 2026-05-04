#include "compressor.h"

Compressor::Compressor(
  float att,
  float dec,
  float thresh,
  float ratio)
   : thresh_(thresh), ratio_(ratio) {
  setAttDec(att, dec);
}
Compressor::~Compressor() {}

void Compressor::applyEffect(const float &input, float &output) {
  //according to Fig. 7c

  // Step 2 + absolute value
  indB_ = linTodB(fabs(input));

  // Step 3
  outdB_ = calcGain(indB_);

  // Step 1
  // if(outdB_ > ) {
    inRMS_ = calcRMS(outdB_, att_a_);
  // } else {
  //   inRMS_ = calcRMS(outdB_, dec_a_);
  // }

  // Step 4
  makeUp_ = -thresh_ * (1 - (1/ratio_));
  outdB_ = inRMS_ + makeUp_;

  // Step 5
  outG_ = dBToLin(outdB_);

  // Step 6
  outG_ = clamp(outG_);
  output = input * outG_;
}

void Compressor::setAttDec(float att, float dec) {
  att_a_ = calcAttDec(att);
  dec_a_ = calcAttDec(dec);
}

float Compressor::calcAttDec(float attDec) {
  float tempAttDec = exp(2.2 / attDec * sampleRate_);
  return tempAttDec;
}

float Compressor::calcRMS(float x, float a) {
  //abs not needed anymore??
  abs_x_ = abs(x);
  a_ = a;

  yn0_ = a_ * yn1_ + (1 - a_) * abs_x_;
  yn1_ = yn0_;
  return yn0_;
}

float Compressor::calcGain(float indB) {
  if(indB > thresh_) {
    float tempOutdB = thresh_ + (indB - thresh_) / ratio_;
    return tempOutdB;
  } else {return indB;}
}

float Compressor::linTodB(float in) {
  float temp = 20 * log10f(in + 0.00000001);
  return temp;
}

float Compressor::dBToLin(float in) {
  float temp = powf(10.0f, in / 20.0f);
  return temp;
}

float Compressor::clamp(float gain) {
  if (gain > 1.0) {gain = 1.0;}
  return gain;
}
