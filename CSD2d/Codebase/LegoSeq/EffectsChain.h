#pragma once
#include <waveShaper.h>

#include "roomReverb.h"
#include "allPassFilter.h"
#include "nestedAPFOne.h"
#include "nestedAPFTwo.h"

#include "phaser.h"
#include "simpleAPF.h"
#include "bitcrush.h"
#include "lowpass.h"
#include "linkRileyLPF.h"
#include "compressor.h"

#include <juce_audio_processors/juce_audio_processors.h>

class EffectsChain {
public:
    EffectsChain() {}
    void prepareToPlay(float sampleRate, int numSamplesPerBlock){}

    void getNextBlock(juce::AudioBuffer<float>& buffer){
        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                if(channel == 0) {
                  // waveshaperL.processFrame(inputChannel[sample], waveshaperOut);
                  // waveshaperOut = waveshaperOut * waveshaperGain;
                  // phaserL.processFrame(waveshaperOut, phaserOut);
                  // reverbL.processFrame(phaserOut, reverbOut);
                  // bitcrushL.processFrame(inputChannel[sample], bitcrushOut);
                  lowpassL.processFrame(inputChannel[sample], bitcrushOut);
                }
                if(channel == 1) {
                  // waveshaperR.processFrame(inputChannel[sample], waveshaperOut);
                  // waveshaperOut = waveshaperOut * waveshaperGain;
                  // phaserR.processFrame(waveshaperOut, phaserOut);
                  // reverbR.processFrame(phaserOut, reverbOut);
                  // bitcrushR.processFrame(inputChannel[sample], bitcrushOut);
                  lowpassR.processFrame(inputChannel[sample], bitcrushOut);
                }
                // outputChannel[sample] = reverbOut * waveshaperGain;
                outputChannel[sample] = bitcrushOut;
            }
        }
    }
    void setParameter(float parameter){
        if (prevParameter != parameter) {
          reverbL.setFeedback(parameter);
          reverbR.setFeedback(parameter);
          reverbL.setDryWet(parameter);
          reverbR.setDryWet(parameter);
          waveshaperL.setDryWet(0.5 - (parameter * 0.75));
          waveshaperR.setDryWet(0.5 - (parameter * 0.75));
          // bitcrushL.setN(int(parameter * 14 + 2));
          bitcrushL.setN(int(parameter * 7 + 3));
          // bitcrushR.setN(int(parameter * 14 + 2));
          bitcrushR.setN(int(parameter * 7 + 3));
          bitcrushL.setDryWet(parameter);
          bitcrushR.setDryWet(parameter);
          lowpassL.calcBreakFreq(parameter);
          lowpassR.calcBreakFreq(parameter);

          if (parameter < 0.5) {
            waveshaperGain = 0.5 + parameter;
            phaserL.setDryWet(parameter * 2);
            phaserR.setDryWet(parameter * 2);
            mapLFOSpeed = parameter;
            mapLFODepth = (parameter * 2) * 0.2;
          }
          if (parameter >= 0.5) {
            waveshaperGain = 1.0;
            phaserL.setDryWet(1 - ((parameter * 2) - 1));
            phaserR.setDryWet(1 - ((parameter * 2) - 1));
            mapLFOSpeed = 1 - parameter;
            mapLFODepth = (1 - ((parameter * 2) - 1)) * 0.2;
          }
          // phaserL.setLFOSpeed(mapLFOSpeed);
          // phaserR.setLFOSpeed(mapLFOSpeed);
          // phaserL.setFeedback(mapLFOSpeed * 1.2);
          // phaserR.setFeedback(mapLFOSpeed * 1.2);
          // phaserL.setLFODepth(mapLFODepth);
          // phaserR.setLFODepth(mapLFODepth);
        }
        prevParameter = parameter;
    }

private:
  WaveShaper waveshaperL;
  WaveShaper waveshaperR;
  Phaser phaserL{0.0, 0.0, 0.05, 1};
  Phaser phaserR{0.0, 0.0, 0.05, -1};
  RoomReverb reverbL;
  RoomReverb reverbR;
  Bitcrush bitcrushL;
  Bitcrush bitcrushR;
  LinkRileyLPF lowpassL;
  LinkRileyLPF lowpassR;
  Compressor compL;
  Compressor compR;

  float prevParameter = 0.1f;
  float mapLFOSpeed = 0.0f;
  float mapLFODepth = 0.0f;
  float waveshaperGain = 0.0f;

  float waveshaperOut = 0.0f;
  float phaserOut = 0.0f;
  float reverbOut = 0.0f;
  float bitcrushOut = 0.0f;
  float lowpassOut = 0.0f;
};
