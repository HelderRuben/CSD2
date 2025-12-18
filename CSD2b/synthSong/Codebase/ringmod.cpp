#include "ringmod.h"

//Default Constructor
Ringmod::Ringmod() : Ringmod(
  440.0f,
  1.5f,
  "sine",
  "sine")
{
  std::cout << "Ringmod - Default Constructor\n";
};

//Constructor
Ringmod::Ringmod(
  float frequency,
  float ratio,
  std::string chosenCarrWaveform,
  std::string chosenModWaveform)
  : Synth(
    frequency,
    ratio,
    chosenCarrWaveform,
    chosenModWaveform)
{
  std::cout << "Ringmod - Constructor\n";
};

//Destructor
Ringmod::~Ringmod() {
  std::cout << "Ringmod - Destructor\n";
};

//RM
float Ringmod::modulate(float carrierSample, float modulatorSample) {
  float RMSample = carrierSample * modulatorSample;
  return RMSample;
}
