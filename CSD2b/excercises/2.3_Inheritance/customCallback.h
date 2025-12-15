// Credits to Daan Schrier

//Connecting things to here
#include "audiocomponent.h"
#include "sine.h"
#include "square.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback (double Fs) : AudioCallback(Fs) {

    };

    ~CustomCallback() override {

    };

    void prepare (int sampleRate) override {

    };

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                //Writing the buffer

                // write sample to buffer at channel 0, amp = 0.25
                  //for sine
                outputChannels[channel][sample] = sine.getSample();
                sine.tick();
                  //for square
                outputChannels[channel][sample] = square.getSample();
                square.tick();
            };
        };
    };

private:
  //Making the sine
  Sine sine{440};
  //Making the square
  Square square{440};
};
