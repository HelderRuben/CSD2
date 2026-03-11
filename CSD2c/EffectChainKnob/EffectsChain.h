#pragma once
#include <waveShaper.h>
#include <delay.h>
#include <saw.h>
#include <juce_audio_processors/juce_audio_processors.h>

class EffectsChain {
public:
    EffectsChain() {}
    void prepareToPlay(float sampleRate, int numSamplesPerBlock){
        // Your Prepare Goes Here

    }

    void getNextBlock(juce::AudioBuffer<float>& buffer){
        // Your DSP goes here
        float outputSample1 = 0.0f;
        float outputSample2 = 0.0f;

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                waveShaper.processFrame(inputChannel[sample], outputSample1);
                delay.processFrame(outputSample1, outputSample2);
                outputChannel[sample] = outputSample1;
            }
        }
    }
    void setParameter(float parameter){
        // Your Code goes here
        //PARAMETER SLIDER
    }

private:
  WaveShaper waveShaper;
  Delay delay;
};
