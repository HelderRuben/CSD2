#pragma once
#include <waveShaper.h>
#include <delay.h>
// #include <saw.h>
#include "pirkleReverb.h"
#include "allPassFilter.h"
#include "nestedAPFOne.h"
#include "nestedAPFTwo.h"
#include "phaser.h"
#include "simpleAPF.h"

#include <juce_audio_processors/juce_audio_processors.h>

class EffectsChain {
public:
    EffectsChain() {}
    void prepareToPlay(float sampleRate, int numSamplesPerBlock){
        // Your Prepare Goes Here
    }

    void getNextBlock(juce::AudioBuffer<float>& buffer){
        float outputSample = 0.0f;
        float outputSample1 = 0.0f;
        float outputSample2 = 0.0f;
        float outputSample3 = 0.0f;

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                // waveshaper.processFrame(inputChannel[sample], outputSample);
                // phaser.processFrame(inputChannel[sample], outputSample1);
                reverb.processFrame(inputChannel[sample], outputSample);
                reverb1.processFrame(inputChannel[sample], outputSample1);
                reverb2.processFrame(inputChannel[sample], outputSample2);
                outputSample3 = (outputSample + outputSample1 + outputSample2) * 0.33;
                outputChannel[sample] = outputSample * 0.8; //some extra gaining just to be sure
            }
        }
    }
    void setParameter(float parameter){
        if (prevParameter != parameter) {
          // waveshaper.setDryWet(1 - parameter);
          reverb.setDryWet(parameter);
          // if (parameter < 0.5) {phaser.setDryWet(parameter * 2);}
          // if (parameter >= 0.5) {phaser.setDryWet(1 - ((parameter * 2) - 1));}

          //MAPPING PARAM FOR TESTING
          // mapParam = parameter * 0.2;
          //TESTING PHASER VALUES
          // phaser.setLFOSpeed(mapParam);
          // phaser.setLFODepth(mapParam);
        }
        prevParameter = parameter;
    }

private:
  WaveShaper waveshaper;
  // Phaser phaser;
  PirkleReverb reverb{0};
  PirkleReverb reverb1{1};
  PirkleReverb reverb2{2};
  float prevParameter = 0.0f;
  float mapParam = 0.0f;
};
