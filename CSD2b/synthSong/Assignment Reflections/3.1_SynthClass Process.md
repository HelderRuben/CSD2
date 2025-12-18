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
Just had a fight with the error msg *"member initialiser does not name a non-static data member or base class"* . Was annoying but finally figured it out by putting my code next to the Ciska-code.  

# Synth class

Now that i can play with different oscillators and frequency ratios, it's time to make differents Synths. I'm seeing these as a preset of defined oscillators and ratio's to one another (plus waveform).  
I added a synth.h file in which i wrote some things to clarify on what i was doing:
```
//This is synth class.
  //Its divided into 2 different synths:
    //FM
    //RM
  //And it is connected to the melody.
  ////
  //It has oscillators and their ratios,
    // and possibly calculations of these which will be done in the derived classes.
```

# Carrier and Modulator

Since both of my eindopdracht synths require 2 oscillators, i'm going to play with 2. I will name them ```carrierOsc``` and ```modulatorOsc``` just for future planning, but i won't be carrying and modulating yet, just playing simultaneously.  
I just started by writing out synth.h as i would assume it would work (and then the run-into-problems-and-fix-them-routine).  
I added a member function "setRatio" for setting the ratio of the 2 oscillators.  
But that didn't work as  planned.  

# Pointing out the obvious (pointers haha get it)
-> It was at this *point* i started to realise i needed something with pointers to get this to work. Looking at Vida's repo really helped fro this realisation.  
I started looking into things like "new" and "delete", polymorphism(which i learned i already did with Oscillator.calculate) and dynamic memory allocation.  
When i saw Vida's ~Synth destructor mentioning "delete" is when knew i needed pointers.  
So, with the help of sites like w3schools, i started learning about the syntax of pointers, and figuring out how to implement then in my code.  
I added the function Synth::setOscs() to set the oscillators for the synth. This function i can later use in combination with user input and which waveform to set the oscillators to.  
I put some Oscillator* pointers in the synth.h and made them into 2 oscillators in the synth.cpp, and to my surprise it worked! (as in, i didn't get errors).  
I still need to do some things now, like put some important functions in the synth.h. My goal is to make sure only the Synth class is called in the Callback. So I did this with tick(), getSample() and setSamplerate(). I found out i could use the "this->" pointer to be able to connect Synth to the waveform classes.  
Joke's on me i didn't, syntax wasn't ```variable = this->carrierOsc.function()``` but ```variable = carrierOsc->function()``` so that's cool (and also pretty obvious).  

AND IT WORKED, i only put a Synth object in the callback with some testing parameters and i got the right audio.  
