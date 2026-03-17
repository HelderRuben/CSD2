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
        float outputSample1 = 0.0f;
        float outputSample2 = 0.0f;
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
        //Final outputSample:
        float outputSample = 0.0f;
        // float apf5output = 0.0f;
        float apf6output = 0.0f;
        float apf7output = 0.0f;
        float apf8output = 0.0f;
        // float apf9output = 0.0f;
        // float apf10output = 0.0f;

        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){

                //WaveShaper does smth
                // waveShaper.processFrame(inputChannel[sample], outputSample1);

                //Delay does smth


                //PIRKLE LARGE ROOM REVERBERATOR
                // apf1.processFrame(inputChannel[sample] + feedbackSample, apf1output);
                // apf2.processFrame(apf1output, apf2output);
                // lineOne = apf2output * 0.6;
                // apf3.processFrame(apf2output, apf3output);
                // lineTwo = apf3output * 0.8;
                // apf4.processFrame(apf3output, apf4output);
                // lineThree = apf4output * 0.7;
                // feedbackSample = apf4output * 0.45;
                // outputSample = lineOne + lineTwo + lineThree;


                //page 95 test
                apf6.processFrame(inputChannel[sample], apf6output);
                apf7.processFrame(apf6output, apf7output);
                apf8.processFrame(apf7output, apf8output);

                delay1.processFrame(apf8output, outputSample1);
                delay2.processFrame(apf8output, outputSample2);
                delay3.processFrame(apf8output, feedbackSample);
                outputSample = outputSample1 + outputSample2 + feedbackSample;
                // apf9.processFrame(apf8output, apf9output);
                // apf10.processFrame(apf9output, apf10output);
                outputChannel[sample] = outputSample * 0.8; //some extra gaining just to be sure
            }
        }
    }
    void setParameter(float parameter){
        // Your Code goes here (look at where setParameter is used)
        //PARAMETER SLIDER
    }

private:
  // WaveShaper waveShaper;
  Delay delay1{0.7, 2397, 2450, 0.8};
  Delay delay2{0.5, 8357, 8400, 0.3};
  Delay delay3{0.8, 4296, 4350, 0.6};

  //PIRKLE LARGE ROOM REVERBERATOR
  // AllPassFilter apf1{0.3, 384, 512};
  // AllPassFilter apf2{0.3, 576, 600};
  // NestedAPFOne apf3{
  //   0.5, 1200, 1250,
  //   0.25, 2976, 3000};
  // NestedAPFTwo apf4{
  //   0.5, 672, 5800,
  //   0.25, 3648, 3700,
  //   0.25, 1440, 1500
  // };


  AllPassFilter apf6{0.7, 1052, 1100};
  AllPassFilter apf7{0.7, 337, 350};
  AllPassFilter apf8{0.7, 113, 130};
  // AllPassFilter apf9{0.56, 2162, 2600};
  // AllPassFilter apf10{0.65, 2568, 2600};
};
