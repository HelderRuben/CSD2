#include "callback.h"

//Constructor wth initialiser list, with oscillators
Callback::Callback (float samplerate) : AudioCallback (samplerate) {
  std::cout << "Callback - Constructor\n";

    //SYNTH KIND
  // std::cout << "What kinda Synth you want?\n";
  // synthPtr->chosenSynth = userinput::UIReturnString(synthOptions, 2);

    //CARRIERS WAVEFORM
  std::cout << "What's the Carrier waveform?\n";
  std::string UICarrWaveform = userinput::UIReturnString(waveforms, 3);

    //MODULATORS WAVEFORM
  std::cout << "What's the Modulator waveform?\n";
  std::string UIModWaveform = userinput::UIReturnString(waveforms, 3);

    //CARRIER-MODULATOR RATIO
  std::cout << "What's the carrier-modulator ratio?\n";
  float UIRatio = userinput::UIReturnFloat(1.0f, 5.0f);

  Callback::setOscs(UICarrWaveform, UIModWaveform, UIRatio);
    //MODULATION AMOUNT
  // std::cout << "How much is the modulation amount?\n";
  // synthPtr->chosenModAmount = userinput::UIReturnFloat(0.0f, 1.0f);
};

//Destructor for deleting pointer
Callback::~Callback() {
  std::cout << "Callback - Destructor\n";
  delete synthPtr;
}

//LINKING TO SYNTH CLASS
void Callback::setOscs(
  std::string carrWaveform,
  std::string modWaveform,
  float ratio)
{
  synthPtr = new Synth();
  synthPtr->setOscs(carrWaveform, modWaveform, ratio);
}

//Function for making the samplerate the samplerate used by the oscillators
void Callback::prepare(int samplerate) {
  synthPtr->setSamplerate(samplerate);
  std::cout << "\nSamplerate: " << samplerate << "\n";
};

//Function for processing the buffer
void Callback::process(AudioBuffer buffer) {
  //Automatically detecting the type of these variables
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  //For every channel used as ouput
  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    //For every frame used
    for (int frame = 0u; frame < numFrames; ++frame) {
      //Assigning float as type to output
      outputChannels[channel][frame] = 0.0f;
      //Calculating total sample value by adding oscillators
      float sample = synthPtr->getSample();
      //normalising sample value
      sample *= 0.5f;
      //making sample the output
      outputChannels[channel][frame] = sample;
      //Updating sample of oscillators
      synthPtr->tick();
    };
  };
};
