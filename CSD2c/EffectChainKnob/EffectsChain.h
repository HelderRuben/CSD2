#pragma once
#include <waveShaper.h>
#include <delay.h>
#include <saw.h>
#include "allPassFilter.h"
#include "nestedAPFOne.h"
#include "nestedAPFTwo.h"
#include <juce_audio_processors/juce_audio_processors.h>

class EffectsChain {
public:
    EffectsChain() {}
    void prepareToPlay(float sampleRate, int numSamplesPerBlock){
        // Your Prepare Goes Here

    }

    void getNextBlock(juce::AudioBuffer<float>& buffer){
        // Your DSP goes here
        // float outputSample1 = 0.0f;
        // float outputSample2 = 0.0f;
        //apf outputs
        float apf1output = 0.0f;
        float apf2output = 0.0f;
        float apf3output = 0.0f;
        float apf4output = 0.0f;
        // float apf5output = 0.0f;
        // float apf6output = 0.0f;
        // float apf7output = 0.0f;
        // float apf8output = 0.0f;
        // float apf9output = 0.0f;
        // float apf10output = 0.0f;

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){

                //WaveShaper does smth
                // waveShaper.processFrame(inputChannel[sample], outputSample1);
                //Delay does smth
                // delay.processFrame(outputSample1, outputSample2);
                //AllPassFilterdoes smth
                apf1.processFrame(inputChannel[sample], apf1output);
                apf2.processFrame(apf1output, apf2output);
                apf3.processFrame(apf2output, apf3output);
                apf4.processFrame(apf3output, apf4output);
                // apf5.processFrame(apf4output, apf5output);
                // apf6.processFrame(apf5output, apf6output);
                // apf7.processFrame(apf6output, apf7output);
                // apf8.processFrame(apf7output, apf8output);
                // apf9.processFrame(apf8output, apf9output);
                // apf10.processFrame(apf9output, apf10output);
                outputChannel[sample] = apf4output;
            }
        }
    }
    void setParameter(float parameter){
        // Your Code goes here
        //PARAMETER SLIDER
    }

private:
  // WaveShaper waveShaper;
  // Delay delay;
  AllPassFilter apf1{0.3, 384, 512};
  AllPassFilter apf2{0.3, 576, 600};
  NestedAPFOne apf3{
    0.5, 4176, 4200,
    0.25, 2976, 3000};
  NestedAPFTwo apf4{
    0.5, 5760, 5800,
    0.25, 3648, 3700,
    0.25, 1440, 1500
  };
  // AllPassFilter apf6{0.12, 1954, 2048, 0.95};
  // AllPassFilter apf7{0.29, 1301, 2048, 0.95};
  // AllPassFilter apf8{0.28, 416, 512, 0.95};
  // AllPassFilter apf9{0.11, 3647, 4096, 0.95};
  // AllPassFilter apf10{0.23, 1835, 2048, 0.95};
};
