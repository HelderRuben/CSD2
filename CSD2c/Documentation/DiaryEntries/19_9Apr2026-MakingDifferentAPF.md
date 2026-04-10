# Hey diary!

Feels like a loss tbh, but i'm making a different APF class for the phaser. Just a simple APF with 1 sample delay, without using a circular buffer. I saw Vida use it and i fully understand it, but I can't figure out why my own APF (with circbuffer) just doesn't work. **This lets me test if the APF or the Phaser is the issue.**  

# Starting Class

Haven't looked at Vida's code in a while, so i'm first attempting to build the simpleAPF myself!  
- Added simpleAPF.h
- Added simpleAPF.cpp

- No destructor bc its just a calculation

- added formula with LFO Modifier
- added setFeedback

+ don't need samplerate
added if(modifier > -0.1f && modifier < 0.1f) for LFO range failsafe

> Committed simpleAPF

Incorporate in filter:
- Throwing out everything with allPassFilter.h
- array is pointing to apf's now
- For now no feedback

TODO:
- TESTING
- TESTING with feedback
- doing smth with LFO depth?

## testing (phaser class in effectsChain)
this is just boosting the signal.... no IDEA WHY AAAHGHGHGHJGHGJHGJKHGAYYKGDSAKS

im oke

OKay so testing in effectschain instead of phaser class:
- LFO isn't working
+ But i do see dips in freq.

turning LFO into pointer in my class (don't know why i don't do that)
Wait
Is that the reason??????? please tell me i found it out.

***YEEEEEEESSSSS IT WORKS***   
okay im hyped bc this means i can fix the reverb too by doing this probably? maybe? or no well see next entry. 
