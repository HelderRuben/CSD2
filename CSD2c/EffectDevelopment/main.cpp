#include <iostream>
#include "callback.h"
#include "allPassFilter.h"
#include <square.h>
#include <sine.h>

#define SAMPLERATE 48000

int main(int argc, char **argv) {
  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource{44100};
  JUCEModule juceModule (audioSource);
  juceModule.init (2, 2);

  AllPassFilter allPassFilter{0.4, 2, 512, 0.9};
  float freq = 400;

  // Square square(freq, SAMPLERATE);
  // Sine sine(freq, SAMPLERATE);

  //TESTING SAMPLE VALUES
  float squareSample = 0;
  float sineSample = 0;
  float impulsSample = 0;
  float outputSample = 0;
  for(int i = 0; i < 512; i++) {
    //SQUARE
    // squareSample = square.getSample();
    // allPassFilter.setWriteValue(squareSample);
    // std::cout << "Square: " << squareSample << " | RH: " << allPassFilter.getReadValue() << " | ";
    // allPassFilter.logRWPos();
    // allPassFilter.applyEffect(squareSample, outputSample);
    // std::cout << " | Outputsample: " << outputSample << "\n";
    // square.tick();

    //SINE
    // sineSample = sine.getSample();
    // allPassFilter.setWriteValue(sineSample);
    // std::cout << "Sine: " << sineSample << " | RH: " << allPassFilter.getReadValue() << " | ";
    // allPassFilter.logRWPos();
    // allPassFilter.applyEffect(sineSample, outputSample);
    // std::cout << " | Outputsample: " << outputSample << "\n";
    // sine.tick();

    //IMPULS
    // if (i == 10) {impulsSample = 1;}
    // else {impulsSample = 0;}
    // allPassFilter.setWriteValue(impulsSample);
    // std::cout << "Impuls: " << impulsSample << " | RH: " << allPassFilter.getReadValue() << " | ";
    // allPassFilter.logRWPos();
    // allPassFilter.applyEffect(impulsSample, outputSample);
    // std::cout << " | Outputsample: " << outputSample << "\n";
  }
  //ALLPASSFILTER
  // allPassFilter.logAllSettings();
  // allPassFilter.logAllValues();
  // allPassFilter.logFeedback();

  std::cout << "Press q + Enter to quit..." << std::endl;
  bool running = true;
  while (running) {
    switch (std::cin.get()) {
      case 'q':
        running = false;
    }
  }
  return 0;
}
