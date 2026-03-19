#include <iostream>
#include "callback.h"
#include "allPassFilter.h"
#include "nestedAPFOne.h"
#include "nestedAPFTwo.h"
#include <square.h>
#include <sine.h>

#define SAMPLERATE 48000

int main(int argc, char **argv) {
  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource{44100};
  JUCEModule juceModule (audioSource);
  juceModule.init (2, 2);

  // NestedAPFTwo allPassFilter{0.6, 4, 512, 0.5, 5, 512, 0.65, 7, 256};
  AllPassFilter testapffB{0.2, 1, 8};
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
    // std::cout << "Impuls: " << impulsSample << " | RH: ";
    // allPassFilter.logReadValues();
    // std::cout << " | ";
    // allPassFilter.logRWPos();
    // allPassFilter.applyEffect(impulsSample, outputSample);
    // std::cout << " | Outputsample: " << outputSample << "\n";
  }
  //ALLPASSFILTER
  // allPassFilter.logAllSettings();
  // allPassFilter.logAllValues();
  // allPassFilter.logFeedback();

  //TESTING FOR BREAKFREQUENCY
  int fBarray[3] = {100, 1000, 10000};
  testapffB.logAllSettings();

  for(int i = 0; i < 3; i++) {
    testapffB.setBreakFrequency(fBarray[i], 48000);
    testapffB.logFeedback();
    testapffB.logAllSettings();
  }



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
