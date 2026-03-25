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
        float outputSample1 = 0.0f;
        float outputSample2 = 0.0f;

        // PIRKLE LARGE ROOM REVERBERATOR
        //apf outputs
        float apf1output = 0.0f;
        float apf2output = 0.0f;
        float apf3output = 0.0f;
        float apf4output = 0.0f;
        //These are the different points in the system that get added up before the output
        float lineOne = 0.0f;
        float lineTwo = 0.0f;
        float lineThree = 0.0f;
        //This is the sample from the feedbackloop that runs through a BPF (that i dont have (yet))
        float feedbackSample = 0.0f;
        // Final outputSample:
        float outputSample = 0.0f;

        //PHASER FLOATS
        // float phaserapf1OUTPUT = 0.0f;
        // float phaserapf2OUTPUT = 0.0f;
        // float phaserapf3OUTPUT = 0.0f;
        // float phaserapf4OUTPUT = 0.0f;
        // float phaserapf5OUTPUT = 0.0f;
        // float phaserapf6OUTPUT = 0.0f;
        // float phaserapf7OUTPUT = 0.0f;

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                // PIRKLE LARGE ROOM REVERBERATOR
                apf1.processFrame(inputChannel[sample] + feedbackSample, apf1output);
                apf2.processFrame(apf1output, apf2output);
                lineOne = apf2output * 0.6;
                apf3.processFrame(apf2output, apf3output);
                lineTwo = apf3output * 0.8;
                apf4.processFrame(apf3output, apf4output);
                lineThree = apf4output * 0.7;
                feedbackSample = apf4output * 0.45;
                outputSample = lineOne + lineTwo + lineThree;


                //TESTING PHASERRRR
                // phaser.processFrame(inputChannel[sample], outputSample);

                //TESTING PHASER IN HERE (without feedback first)
                // phaserapf1.processFrame(inputChannel[sample], phaserapf1OUTPUT);
                // phaserapf2.processFrame(phaserapf1OUTPUT, phaserapf2OUTPUT);
                // phaserapf3.processFrame(phaserapf2OUTPUT, phaserapf3OUTPUT);
                // phaserapf4.processFrame(phaserapf3OUTPUT, phaserapf4OUTPUT);
                // phaserapf5.processFrame(phaserapf4OUTPUT, phaserapf5OUTPUT);
                // phaserapf6.processFrame(phaserapf5OUTPUT, phaserapf6OUTPUT);
                // outputSample = (phaserapf6OUTPUT * 0.5) + (inputChannel[sample] * 0.5);

                outputChannel[sample] = outputSample * 0.8; //some extra gaining just to be sure
            }
        }
    }
    void setParameter(float parameter){
        // Your Code goes here (look at where setParameter is used)
        //PARAMETER SLIDER
    }

private:
  // AllPassFilter phaserapf1{0.000002, 1, 8};
  // AllPassFilter phaserapf2{0.000004, 1, 8};
  // AllPassFilter phaserapf3{0.000006, 1, 8};
  // AllPassFilter phaserapf4{0.000008, 1, 8};
  // AllPassFilter phaserapf5{0.00001, 1, 8};
  // AllPassFilter phaserapf6{0.000012, 1, 8};

  // Phaser phaser;

  // PIRKLE LARGE ROOM REVERBERATOR
  AllPassFilter apf1{0.3, 384, 512};
  AllPassFilter apf2{0.3, 576, 600};
  NestedAPFOne apf3{
    0.5, 1200, 1250,
    0.25, 2976, 3000};
  NestedAPFTwo apf4{
    0.5, 672, 5800,
    0.25, 3648, 3700,
    0.25, 1440, 1500
  };
};
