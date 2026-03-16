# Hey Diary!

Back again with the AllPassFilter, should be almost finished. have a lesson today and i'm for sure going to ask some useful questions  

**For in lesson**  
- advice on class diagram and circular buffer
- Questions about working of AllPassFilter  

# For now: testing AllPassFilter

still on the train, so have some time for testing things:  

testing different formula for feedforwardSample:  
```m_feedforwardSample = input * (1 - m_feedback);```  

Don't know if this is correct, but it feels good i guess.  

Nvm, the same exact sample-values are concluded.  

# In Class (school class not object in c++)

**TakeAways:**

- Prepare  
Everything that needs samplerate has to be prepared (setting the samplerate correctly)  

- Positive G and Negative G  
(G here is the feedback gain)
The G should be negative inside the feedbackloop, and positive inside the feedforward-line.  

- Better Block Diagram  
the feedforward-line should come from the input instantly instead of behind the feedback.  

- Vida Mail  
Read this!!  

- Ciska mail  
Values specifically for a room reverb. Page 486 Csound: every line is an APF (nested) with delaytimes in MS and G in [0, 1].
  - It's okay for now to not know what values are best for what reasons.  

- Need to do something with a gain after the APF so the signal doesn't clip. Sample goes out of [-1, 1].  

**Implementing the takeaways**

- Made it so the feedback is set to the negative of the constructor initiater-value, therefore a positive value is expected as feedback when constructing the APF.  
- Improved the block diagrams and committed them. I didn't improve the nested small ones in the chain bc that's kind of just for show :)  
- read some important parts
- Made screenshots of cSound chapter about reverberators
- Different values that are nice for a room reverb:
  - For delayLength (feedback g):
    + 1680 (0.15)
      + 1056 (0.25)
      + 398 (0.3)
    + 3168 (0.08)
      + 1440 (0.3)
    - NOTE: The overarching APF's seem to have a lower g and higher sampleAmount then the APF's inside of them
  - NOTE: seeing this graph and seeing how random the signal flow can be, this is what i can maybe do in the Reverb Effect when i am building the applyEffect(). BUT only if i have the time, i'm starting with
- Experimenting with gain:

## Gain after the APF

Because of outputvalues still going beyond [-1, 1], i'm doing some testing.
seems like with a sine, there isn't much going over [-1, 1], except at a very small sample value.

## Fixing the blockdiagram (again)

When testing in the practicum, i corrected the code so that the feedforward IS conected to after the plus, including the feedbacksample inside of the feedforward.

It does not seem to fix the issue with a square wave, but with a sine wave it is fixed! (also with different feedback-values) I am going to keep the makeUpGain for if i need it in the future.

When testing different sampleAmount values i did notice that for a sinewave its not fixed entirely, because if the sampleAmount is roughly the amount of samples in 1 freq-wave, it is boosted high enough to reach around 1.04 and -1.04. Don't know how to fix that, maybe i'll just make a small gain-adjustment at the end. For now i'll put the makeUpGain at 0.9.  

I'll have to check Pirkle when working on this again i guess

## Moving to Plugin Focus

Just realised it doesn't really do alot if i test the sound with a sine, because a sine is 1 frequency and the APF changes the phase along the frequency SPECTRUM, so yea. I think i'll just try to incorporate the APF into the plugin focus, and then test out the plugin. Plan:  
- Commit before doing all This
- Put the allPassFilter header and cpp into the csd_lib
- Implement it in the plugin focus

**Doing that**  
Linker error, great  

**Not doing that**  
Nevermind, not even a logical decision because not part of csd_lib.  

# Clean-up

Did code clean-up.
- Gonna keep the outcommented code which i was testing with (in the main and callback) bc it was very useful.
- Removed dryWet from AllPassFilter bc its only gonna be at 1.0 always.  
- Improved logFeedback bc it was giving the negative.
- made makeUpGain the fourth argument for AllPassFilter
- improved over-all readability
