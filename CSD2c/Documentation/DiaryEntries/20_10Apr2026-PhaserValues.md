# Hey Diary!

Now that the phaser works, i need to calibrate it to have nice values for all parameters. Something else i need to do is make the phaser Feedback and LFO Frequency and Depth changeable. But thats details, first the values and then i think i'm making another entry on correcting the reverb!

# Testing Values

- Cleaned up the entire mess of the effectChain.h, very satisfying

**Way to do testing:**  
Mapping the testvalue to the knob and testing which value would be good.

## Mapping LFOSpeed to knob & Testing

doing LFO->setFrequency(LFOSpeed); crashes it, no idea why.
nevermind, tried to do setFrequency before making the LFO haha, works Now  
**Conclusion**  
***I would like to map the possible LFOSpeed range to [0.1Hz, 3.5Hz]***  

## Mapping LFODepth to knob & Testing

**Conclusion**  
***I would like to map the possible LFODepth range to [0.04, 0.14]***  

## Why APF weird?

When i'm trying the normal Ableton phaser, it phaser the entire frequency spectrum. So i'm still very confused about why the phaser only works in the high end. I mean it sounds good, so for now i'm not really complaining.  
**I'll get back to this when i'm in the "mixing" stage.** 
