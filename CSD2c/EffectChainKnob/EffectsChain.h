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



        //apf outputs
        float xtra1apf1output = 0.0f;
        float xtra1apf2output = 0.0f;
        float xtra1apf3output = 0.0f;
        float xtra1apf4output = 0.0f;
        //These are the different points in the system that get added up before the output
        float xtra1lineOne = 0.0f;
        float xtra1lineTwo = 0.0f;
        float xtra1lineThree = 0.0f;
        //This is the sample from the feedbackloop that runs through a BPF (that i dont have (yet))
        float xtra1feedbackSample = 0.0f;
        // Final outputSample:
        float xtra1outputSample = 0.0f;



        //apf outputs
        float xtra2apf1output = 0.0f;
        float xtra2apf2output = 0.0f;
        float xtra2apf3output = 0.0f;
        float xtra2apf4output = 0.0f;
        //These are the different points in the system that get added up before the output
        float xtra2lineOne = 0.0f;
        float xtra2lineTwo = 0.0f;
        float xtra2lineThree = 0.0f;
        //This is the sample from the feedbackloop that runs through a BPF (that i dont have (yet))
        float xtra2feedbackSample = 0.0f;
        // Final outputSample:
        float xtra2outputSample = 0.0f;






        float apf5output = 0.0f;
        float apf6output = 0.0f;
        float apf7output = 0.0f;
        float apf8output = 0.0f;

        float delay1Output = 0.0f;
        float delay2Output = 0.0f;
        float delay3Output = 0.0f;
        float delay4Output = 0.0f;


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
                lineOne = apf2output * 0.5;
                apf3.processFrame(apf2output, apf3output);
                lineTwo = apf3output * 0.3;
                apf4.processFrame(apf3output, apf4output);
                lineThree = apf4output * 0.5;
                feedbackSample = apf4output * 0.45;
                outputSample1 = lineOne + lineTwo + lineThree;

                xtra1apf1.processFrame(inputChannel[sample] + feedbackSample, xtra1apf1output);
                xtra1apf2.processFrame(xtra1apf1output, xtra1apf2output);
                xtra1lineOne = xtra1apf2output * 0.6;
                xtra1apf3.processFrame(xtra1apf2output, xtra1apf3output);
                xtra1lineTwo = xtra1apf3output * 0.4;
                xtra1apf4.processFrame(xtra1apf3output, xtra1apf4output);
                xtra1lineThree = xtra1apf4output * 0.55;
                xtra1feedbackSample = xtra1apf4output * 0.45;
                xtra1outputSample = xtra1lineOne + xtra1lineTwo + xtra1lineThree;

                xtra2apf1.processFrame(inputChannel[sample] + feedbackSample, xtra2apf1output);
                xtra2apf2.processFrame(xtra2apf1output, xtra2apf2output);
                xtra2lineOne = xtra2apf2output * 0.9;
                xtra2apf3.processFrame(xtra2apf2output, xtra2apf3output);
                xtra2lineTwo = xtra2apf3output * 0.5;
                xtra2apf4.processFrame(xtra2apf3output, xtra2apf4output);
                xtra2lineThree = xtra2apf4output * 0.4;
                xtra2feedbackSample = xtra2apf4output * 0.45;
                xtra2outputSample = xtra2lineOne + xtra2lineTwo + xtra2lineThree;

                outputSample = (outputSample1 + xtra1outputSample + xtra2outputSample) * 0.33;


                //WEIRD DELAY + APF THING
                // apf1.processFrame(inputChannel[sample] + feedbackSample, apf1output);
                // apf2.processFrame(apf1output, apf2output);
                // apf3.processFrame(apf2output, apf3output);
                // apf4.processFrame(apf3output, apf4output);
                //
                // apf5.processFrame(inputChannel[sample] + feedbackSample, apf5output);
                // apf6.processFrame(apf5output, apf6output);
                // lineOne = apf6output * 0.3;
                // apf7.processFrame(apf6output, apf7output);
                // lineTwo = apf7output * 0.4;
                // apf8.processFrame(apf7output, apf8output);
                // lineThree = apf8output * 0.9;
                // feedbackSample = apf8output * 0.35;
                // float tempoutputSample = lineOne + lineTwo + lineThree;
                // delay1.processFrame(tempoutputSample, delay1Output);
                // delay2.processFrame(tempoutputSample, delay2Output);
                // delay3.processFrame(tempoutputSample, delay3Output);
                // delay4.processFrame(tempoutputSample, delay4Output);
                // outputSample = (delay1Output + delay2Output + delay3Output + delay4Output + tempoutputSample) * 0.20;

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
  AllPassFilter apf1{0.35, 384, 512};
  AllPassFilter apf2{0.3, 576, 600};
  NestedAPFOne apf3{
    0.5, 1200, 1250,
    0.25, 2976, 3000};
  NestedAPFTwo apf4{
    0.5, 672, 680,
    0.25, 3648, 3700,
    0.25, 1440, 1500
  };

  AllPassFilter xtra1apf1{0.4, 413, 512};
  AllPassFilter xtra1apf2{0.35, 534, 600};
  NestedAPFOne xtra1apf3{
    0.3, 1134, 1250,
    0.45, 3197, 3200};
  NestedAPFTwo xtra1apf4{
    0.6, 649, 660,
    0.45, 3856, 3900,
    0.15, 1340, 1500
  };

  AllPassFilter xtra2apf1{0.3, 367, 512};
  AllPassFilter xtra2apf2{0.4, 614, 630};
  NestedAPFOne xtra2apf3{
    0.6, 1236, 1250,
    0.2, 2743, 3000};
  NestedAPFTwo xtra2apf4{
    0.45, 699, 710,
    0.15, 3578, 3700,
    0.45, 1540, 1550
  };




  // AllPassFilter apf1{0.3, 23, 25};
  // AllPassFilter apf2{0.3, 14, 16};
  // NestedAPFOne apf3{
  //   0.5, 50, 53,
  //   0.25, 73, 76};
  // NestedAPFTwo apf4{
  //   0.5, 41, 44,
  //   0.25, 107, 110,
  //   0.25, 89, 93
  // };
  //
  // AllPassFilter apf5{0.3, 187, 195};
  // AllPassFilter apf6{0.3, 289, 300};
  // NestedAPFOne apf7{
  //   0.5, 599, 605,
  //   0.25, 1476, 1500};
  // NestedAPFTwo apf8{
  //   0.5, 336, 350,
  //   0.25, 1823, 1850,
  //   0.25, 721, 730
  // };
  // Delay delay1{0.8, 2048, 2050, 1};
  // Delay delay2{0.8, 1703, 1850, 1};
  // Delay delay3{0.8, 1309, 1330, 1};
  // Delay delay4{0.8, 2246, 2250, 1};
};
