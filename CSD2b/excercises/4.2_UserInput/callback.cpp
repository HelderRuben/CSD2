#include "callback.h"

//Constructor wth initialiser list, with oscillators
Callback::Callback (float samplerate) : AudioCallback (samplerate), synthPtr(){
  std::cout << "Callback - Constructor\n";

    //SYNTH KIND
  std::cout << "What kinda Synth you want?\n";
  // synthOptions[2] = {"FM", "RM"};
  synthPtr->chosenSynth = userinput::UIReturnString(synthOptions, 2);

    //CARRIERS WAVEFORM
  std::cout << "What's the Carrier waveform?\n";
  // waveforms[3] = {"sine", "saw", "square"};
  synthPtr->chosenCarrWaveform = userinput::UIReturnString(waveforms, 3);

    //MODULATORS WAVEFORM
  std::cout << "What's the Modulator waveform?\n";
  synthPtr->chosenModWaveform = userinput::UIReturnString(waveforms, 3);

    //CARRIER-MODULATOR RATIO
  std::cout << "What's the carrier-modulator ratio?\n";
  synthPtr->chosenRatio = userinput::UIReturnFloat(1.0f, 5.0f);

    //MODULATION AMOUNT
  std::cout << "How much is the modulation amount?\n";
  synthPtr->chosenModAmount = userinput::UIReturnFloat(0.0f, 1.0f);

  // synthPtr(440, chosenRatio, chosenCarrWaveform, chosenModWaveform);
};

//Destructor for deleting pointer
Callback::~Callback() {
  std::cout << "Callback - Destructor\n";
  delete synthPtr;
}


//Function for making the chosen samplerate the samplerate used by the oscillators
void Callback::prepare(int samplerate) {
  synthPtr->setSamplerate(samplerate);
  std::cout << "\nSamplerate: " << samplerate << "\n";
};

//Function for processing the buffer (making and ???)
void Callback::process(AudioBuffer buffer) {
  //Automatically detecting the type of these variables
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  //Deathly for-loop
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
