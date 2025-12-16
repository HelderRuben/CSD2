# Back again with another Assignment!

This time for making different Synths. Things i did:
- Copied everything from 2.3_Inheritance assignment
- Tried to make an organ by adding multiple oscillators in Callback
Couldn't figure out why it wasn't working so i checked the Ciska-code.  
Pretty obvious fix: the sample-values need to be added to each other to make the total value of sample (oscillators combined).  

Still can't quite figure out why the callback doesn't want ```Sine oscName(440, 44100);``` but only accepts ```Sine oscName;```. At first i thought it had something to do with a default constructor missing. So i tried adding a default constructor to Oscillator, but now that i did it i don't understand why because that wouldn't change anything since a default constructor of Oscillator is never called.  
I am deciding now that i'm changing the customCallback part. I'm adding a header and shaping it further to look like the Ciska-code callback. I'm adding comments to understand what's happening.  
Maybe something to do with first putting the oscillator-objects in the private section without any parameters and then initialising them in the Callback constructor?  

I really enjoyed trying to figure out what everything was doing in the callback. I maybe got some comments wrong but I tried.
Just had a fight with the error msg *"member initializer does not name a non-static data member or base class"* . Was annoying but finally figured it out by putting my code next to the Ciska-code.  

# Synth class

Now that i can play with different oscillators and frequency ratios, it's time to make differents Synths. I'm seeing these as a preset of defined oscillators and ratio's to one another (plus waveform).  
