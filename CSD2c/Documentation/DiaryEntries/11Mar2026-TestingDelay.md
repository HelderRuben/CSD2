# Hey Diary!

Today, I want to make sure the Circular Buffer is working as intended, so that I can use it in later effect-building. I'll be looking at main.cpp and see to implement the buffer.  

**Logging**  
I saw some debug methods in the Ciska-code, I'm just going to copy them into my project so that i can use them as well.  
Just for my overview, this is for:
- Logging the positions of the heads
- Logging the delayLength(distanceRW)
- Logging the buffer size
- Logging all of the above
- Logging all the values in the buffer
I've changed the members so they fit my project.  

# Inside Main.cpp

Reading the Ciska-Code, i don't fully understand the reason for the choices made. I see that a freq of 882 Hz with a sampleRate of 44100 creates a full cycle in 50 samples (44100/882), but what is the reason for the delay being set to about a quarter of one cycle? Is that just optimal or am I overthinking?  

Anyway, this is things i'm doing:  
- Including circularBuffer
- Creating the buffer (size and delayLength)
- making float freq
- ```#define SAMPLERATE 44100```
- loging all settings
- include square and make square

# Okay hold on

I just found out that a delay IS a circular buffer and that it's already in the cds_lib. In my mind the delay was something that was USING the Circular Buffer class. But now i see that it's already in the delayclass itself.
Okay but i can learn from this though. The Circular Buffer class which i'm currently building, i can change to a delay class. I know it's already in the library, but reading and copying every bit of code teaches me a lot (even though it takes time). Plus, i'd like to use my own names for methods and members and stuff.

# Testing the Delay (as a plugin)

First, i'd like to test the delay module itself (just from the csd_lib.  
So i'm doing this by:
- ```#include <delay.h>``` delay included
- ```Delay delay;``` creating a delay class
- ```delay.processFrame(sine.getSample(), outputSample);``` Processing the delay, which applies the effect and gets the "delayed sample"  

I was weirded out by the fact that the feedback and numDelaySamples isn't instantly set to the correct value in the constructor, but to zero. Now i read the code and understand that there's more to do with those members, and validating them because the buffersize is ofcourse dynamic.  

Testing this is EffectChainKnob project for making the plugin.

-> Delay wasn't working because this:  
```delay.processFrame(inputChannel[sample], outputChannel[sample]);```  
should be this:  
```delay[channel].processFrame(inputChannel[sample], outputChannel[sample]);```

Breaking that down:
- delay[channel] -> The delay has 2 channels, left and right (also with ```Delay delay[2]``` in the *private:*)  
- ```.processFrame(outputSample1, outputSample2)```-> with outputSample1 and outputSample2 defined in the *getNextBlock()*  
- ```outputChannel[sample] = outputsample2;``` -> It should follow up on the sample that the delay changed, not the sample that was just the input to begin with.  
- In the *applyeffect()* of the *delay.cpp*, the output sample is:
  - defined by the sample under the readHead,
  - multiplied by the feedback,
  - and added up to the input sample.

Okay don't know what i did wrong, but opening the plugin in Ableton now crashes Ableton. Which is quite cool but not ideal to be honest.

# Testing the Delay AND WaveShaper (as a plugin)

Just noticed that
```for(int channel = 0; channel < buffer.getNumChannels(); ++channel){  
    auto* inputChannel = buffer.getReadPointer(channel);  
    auto* outputChannel = buffer.getWritePointer(channel);  
    for (int sample = 0; sample < buffer.getNumSamples();   ++sample){```
is already working with a buffer. I should read more code. Makes kindof sense now: the waveshaper and the delay both process a frame and output a sample. It makes a chain by going from **inputsample -> outputSample1 -> outputSample2** and then outputting it.  
Doing that now, so testing with waveshaper AND delay in chain.  

Great that works! Committing this as effectChain test that works as a plugin!  

# Afterthoughts or smth

Okay i know how the delay.h and delay.cpp work now, i'm not gonna manually copy them over into the Circular Buffer i was making, i'm just going to use the delay when building the ALLPASSFILTERRR.  
So going to be working on that now, deserves a new Diary Entry.  
