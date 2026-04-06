#pragma once
#include <waveShaper.h>
#include <delay.h>
#include <saw.h>
#include "allPassFilter.h"
#include "nestedAPFOne.h"
#include "nestedAPFTwo.h"
#include "phaser.h"
#include <juce_audio_processors/juce_audio_processors.h>

class EffectsChain {
public:
    EffectsChain() {}
    void prepareToPlay(float sampleRate, int numSamplesPerBlock){
        // Your Prepare Goes Here

    }

    void getNextBlock(juce::AudioBuffer<float>& buffer){
        // Your DSP goes here
        float outputSample = 0.0f;
        float outputSample1 = 0.0f;
        float outputSample2 = 0.0f;

        //PHASER FLOATS
        // float phaserapf1OUTPUT = 0.0f;
        // float phaserapf2OUTPUT = 0.0f;
        // float phaserapf3OUTPUT = 0.0f;
        // float phaserapf4OUTPUT = 0.0f;
        // float phaserapf5OUTPUT = 0.0f;
        // float phaserapf6OUTPUT = 0.0f;
        // float feedbackSample = 0.0f;
        // float feedback = 0.0f;
        // float LFOSample = 0.0f;
        // LFO.tick();

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                //TESTING PHASERRRR
                // phaser.applyEffect(inputChannel[sample], outputSample);

                //TESTING PHASER IN HERE (without feedback first)
                // LFOSample = LFO.getSample();
                // phaserapf1.applyEffect(inputChannel[sample] + feedbackSample, phaserapf1OUTPUT, LFOSample);
                // phaserapf2.applyEffect(phaserapf1OUTPUT, phaserapf2OUTPUT, LFOSample);
                // phaserapf3.applyEffect(phaserapf2OUTPUT, phaserapf3OUTPUT, LFOSample);
                // phaserapf4.applyEffect(phaserapf3OUTPUT, phaserapf4OUTPUT, LFOSample);
                // phaserapf5.applyEffect(phaserapf4OUTPUT, phaserapf5OUTPUT, LFOSample);
                // phaserapf6.applyEffect(phaserapf5OUTPUT, phaserapf6OUTPUT, LFOSample);
                // feedbackSample = phaserapf6OUTPUT * feedback;
                //
                // outputSample = (phaserapf6OUTPUT * 0.5) + (inputChannel[sample] * 0.5);

                // waveshaper.processFrame(inputChannel[sample], outputSample);
                phaser.processFrame(inputChannel[sample], outputSample1);
                // reverb.processFrame(inputChannel[sample], outputSample2);
                outputChannel[sample] = outputSample1 * 0.8; //some extra gaining just to be sure
            }
        }
    }
    void setParameter(float parameter){
        if (prevParameter != parameter) {
          // waveshaper.setDryWet(1 - parameter);
          // reverb.setDryWet(parameter);
          if (parameter < 0.5) {phaser.setDryWet(parameter * 2);}
          if (parameter >= 0.5) {phaser.setDryWet(1 - ((parameter * 2) - 1));}
        }
        prevParameter = parameter;
    }

private:
  // AllPassFilter phaserapf1{0.06, 1, 8};
  // AllPassFilter phaserapf2{0.12, 1, 8};
  // AllPassFilter phaserapf3{0.18, 1, 8};
  // AllPassFilter phaserapf4{0.24, 1, 8};
  // AllPassFilter phaserapf5{0.3, 1, 8};
  // AllPassFilter phaserapf6{0.36, 1, 8};
  // Sine LFO{0.5, 48000};

  // Phaser phaser{0.0, 0.08, 0.5, 0.8};
  WaveShaper phaser;
  float prevParameter = 0.0f;
};
