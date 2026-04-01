# Hey Diary!

Took a break because lack of motivation, but i'm back. Starting with an overview of things that need to happen for me to be done with this block:  

- Doing something with prepare to samplerate things (yes that's a verb)
- Finishing Phaser (making LFO)
- Making Reverb Class
- Mapping one-knob to wet/dry parameters of effects.
- Making LPF and BPF for in Reverb Class

I'm kind of regarding the last one as extra, but i feel like it could be done quite quickly (i hope at least)

# Samplerating the things
*Yes its a verb*  

Uhh I don't think I need it? Not sure actually, I think i'll look into this at the last moments...
Smoothly moving on.  

# REALISATION IN BETWEEN

**Did some spontaneous testing on the reverb, and made the following conclusion about the weird smeary clicky sound:**  
1. It happens more in low frequencies than in high
2. On C and F notes, it doesn't happen!
3. The notes around C and F sound really smeary and clicky

**It's like something is interfering. This makes me happy because it means it's probably not an interpolation thing, so in code cleanup later i can remove that.**  

***I have to look into this more later, maybe do some frequency calculations and look in detail what happens with the APF-values in the module and if it influences these frequencies.***  

# Adding LFO

First quick test if Phaser does nice things:
- Okay it gives peaks instead of dips and i don't know why.
- It's very weird, if i use the phaser class it does peaks, if i use 5 APF's in chain (with same values as the class) it does dips.
- It shouldn't be the applyEffect difference with ProcessFrame  
- Leaving this for now, adding LFO first:

1. Add Sine as LFO inside Phaser with frequency and samplerate
2. Let LFO tick inside applyEffect()
3. Add processFrame with 3 arguments inside APF, for modulating them with the LFOSample

- Changing the name "LFOSample" to "LFOModifier", because the sample gets scaled to range [-0.1, 0.1]  
- Removing cubic interpolation from APF  
- LFOModifier modulates APF's "m_feedback", so m_feedback = (m_feedback + LFOModifier) everywhere where m_feedback is used
- Woops, had to do processFrame with 3 arguments as well, altering effect.cpp...  
  - I feel like there is a much cleaner way to do this
- Nope i need to fix it now bc its getting messy
- Fixed it: phaser doesn't need to "processFrame" the APF's, only "applyEffect" them

**Testing**  
Very weird. It is modulating at 0.5Hz so the LFO itself works, but its modulating the gain. So currently, i have a tremelo with a messed frequency response instead of a phaser.  

**Testing without class**  
As mentioned previously, the class does something weird anyway and i don't know what.
So i'm testing it first in the EffectsChain.h.  

- didn't get the lfo to work, so i'm trying to improve the phaser class

- Why is my phaser boosting peaks with even multiple-amounts of ~1kHz?  
  - Better question, why does "*output = apf6output * 0.5 + input * 0.5*" not even influence
- More APS's give more gain (why?)  
- Giving the phaser a feedback higher than 0.0 CRASHES the sounds(why?)

- Trying apfArray with pointers like Vida did
--> Crashes immediately after plugin is opened... So mission abort

- The increment amount doesn't influence the peaks that the phaser is giving  
- Don't know what to do, if this continues like this i may just copy Vida's code into my design honestly
