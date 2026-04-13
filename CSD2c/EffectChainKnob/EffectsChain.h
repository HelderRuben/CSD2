#pragma once
#include <waveShaper.h>
#include <delay.h>
#include "roomReverb.h"
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
        // float waveshaperOut = 0.0f;
        float phaserOut = 0.0f;
        // float reverbOut = 0.0f;

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                if(channel == 0) {
                  // waveshaperL.processFrame(inputChannel[sample], waveshaperOut);
                  // waveshaperOut = waveshaperOut * waveshaperGain;
                  // phaserL.processFrame(waveshaperOut, phaserOut);
                  // reverbL.processFrame(waveshaperOut, reverbOut);
                  phaserL.processFrame(inputChannel[sample], phaserOut);
                }
                if(channel == 1) {
                  // waveshaperR.processFrame(inputChannel[sample], waveshaperOut);
                  // waveshaperOut = waveshaperOut * waveshaperGain;
                  // phaserR.processFrame(waveshaperOut, phaserOut);
                  // reverbR.processFrame(waveshaperOut, reverbOut);
                  phaserR.processFrame(inputChannel[sample], phaserOut);
                }
                // outputChannel[sample] = reverbOut * waveshaperGain;
                outputChannel[sample] = phaserOut;
            }
        }
    }
    void setParameter(float parameter){
        if (prevParameter != parameter) {
          // reverbL.setFeedback(parameter);
          // reverbR.setFeedback(parameter);
          // reverbL.setDryWet(parameter);
          // reverbR.setDryWet(parameter);
          // waveshaperGain = 0.35 + (parameter * 0.65);
          // waveshaperL.setDryWet(1 - parameter);
          // waveshaperR.setDryWet(1 - parameter);

          if (parameter < 0.5) {
            // phaserL.setDryWet(parameter * 2);
            // phaserR.setDryWet(parameter * 2);
          }
          if (parameter >= 0.5) {
            // phaserL.setDryWet(1 - ((parameter * 2) - 1));
            // phaserR.setDryWet(1 - ((parameter * 2) - 1));
          }

          //MAPPING PARAM FOR TESTING
          mapParam1 = parameter * 3.5;
          mapParam2 = parameter;
          //TESTING PHASER VALUES
          phaserL.setLFOSpeed(mapParam1);
          phaserR.setLFOSpeed(mapParam1);
          phaserL.setLFODepth(mapParam2);
          phaserR.setLFODepth(mapParam2);

        }
        prevParameter = parameter;
    }

private:
  // WaveShaper waveshaperL;
  // WaveShaper waveshaperR;
  Phaser phaserL;
  Phaser phaserR;
  // RoomReverb reverbL{0};
  // RoomReverb reverbR{0};
  float prevParameter = 0.0f;
  float mapParam1 = 0.0f;
  float mapParam2 = 0.0f;
  // float waveshaperGain = 0.0f;
};
