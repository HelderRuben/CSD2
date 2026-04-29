#include "bitcrush.h"

Bitcrush::Bitcrush(int N) : N_(N) {}
Bitcrush::~Bitcrush() {}

void Bitcrush::applyEffect(const float &input, float &output) {
  QL_ = 2 / (pow(2, N_) - 1);

  output = QL_ * int(input / QL_);
}
