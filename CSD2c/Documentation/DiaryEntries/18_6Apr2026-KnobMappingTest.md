# Hey Diary!

Taking a break from messing with the phaser bc i don't like him (it's personal now)  
Therefore testing a thing i haven't done anything in: the knob itself!  

# Doing things

- Reading Code and finding parameter
- Reading others code?
- Trying to map it to delay drywet (should be easy)

testing with waveShaper

Saw Midas work with prevParameter, nice and makes sense, implementing

Use processFrame i.o. applyEffect when working with dryWet obviously.  

It works!  

Implementing the mapping i want:
- Waveshaper: knob 0 means d/w 1, knob 1 means d/w 0
- Phaser: knob 0 means d/w 0, knob 0.5 means d/w 1, knob 1 means d/w 0
- Reverb: knob 0 means d/w = 0, knob 1 means d/w = 1  
*(see Mapping.mng in Documentation)*  

Works!  

It may require some testing when I'm fully done with the effects, but for now I can cross this off my list!  
