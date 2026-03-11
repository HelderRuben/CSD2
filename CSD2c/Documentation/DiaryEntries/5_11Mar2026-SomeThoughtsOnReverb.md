# Hey Diary!

Just watched this video: https://www.youtube.com/watch?v=XLyrEKX4Q2g  

It was an amazing video on how to make a reverb with a series of AllPass-Filters (in Max for Live)  

# Video Takeaways

There were some interesting takeaways i realised that i could use:
- Schroeder (AllPassFilter guy) suggested that around 5 APF's would be optimal for creating a reverb that sounded like a room
  - Because it's not too metallic
  - And doesn't swell up after the sound (unnaturally weird/large)  
- The delay time of each APF is pretty good around 30 ms
- The delay time of each APF should vary from one another, in a way that they don't create boosted delayed signals because they're (too) synchronised
- I should really test a lot with the delay time, amount of APF's, and feedback. To get a close approximation of a reverb that sounds like a room and actually sounds nice (i mean i like metallic but it's not that satisfying as a smooth room reverb)

# Reverb Thoughts

Some thoughts about the reverb i'm building
- I'm excited like actually (and motivated even)
- I was wondering how i should do the chain of APF's:
  - A class "APFChain" ?
  - A for-loop
- -> The for-loop would be pretty cool i think
- I think *float processAPFChain(int APFAmount, float feedback, int SampleDelayAmount)* (or smth) is gonna be a member of the Reverb class. It would have:
  - A for-loop with amount of APF's
  - One APF is applied to one sample each iteration
  - But then also changing the delaytime each iteration
    - Maybe there's an array with delayTimeValues, and every iteration the APF is getting the next delaytime out of that array
  - The output is a sample that went through the all-passfilter 5 times

**You know**, in my head this works and saves time.
Because then i don't have to create 5 APF's with all different times and things, and then let the sample go through those one by one (probably in a for-loop anyway but still).  

**It is gonna** be interesting to see how the delay after the APF-Chain is going to work, because in the video (in Max) there's no sign of doing a delay after the chain, so that makes me wonder if I even need one.
Therefore another takeaway:
- First make sure the APF-chain is working (and tested) before moving on to making that signal be delayed by another feedbackloop.  

**I'm really interested** to see if i can get the Nested APF to work as well, and then a chain of those. I'm purposefully postponing that for later, because i don't want to be thinking about that right now, i haven't made an APF yet.

# End of Entry

This was nice jotting down my thoughts and having an overview on how I'm doing the reverb in the future. Definitely going to visit this Entry later on and look at advice from past me.
