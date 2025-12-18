# Adding FM and RM

Next goal in sight! adding FM and RM. I know i kind of skipped implementing the velocity in the note class, but i'm in a physical rush to catch my flight to South Africa, so as disrespectful as it is to say, Note velocity is not my priority right now...  

- Added fm.h and fm.cpp  

FM has the same relationship that the waveform classes have towards oscillator, so i'm copying a lot from that (as in structure wise).  

- Added ```modulate()``` function as virtual
- Deleted synth default Constructor
- Did inheritance things
- Implemented modulate() as part of getSample in synth.cpp
- Added rm.h and rm.cpp (because RM is easier so starting with that)
- Changed synthPtr definitions from Synth class to RM (testing)

Does it work? Yes kinda but stumbling on an annoying error: *"constructor cannot have a return type"*  
I FORGOT A SEMICOLON AT THE END OF THE CLASS OKAYYYYY  
Anyway. Works now.

# RM Calculation

- Added RM calculation to RM::modulate() and parameters (samples)
- Tested and doesnt work(struggled bc didn't notice i was half working in previous assignment...)

Had lots of errors, now everything is in place except i can't hear any soundd....

Nevermind! Forgot to un-comment one line that returns the sample value :D

# FM Coding

I am currently on the train to Schiphol and i thought yea why not try it for the last time.  
Soo here we go, implementing FM.  
I need Phase and Oscillator's got phase, so function getPhase() it is.

 - Added ```float getPhase()``` to Oscillator.
 - Tested if Freqmod could be implemented in ```Freqmod* synthPtr``` (successful)
 - Did FM calculation
 - Changed ```Freqmod* synthPtr``` to ```Synth* synthPtr```, this way pointer points to either Freqmod or Ringmod based on variable ```chosenSynth``` (UserInput)
