#include <iostream>
#include "callback.h"
#include "allPassFilter.h"
#include <square.h>

#define SAMPLERATE 44100

int main(int argc, char **argv) {
  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource{44100};
  JUCEModule juceModule (audioSource);
  juceModule.init (2, 2);

  AllPassFilter allPassFilter(0.7, 10, 256, 1.0);
  float freq = 882;

  allPassFilter.logAllSettings();

  Square square(freq, SAMPLERATE);

  //TESTING CIRCBUFFER
  float squareSample = 0;
  float outputSample = 0;
  for(int i = 0; i < 250; i++) {
    squareSample = square.getSample();
    allPassFilter.setWriteValue(squareSample);
    // std::cout << "CBRead: " << allPassFilter.getReadValue() << ", squareSample: " << squareSample << "RW = " << RHPosition << "-" << WHPosition << "\n";
    std::cout << "Square: " << squareSample << " | RH: " << allPassFilter.getReadValue() << " | ";
    // allPassFilter.logRWPos();
    allPassFilter.applyEffect(squareSample, outputSample);
    std::cout << " | Outputsample: " << outputSample << "\n";
    square.tick();
  }

  allPassFilter.logAllSettings();
  allPassFilter.logAllValues();
  allPassFilter.logFeedback();

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
