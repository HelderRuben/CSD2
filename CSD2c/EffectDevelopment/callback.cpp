#include "callback.h"


CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), sampleRate (sampleRate) {}

void CustomCallback::prepare (int rate) {
  sampleRate = (float) rate;
  std::cout << "\nsamplerate: " << sampleRate << "\n";

    sine.prepare(sampleRate);
    sine.setFrequency(targetParameter);

    // square.prepare(sampleRate);
    // square.setFrequency(targetParameter);

  oscServer.init (serverport);
  oscServer.set_callback ("/parameter", "f");

  oscServer.start();
  std::cout << "OSC Server listening on port: " << serverport << std::endl;
}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    float outputSample = 0.0f;
    sine.setFrequency(targetParameter);
    // square.setFrequency(targetParameter);

    for (int sample = 0u; sample < numFrames; ++sample) {
        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            //process waveshaper frame
            // waveShaper.processFrame(sine.getSample(), outputSample);

            //process AllPassFilter frame
            allPassFilter.processFrame(sine.getSample(), outputSample);
            //IF NO EFFECT:
            // outputChannels[channel][sample] = sine.getSample() * 0.2;
            // IF EFFECT:
            outputChannels[channel][sample] = outputSample * 0.2;
        }
        sine.tick();
        // square.tick();
    }
}
