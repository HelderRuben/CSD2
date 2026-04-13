# Hey diary!!!

Finally time to make a reverb class. I'm really focussing today on fixing the pointer thing from earlier ("Has a" relationships are with a pointer, not just inside the class itself...)  
Also doing the stereo fix i think, just duplicating the effects in the effectChain.h bc i suspect it'll maybe fix the clicking. Plus code-cleanup

# FIXING APF's

- changed every apf inside other APF to pointers in the same way as the phaser does with the SimpleAPF
- Testing new things in effectChain.h by getting the thing i wrote in ReverbIReallyLike.txt
- Works but doesn't fix clicks

# PIRKLEREVERB CLASS
I'm basically doing ReverbIReallyLike.txt in a class, without the ability to change anything (YET) in the reverb apart from the dry/wet. Doing that by creating a class for 1 pirkle reverb, and then a class for containing 3 of them with standard values.

- Made reverb class of 1 Pirkle reverb
+ I'm going to be using 3 different sets of values for the 3 pircle reverbs i'm making, I'm doing that by giving the PirkleReverb a valueSet variable, and when that variable is either 0, 1 or 2, it activates the set of one of the three PirkleReverbs in the ReverbIReallyLike
- Made the variable
+ Idea for if i have time: map the volumes of the audio lines to the reverb mapping, so that the room can get bigger.
- Made applyEffect the flowchart with 3 audio lines and gains
- Testing, WORKS!

- Testing the 3 different valueSets in the effectChain.h gives a slowrising feedback, no idea why, didn't do that before
- Fixed it!

# REVERBILIKE CLASS
done with that class, now a simple one making a class of the 3 PirkleReverbs.

- Made class
- Oops nvm, i didn't fix the feedback issue...
- Fixed it but i was wrong all along, there was a mistake in the reverbireally like so i'm not doing that, one PirkleReverb sounds way better than 3 combined.
- DELETING THIS CLASS

# done
i have reverb now but its still weird, doing more on taht later
