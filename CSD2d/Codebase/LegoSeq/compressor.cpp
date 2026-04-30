#include "compressor.h"

Compressor::Compressor(
  float att,
  float dec,
  float thresh,
  float ratio)
   : thresh_(thresh), ratio_(ratio) {
  att_a_ = calcAttDec(att);
  dec_a_ = calcAttDec(dec);

}
Compressor::~Compressor() {}

void Compressor::applyEffect(const float &input, float &output) {
  if() {
    inRMS_ = calcRMS(input, att_a_);
  } else {
    inRMS_ = calcRMS(input, dec_a_);
  }
  linTodB(inRMS_);
  makeUp_ = -thresh_ * (1 - (1/ratio_));
  outdB_ = calcGain(indB_) + makeUp_;
  dBToLin();
  outG_ = clamp(outG_);
  output = input *
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
  abs_x_ = abs(x);
  a_ = a;

  yn0_ = a_ * yn1_ + (1 - a_) * abs_x;
  yn1_ = yn0_;
  return yn0_;
}

float Compressor::calcGain(float indB) {
  if(indB > thresh_) {
    float tempOutdB = thresh_ + (indB - thresh_) / ratio_;
    return tempOutdB;
  } else {return indB;}
}

void Compressor::linTodB(float in) {
  indB_ = 20 * log10f(in + 0.00000001);
}

void Compressor::dBToLin(float in) {
  outG_ = powf(10.0f, in / 20.0f);
}

float Compressor::clamp(gain) {
  if (gain > 1.0) {gain = 1.0;}
  return gain;
}
