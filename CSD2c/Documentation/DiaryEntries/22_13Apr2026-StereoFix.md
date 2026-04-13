# Hey Diary!!!

Trying stereo fix
Trying mapping


## Stereo fix

trying with reverb: YESSSS THAT FIXES EVERYTHINGGGGGGGG
im so happy
trying with phaser: didn't change anything unfortunately, so still need to work on that

## startingFinal mapping
doing all 3 effects
- Mainly focussing on reverb and waveshaper volume- and effectwise, later phaser as well

**REVERB**  
- adding setFeedback to PirkleReverb:
  - added function and variable member
  - fixed some testing errors
  - Works!
+ Volume conclusion Reverb: overall keeps the same exact volume, but due to the feedback it can be a couple dB louder with a continues input
+ Totally fine

**WAVESHAPER**  
- gonna be testing with a linear mapped waveshaperGain to make sure the volume balance stays intact
- testing with waveshaperGain = [0.5, 1]: still too loud when knob = 0
- testing with waveshaperGain = [0.25, 1]: Too little gain when knob = 0
- testing with waveshaperGain = [0.35, 1]: To my ears this feels like a perfect mapping, and visual as well!  
-> Pretty much goldilocks this haha  

**TOGETHER**  
trying these 2 together  
Yes good balance!  
But the reverb doesn't really sound good on the synth, i think its due to the absence of the LPF and BPF from the cSound thing  
(Oh and found out that its not even a pirkle reverb so i changed the name to room reverb)  
