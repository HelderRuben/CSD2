#pragma once
#include <effect.h>
#include <cmath>

//Bitcrush with naming according to Pirkle
class Bitcrush : public Effect
{
public:
  Bitcrush(int N = 16);
  ~Bitcrush();

  void applyEffect(const float &input, float &output) override;

  void setN(int N) {N_ = N;};
  int getN() {return N_;};

private:
  int N_;
  float QL_;
};
