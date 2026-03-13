# Hey Diary!

Alrightt, i have a delay (that was already there but sure)
APF needs a delay, so i'm using that
APF also needs:
- feedback with gain
- feedforward with gain

When using the delay, I do not want to touch the wetdry, bc i want it at 100%. I do want to be able to set the delayamount at a handful of milliseconds.

# Before APF (??? confusion)

No hold on I think i'm wrong again. The effect "delay" is a bit different from a Circular buffer. Before I'm going to work on the APF, i'm going to... (idk)

# Testing CircBuffer

I never tested the circBuffer like actually good, so i'm making sure i understand it better. It feels like i'm going somewhere again. I was confused by delay and circBuffer and if they're interchangable or no, but FOR NOW i'm making the decision that the Delay module and the APF module both have a built in CircBuffer, and that i need to make sure that actually works properly before working on the both of them.

I did some tests with logging things, doing a square wave.
I logged 250 iterations of ticking the square and the circularBuffer, and i don't know why the read and write are constantly at the same positions. There should be a delay.

Oeh-> I notice that in ```setNumDelaySamples()```  of the *delay.cpp*, the readH position is set to ```m_writeH - numDelaySamples + m_size```. I think i forgot that part.

Works now! but when logging the distance between read and write head, it just says "2", which isn't correct.
It's not bothering my code, but maybe something to ask in class or smth.

# How Am I Coding an APF (keep getting stuck)

Okay I'm just wondering if I can duplicate the *delay.h* and *delay.cpp* and add another gain for the signal that isnt delayed, because the signal flowcharts of a delay and a APF are very similar:
- Both are an Effect
- Both use a Circular Buffer for the delay
- Both have a feedback loop

Where an APF is different:
- Feedforward with gain
- Lower delayLength?

# Testing this
I don't actually know the flowchart of the delay in the csd_lib, so that will be helpful to dive in first.
The delay has:
- Length (numDelaySamples)
- Circular Buffer (m_readH/m_writeH)
- Feedback gain (m_feedback)
- Dry/Wet ratio (dryWet)
Seems to me that the delay needs this to become an APF:
- Feedforward path (not in delay)
- Feedforward Gain

I'm just gonna do that aren't i? Let's go
- Duplicated delay code
- Made AllPassFilter an effect
- changed member names
  - NOTE: maxDelaySize has to do with memory and the chosen delayLength not exceeding it

- I'm seeing the APF as if it's having a CircularBuffer already built inside of it.
  - Therefore, in the naming of members and methods, i'm choosing to name them after APF or CB.
- You know, i'm actually going to treat the CircularBufferas a separate thing.::
  - Deleting CB-things from AllPassFilter.h and .cpp
  - I want to make sure everything CB-related goes via the APF

# NOT a good idea
- Running into issues and linker errors, so i'm cancelling my operation because i don't know what's going on
- Just going to copy my code from last commit and continue

# PLAN
1. Copy previous circbuffer
2. compare to AllPassFilter things (what are extra added?)
  - Make list of methods and members that are added
3. Add them to circbuffer
  - Incorporate them
4. circbuffer becomes AllPassFilter
5. TEST it
  - Same method as circbuffer, look at samples
  - TRY TO HEAR SOUND BE DIFFERENT
