# Hey Diary!

Yesterday, this was the plan that was formed:
```
# PLAN
1. Copy previous circbuffer
2. compare to AllPassFilter things (what are extra added?)
  - Make list of methods and members that are added
3. Add them to circbuffer
  - Incorporate them
4. circbuffer becomes delay first, then AllPassFilter
5. TEST it
  - Same method as circbuffer, look at samples
  - TRY TO HEAR SOUND BE DIFFERENT

```

I just really want to have that AllPassFilter and i want it TODAY. So I'm just going to follow this plan and have an AllPassFilter finally working. Every step of this plan will be every chapter in this Diary entry.  


# 1. Copy previous CircularBuffer Code
Yes i did that.  

# 2.1 Compare to Delay
Compared first with *delay.h* and *delay.cpp*  

**List of things that are added to make it a delay:**  
- Child class of Effect
- dryWet: Incorporated into Effect class
- applyEffect(): function within Effect class to apply it
- applyEffect Increments RWHeads (dont need tick anymore)
- applyEffect Calculates delaysample
- feedback: feedback of delay
- setFeedback(): setting feedback gain
- Bugfix: setDelayLength sets Rhead correctly
- - Error when delayLength > bufferSize
- - Error when feedback != [0, 1]

# 2.2 Add them to Circular Buffer

**Added**
+ Child class of Effect
+ dryWet: Incorporated into Effect class
  + set delayLength(0) inside constructor
+ applyEffect()
+ feedback member
+ feedback in constructor
+ setFeedback()
+ setDelayLength sets Rhead correctly
+ Error when feedback != [0, 1]

**Removed**
- tick(): heads are incremented by applyEffect
- incrRead() & incrWrite(): heads are incremented by applyEffect
- default constructor

## Testing
added default arguments
solved all small terminal errors
Works!

# 3.1 Compare to AllPassFilter

**List of things that are added to make a delay an APF**  
- Member: feedforwardSample
  - Should be multiplied by feedforward gain and added up to delayed sample
- Member: feedbackSample
  - To add up to feedforwardSample and make it the output
- Calculation:
  - feedforward gain = inverted of feedback gain;
  - feedforwardSample = input * -feedback
  - output: feedforwardSample + delayed sample

# 3.2 Add Them to CircularBuffer
added them tings
added setFeedback(feedback); in constructor

## Testing again
**Looking at the sample-Logs**
Weird thing: after construction: the feedback and delayLength seem to be logged as 0, as if setDelayLength() and setFeedback() didn't work.

What i'm doing for overview: making all the members have a distinct member-name, with "m_" in front. seems nice.
Works now! had something to do with a member being recognised as a non-member i guess.

Do i now have an AllPassFilter????
Hmmm thing I see is the samples having a value between -2 and 3, that should not be possible right? or am i confused and i need to do gainstaging or something.

I'm doing another entry with bugfixing this.
