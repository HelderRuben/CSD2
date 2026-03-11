# Hey Diary!

Heloooo I'm doing this again, writing everything I do or am gonna do step by step. Just for my own process, to:
- Make sure i'm focused on one thing at a time
- Be able to read back things I maybe missed earlier
- Learn from mistakes by processing in a fun and active way

# Lots of Things to dooooo

Today in the lessons I truly found out there is a LOT of work to be done, but i'm just gonna do it. I have lots of other school assignments which I am also doing and it's (again) my own fault that I didn't start earlier, but I have more hope now because:
- No more social media
- Sleep well
- Less of optional things in my free time
- Motivated to actually do things

# Coding Start
## GOAL: WORKING PLUGIN WITH WAVESHAPER

Today I finally got the OneKnob blueprint working in Ableton, it didn't seem to be included first when rescanning for plug-ins. Next step: copying the blueprint and messing with it.
Since I am going to be including a WaveShaper into my Effects-chain anyway, lets add it:
I notice that it's pretty hard to start this for me, because I don't really know where to start, and my syntax-knowledge is not up to date.
Error when trying to add WaveShaper into EffectsChain:
```reference to non-static member function must be called; did you mean to call it with no arguments?```
Annoying error, why is **"WaveShaper.applyEffect(inputChannel[sample], outputChannel[sample]);"** a problem being in the EffectsChain header?
Okay that's fixed, was a syntax bug.
I now have a plugin working with a waveshaper, so that's good.
Did some testing with how to test this in Ableton, I think i'm just going to put an oscillator on it, next step:

## Being confused
**Next day, 10 Mar 2026**  
*Status: I'm confused*  

I'm having some trouble, because i'm kind of getting thrown in some code I don't know the structure of. For instance, am I using the EffectsChain.h as a 'main' thing like last time? I assume so, because that's where the effects are chained together. But i'm having trouble understanding where my code goes. I feel like I just need someone to explain quickly where what kind of code goes (bc it feels like unfamiliar terrain) and then I can go all in.  
Another thing i'm a bit confused about: how do I test things? Do I just keep refreshing the updates audiocomponent in Ableton and close/open Ableton afterwards? It feels like this can be done more efficiently.  

Quick overview of the questions I want answered:  
- Where is the main place I can implement effects? (i probably know this one already but still)
- Where can I add an oscillator?
- How can I then make sure the oscillator runs in the terminal? (what executable?)
- Where can I map the knob to an effect?

## Asking Ciska some Questions
Today after the coding clinic I had 5 minutes with Ciska to ask these questions and it really helped.
Processing this valuable (basic) information:
- Build the effects in the other blueprint (PP_C_Focus)
- If they're done, paste them into the Plugin_Focus
- ```void getNextBlock``` in *EffectsChain.h* is kind of the callback
- ```void setParameter``` in *EffectsChain.h* is where to map the effects to the knob
- PluginEditor is how the plugin gets made and how it looks like
- PP_C_Focus has an OSC_Server which can be easily connected to Max (see the *simple_python_client.py* for the address)
- Use WRITE_TO_FILE_MODE in *settings.h* to test code in different ways
This was really helpful, i'll end this entry here and start working in the PP_C_Focus.
