# Hey Diary!

Yess, now i'm going to be coding in the right place, making my effects in one blueprint project and adding them to the other.  
I copied the PP_C_Focus project and called it "*EffectDevelopment*". Let's go.  

# Library chaos
I did some things to the CMakeLists to make it work. Ran into an error with csd_lib but fixed it by changing the name of the library stuff. No i didn't, possibly only made it worse. There's a linker error and i'm considering putting everything from library just in the main project so i can use it without a library. I'll ask Daan later in the practicum.  
So just for this week, I'm just gonna paste the things i need into the project from the library.  

Lines i changed for this:  
- "../setting.h" to "setting.h" in audiocomponent.h  
- <> into "" in callback.h  

nope doesn't work, no idea why not pls help. Sent an e-mail to Daan with details, we'll see.  

Daan answered! In the mean time i:  
- Did some self study on how to code an all-pass filter
- Made a first version of a class diagram  

Daan's advice fixed it, just have one csd_lib library (why did i not test this). It still works when applying the <> things.

# Test Waveshaper as Effect

To get familiar with this code project, i'm just going to test it by applying the waveshaper to the sine. Eventually, i'm implementing the waveshaper anyway so this is already a nice step to victory.  

-> put waveshaper into the callback, resulted in feedback (and no sine)  
-> waveShaper was still processing microphone input! (Thanks Midas)  
-> ```waveShaper.processFrame(sine.getSample(), outputSample);``` fixed it.  

**Testing WetDry**
Let me test the drywet of the Waveshaper. In *effect.h*, setDryWet() is a thing, so i'm throwing that into the prepare.  
In the prepare doesn't work, let's try in the process.  
Hmm still not working.  
-> Nvm, it is working but i didn't listen properly.  

Gonna leave the wet-dry ratio for at the end, i'm first focussing on building the actual effects.  
First, i'll make an all-pass filter (because important), i'm making a new Diary entry.
