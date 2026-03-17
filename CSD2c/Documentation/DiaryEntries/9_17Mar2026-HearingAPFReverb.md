# Hey Diary!

The next steps i'm taking are these (i think):  
- Reading Pirkle on APF's (just for understanding and final FINAL check as well)
- Putting the APF as an effect on the chain and playing with the plugin in Ableton
- Making a Reverb Class with a chain of APF's inside
+ Optional step: Improve class diagram and commit the different versions

# Pirkle takeaways

**Reading and skipping through chapter 17: Reverb Effects**

- Nested APF's are way easier than i thought!
  - I think I got enough strength today to make a nested APF with one APF, and one with 2 in series nested.
  - This will be a step very close to the direction of making a room reverb.  

# APF on EffectChain

- copied AllPassFilter into Plugin focus
- Made plugin out of 1 AllPassFilter
Messing around with different things:  
```AllPassFilter allPassFilter{0.3, 20, 512, 0.85};```
- Feels like some overdrive things are happening? seeing a comb-filter-like pattern in high frequencies, i presume it is because some frequencies are boosted and others cancelled out.  
```
AllPassFilter apf1{0.3, 1, 512, 0.85};
AllPassFilter apf2{0.25, 2, 512, 0.85};
AllPassFilter apf3{0.35, 1, 512, 0.85};
AllPassFilter apf4{0.4, 1, 512, 0.85};
AllPassFilter apf5{0.2, 3, 512, 0.85};```
- Feels like the normal sample, but then with a high buzzing added
- Also noticed the gain goes down (bc of the makeUpGain), so i'm tuning that up as well  
```
AllPassFilter apf1{0.15, 1680, 2048, 0.95};
AllPassFilter apf2{0.25, 1056, 2048, 0.95};
AllPassFilter apf3{0.3, 398, 512, 0.95};
AllPassFilter apf4{0.08, 3168, 4096, 0.95};
AllPassFilter apf5{0.3, 1440, 2048, 0.95};```
+ These are the values that cSound used in a small room reverb, but without nested APF's and filters. I'm expecting too much high-end here
- Wasn't even too bad! I'm definitely getting somewhere. It is heavily smearing out the sound across time, feels a bit slow-motion-like. The low-end feels really weird, a bass drum just turns into a weird smeared buzz in the low frequencies. But i do see how this phase-delay thing can simulate a room.
- I'm happy with the makeUpGain at 0.95  
```
AllPassFilter apf1{0.15, 1680, 2048, 0.95};
AllPassFilter apf2{0.25, 1056, 2048, 0.95};
AllPassFilter apf3{0.3, 398, 512, 0.95};
AllPassFilter apf4{0.08, 3168, 4096, 0.95};
AllPassFilter apf5{0.3, 1440, 2048, 0.95};
AllPassFilter apf6{0.12, 1954, 2048, 0.95};
AllPassFilter apf7{0.29, 1301, 2048, 0.95};
AllPassFilter apf8{0.28, 416, 512, 0.95};
AllPassFilter apf9{0.11, 3647, 4096, 0.95};
AllPassFilter apf10{0.23, 1835, 2048, 0.95};```
- This is so cool! it feels very clean in the high end. I can see this diffusing the signal and then being delayed to make a long-lasting reverb.  
- Once again, it is weird in the low-end but sure

# Nested APF

After reading some Pirkle, i'm actually quite excited to make a nested APF.
doing that:
- returning to PP focus
- changed AllPassFilter to put makeUpGain at standard 0.97 (no 4th argument)
- Added setSize()
- copying allPassFilter class
- linked every member etc.
  - Also made sure APFInsideThisOne logs his stuff when NestedAPFOne does
- did this:
```
const auto inputPlusFeedback = m_feedbackSample * m_feedback + input;
float NestedAPFOutput = 0.0f;
APFInsideThisOne.applyEffect(inputPlusFeedback, NestedAPFOutput);
m_buffer[m_WHPosition++] = NestedAPFOutput;
```

## Testing Logs

- Made allocate and release buffer public so nested can use it
- added logReadValues() so both ReadValues can be logged
- Tested with logging all values and things an everything:
Works!  

- Committing and
- Moving everything to Plugin focus

## Testing Sound

did this:  
```
NestedAPFOne apf1{0.15, 1680, 2048, 0.25, 1056, 2048};
AllPassFilter apf2{0.3, 398, 512};
NestedAPFOne apf3{0.08, 3168, 4096, 0.3, 1440, 2048};
```
(kind of almost based on cSound book, but don't have a double nested APF yet)  
- Works nice! sounds like smearing a lot of frames
-> Next step is double nested APF

# Double nested AllPassFilter
Description: not like a nestedapf inside a nested one, but 1 nested APF with 2 APF's in series inside it (based on what Pirkle said in the room reverberators)

First inside PP Focus:
- copying NestedAPFOne things
- duplicated every APFInsideThisOne things
- added step in applyEffect(), including the second APF:  
```
float NestedAPF1Output = 0.0f;
float NestedAPF2Output = 0.0f;
APFInsideThisOne.applyEffect(inputPlusFeedback, NestedAPF1Output);
APFInsideThisTwo.applyEffect(NestedAPF1Output, NestedAPF2Output);
m_buffer[m_WHPosition++] = NestedAPF2Output;
```

# Testing Logs
Works

# Testing Sound

- moving NestedAPFTwo to Plugin Focus
- Making the large room reverberator APF chain:
  - APF{0.3, 384}
  - APF{0.3, 576}
  - NAPF1{0.5, 4176, 0.25, 2976}
  - NAPF2{0.5, 5760, 0.25, 3648, 0.25, 1440}
- Like this:
```
AllPassFilter apf1{0.3, 384, 512};
AllPassFilter apf2{0.3, 576, 600};
NestedAPFOne apf3{
  0.5, 4176, 4200,
  0.25, 2976, 3000};
NestedAPFTwo apf4{
  0.5, 5760, 5800,
  0.25, 3648, 3700,
  0.25, 1440, 1500
};
```
- I mean, it sounds kind of like a large room, in the sense that you can pretty much hear the individual delays, but it sounds robotic
- Trying something else:
```
AllPassFilter apf1{0.15, 4, 10};
AllPassFilter apf2{0.05, 7, 16};
AllPassFilter apf3{0.4, 384, 512};
AllPassFilter apf4{0.3, 576, 600};
NestedAPFOne apf5{
  0.2, 3487, 4200,
  0.15, 2976, 3000
};
NestedAPFTwo apf6{
  0.3, 3857, 4000,
  0.15, 3648, 3700,
  0.25, 1440, 1500
};
NestedAPFOne apf7{
  0.24, 1749, 1800,
  0.15, 327, 350
};
NestedAPFOne apf8{
  0.4, 2758, 2800,
  0.3, 499, 510
};
```
- Sounds alright i guess
- Trying with very small values compared to these:
```
AllPassFilter apf1{0.45, 4, 10};
AllPassFilter apf2{0.35, 7, 16};
AllPassFilter apf3{0.40, 5, 8};
AllPassFilter apf4{0.34, 11, 16};
NestedAPFOne apf5{
  0.25, 14, 16,
  0.1, 3, 8
};
NestedAPFTwo apf6{
  0.65, 31, 36,
  0.15, 13, 16,
  0.23, 9, 12
};
NestedAPFOne apf7{
  0.76, 53, 64,
  0.15, 27, 32
};
NestedAPFOne apf8{
  0.4, 43, 50,
  0.3, 23, 32
};
```
- Sound diffuse! But very delayed from the original sample, like a diffuse echo more than a reverb.
- Testing with doing the thing that Pirkle does in his diagram. By adding variables to make the lines with different gains coming from the different points in the APF-chain. Also added the feedback sample (but without the Band-pass):
```
apf1.processFrame(inputChannel[sample] + feedbackSample, apf1output);
apf2.processFrame(apf1output, apf2output);
lineOne = apf2output * 1.5;
apf3.processFrame(apf2output, apf3output);
lineTwo = apf3output * 0.8;
apf4.processFrame(apf3output, apf4output);
lineThree = apf4output * 0.8;
feedbackSample = apf4output * 0.25;
outputSample = lineOne + lineTwo + lineThree;
outputChannel[sample] = outputSample * 0.8;
```
- It just doesn't really sound right yet
  - I'm suspecting the "inputPlusFeedback" thing in the applyEffect of the AllPassFilter is not very cooperative. I see that both cSound AND Pirkle do not include the inputPlusFeedback into the feedforward.
  - Removing that
- Also:
  - Just found https://www.eumus.edu.uy/eme/ensenanza/electivas/csound/materiales/book_chapters/24mikelson/24mikelson.html, and it is mentioned that the overarching delay is the SUM of the delay in the APF AND that of the nested APF. so i'm doing some math to get the timings right:
```
AllPassFilter apf1{0.3, 384, 512};
AllPassFilter apf2{0.3, 576, 600};
NestedAPFOne apf3{
  0.5, 1200, 1250,
  0.25, 2976, 3000};
NestedAPFTwo apf4{
  0.5, 672, 5800,
  0.25, 3648, 3700,
  0.25, 1440, 1500
};
```
- It does sound pretty good, but the lower the frequencies, the more phasing-combfiltery sound it produces, don't really know why.

I'm committing this and trying another approach: a Diffuser + a Delay instead of letting every APF decide the reverb.
