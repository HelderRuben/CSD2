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

# Calculation

- Added RM calculation to RM::modulate() and parameters (samples)
- Tested and doesnt work(struggled bc didn't notice i was half working in previous assignment...)

Had lots of errors, now everything is in place except i can't hear any soundd....
