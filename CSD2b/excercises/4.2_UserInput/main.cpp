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

    // Q as user input makes script stop running
    std::cout << "Press q + Enter to quit..." << std::endl;
    
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
