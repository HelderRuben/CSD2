//Including Things
#include <iostream>
#include "customCallback.h"

//Main function when running code
int main() {
    //Not really any idea what this is for
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    //Something with sampleRate and connecting with JUCE things
    CustomCallback audioSource (44100);
    JUCEModule juceModule (audioSource);
    juceModule.init(1,1);

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
