#include "callback.h"

//Constructor wth initialiser list, with oscillators
Callback::Callback (float samplerate)
  : AudioCallback (samplerate),
    test(440, 1.5f)
{std::cout << "Callback - Constructor\n";};


//Function for making the chosen samplerate the samplerate used by the oscillators
void Callback::prepare(int samplerate) {
  test.setSamplerate(samplerate);
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
      float sample = test.getSample();
      //normalising sample value
      sample *= 0.5f;
      //making sample the output
      outputChannels[channel][frame] = sample;
      //Updating sample of oscillators
      test.tick();
    };
  };
};
