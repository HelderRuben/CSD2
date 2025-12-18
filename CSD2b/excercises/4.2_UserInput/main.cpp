//Including Things
#include <iostream>
#include "callback.h"
#include "userinput.h"
#include <list>

//Main function when running code
int main() {
    //Not really any idea what this is for
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    //Something with sampleRate and connecting with JUCE things i suppose
    Callback audioSource (44100);
    JUCEModule juceModule (audioSource);
    juceModule.init(1,1);


    //TESTING UI
    //NOTE: I know the questions can be implemented in the functions as well but this is very readable...
      //SYNTH KIND
    // std::cout << "What kinda Synth you want?\n";
    // synthOptions[2] = {"FM", "RM"};
    // chosenSynth = userinput::UIReturnString(synthOptions, 2);
    //
    //   //CARRIERS WAVEFORM
    // std::cout << "What's the Carrier waveform?\n";
    // waveforms[3] = {"sine", "saw", "square"};
    // chosenCarrWaveform = userinput::UIReturnString(waveforms, 3);
    //
    //   //MODULATORS WAVEFORM
    // std::cout << "What's the Modulator waveform?\n";
    // chosenModWaveform = userinput::UIReturnString(waveforms, 3);
    //
    //   //CARRIER-MODULATOR RATIO
    // std::cout << "What's the carrier-modulator ratio?\n";
    // chosenRatio = userinput::UIReturnFloat(1.0f, 5.0f);
    //
    //   //MODULATION AMOUNT
    // std::cout << "How much is the modulation amount?\n";
    // chosenModAmount = userinput::UIReturnFloat(0.0f, 1.0f);


    // std::string boolQuestion = "Is red your favorourite colour? maybeee?";
    // bool test3 = userinput::UIReturnBool(boolQuestion);

    //Letting user know how to quit script
    std::cout << "Press q + Enter to quit..." << std::endl;

    // Q as user input makes script stop running
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        };
    };
    //Stopping script
    return 0;
};
