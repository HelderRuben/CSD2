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
  //=-=-=-=-=-=-=-=-= according to Fig. 7c =-=-=-=-=-=-=-=-=

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

  // //=-=-=-=-=-=-=-=-= according to SimpleComp =-=-=-=-=-=-=-=-=
  //
  // //Step 1: define things as DC OFFSET
  //   //Needed in process? where? First test without
  //
  // //    Step 1.5: Square inputs and stuff (SimpleComp Step)
  //
  // //Step 2: Averager Envelope calculation
  // = calcRMS(input, 5);
  //
  // //    Step 2.5: Rectify just in case (SimpleComp step)
  //
  // //Step 3: lin2dB
  // = linTodB()
  //
  // //Step 4: calc delta over thresh + DC OFFSET
  //
  // //Step 5: att or dec envelope calculation (minus DC OFFSET)
  // if(xxx > prevRMS) {
  //   = calcRMS(xxx, att_a_);
  // } else {
  //   = calcRMS(xxx, dec_a_);
  // }
  // xxx -= DC_OFFSET;
  //
  // //Step 6: Transfer function calculation (apparantly)
  // = xxx * (ratio_ - 1);  //With ratio_ = [0, 1]
  //
  // //Step 7: dB2lin
  // = dBToLin(xxx);
  //
  // //Step 8: apply gain to input
  // output = input * xxx;
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

  // state = in + a_ * ( state - in )
}

float Compressor::calcGain(float indB) {
  if(indB > thresh_) {
    float tempOutdB = thresh_ + (indB - thresh_) / ratio_;
    return tempOutdB;
  } else {return indB;}
}

float Compressor::linTodB(float lin) {
  float dB = 20 * log10f(lin + 0.00000001);
  return dB;
}

float Compressor::dBToLin(float dB) {
  float lin = powf(10.0f, dB / 20.0f);
  return lin;
}

//clamp thoughts: is this needed? bc cant the gain go above 1 to boost the things or am i crazy
float Compressor::clamp(float gain) {
  if (gain > 1.0) {gain = 1.0;}
  return gain;
}
