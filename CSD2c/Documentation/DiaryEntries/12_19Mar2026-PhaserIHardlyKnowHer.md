# Hey Diary!

Today i'm planning on FINISHING the phaser. maybe it doesn't go to plan but i'm curous to see how far i can get.
I'm starting with answering the questions i got last entry:  
- What value should the feedbackgain for each APF be for the Fc's of the notches to be at 100Hz, 1kHz and 10kHz?
- How many samples should the delayLength of each APF be?
- How much should the LFO modulate the feedbackgain of each APF?  

# setBreakFrequency

I saw this in Vida-code and thought it was a nice idea, this way i can put in the breakfrequency and the formula will just calculate the coefficient. Don't know why i didn't just look up the formula, I'm seeing my lack of selfstudy again but i don't really have the time for it unfortunately.  

Watched this WolfSound video to understand the formula:  
https://www.youtube.com/watch?v=AKMoKWYGe8I  

The Formula:  

**Coefficient = (tan(PI * fB/fS) - 1)/(tan(PI * fB/fS) + 1)**

With:
**fB = breakFrequency (reaches 90º phase rotation)**
**fS = sampleRate**

# Implementing
I'm working in the pp focus for now bc i want to test it.
I also want to test it in light of these differences:
```const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;```
```m_buffer[m_WHPosition++] = inputPlusFeedback;```
```wrapHead(m_WHPosition);```
```m_feedforwardSample = inputPlusFeedback * -m_feedback;```

and  
```m_buffer[m_WHPosition++] = m_feedbackSample * m_feedback + input;```
```wrapHead(m_WHPosition);```
```m_feedforwardSample = input * -m_feedback;```

- Added setBreakFrequency() for calculating the coefficient
- Did testing with logging the feedback after setting the breakFrequency
- Works!  

I'm already deciding:  
**FIRST PLUGIN FOCUS COMMIT IS GONNA BE: "added setBreakFrequency, LFO and Phaser"**

# PhaserChain

I'm kind of creating thoughts in my head how the phaser should work:
- Has 6 APF's
- Has LFO influencing apfx.setBreakFrequency()
- An LFO-variable inside the setBreakFrequency() in AllPassFilter should be there to influence the formula
  - Vida does this as well and it's purely logical
- **Every 2 LFO's should have the same breakFrequency, because then the total phase response on the fB goes from 90º to 180º, cancelling out the sound there**  

I'm gonna start buidling the Phaser class, and as i go i'll figure out how i want to LFO to be incorporated. For now, lets make a chain of 6 APF's with the right breakFrequencies.

# Building Phaser Class

This is going well! Added:
- initialiser list
- APF-array
- fB-array
- setFeedback
- setLFOSpeed
- setLFODepth

Testing all these things
This all pretty much works, but i did found out things..

# How To Phaser

**TWO THINGS**

1. Okay so the notches aren't in pairs of APF's, then you get pretty strong resonances. I should think of this more in the sense of the entire frequency spectrum. this way the notches aren't really that steep but more smooth.  
2. The feedback values (in pairs) that are coming back are: 0.986995, 0.876976, 0.131653, according to 100, 1000, and 10000.
By doing some math myself i did figure out that this is correct for the formula, so the code works.

## Quickly testing this in Plugin focus

first making the applyEffet():  
```apf1.processFrame(input + feedbackSample, apf1output);```
```apf2.processFrame(apf1output, apf2output);```
```apf3.processFrame(apf2output, apf3output);```
```apf4.processFrame(apf3output, apf4output);```
```apf5.processFrame(apf4output, apf5output);```
```apf6.processFrame(apf5output, apf6output);```
```feedbackSample = apf6output * m_feedback;```
```output = apf6output * 0.5 + input * 0.5;```

Moving to plugin focus  
- Uhm i'm very happy i did this in ableton and not with the standalone bc the the gain goes REAAAAALLY red high.

Gonna test where the error is.
