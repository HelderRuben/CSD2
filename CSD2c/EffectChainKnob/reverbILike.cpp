#include "reverbILike.h"

ReverbILike::ReverbILike() {
  rev1 = new PirkleReverb{0};
  rev2 = new PirkleReverb{1};
  rev3 = new PirkleReverb{2};
}

ReverbILike::~ReverbILike() {
  delete rev1;
  rev1 = nullptr;
  delete rev2;
  rev2 = nullptr;
  delete rev3;
  rev3 = nullptr;
}

void ReverbILike::applyEffect(const float &input, float &output) {
  rev1->processFrame(input, rev1out);
  rev2->processFrame(input, rev2out);
  rev3->processFrame(input, rev3out);
  output = (rev1out + rev2out + rev3out) * 0.33;
}

// void ReverbILike::setLineGain(float line1Gain, float line2Gain, float line3gain) {

// }
