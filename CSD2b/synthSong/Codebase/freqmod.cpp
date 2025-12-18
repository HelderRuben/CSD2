#include "freqmod.h"

//Default Constructor
Freqmod::Freqmod() : Freqmod(
  440.0f,
  1.5f,
  "sine",
  "sine")
{
  std::cout << "Freqmod - Default Constructor\n";
};

//Constructor
Freqmod::Freqmod(
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
  std::cout << "Freqmod - Constructor\n";
};

//Destructor
Freqmod::~Freqmod() {
  std::cout << "Freqmod - Destructor\n";
};

//FM
  float Freqmod::modulate(float carrierSample, float modulatorSample) {
    float carrPhase = CarrAndMod[0]->getPhase();
    // float modPhase = CarrAndMod[0]->getPhase();
    float RMSample = carrPhase * modulatorSample;
    return RMSample;
};
