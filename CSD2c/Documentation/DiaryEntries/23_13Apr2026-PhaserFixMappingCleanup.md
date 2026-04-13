# Hey Diary!!

AlrighTTTTT lets fix this phaser
takeaway from practicumles: do the pirkle formula for the values for the apf

## Formula
Formula:  
a = (tan(π * (breakFreq/samplerate)) - 1)  /  (tan(π * (breakFreq/samplerate)) + 1)

Pirkle also gives values for the frequencies the LFO should move between
1. 16 Hz - 1.6 kHz
2. 33 Hz - 3.3 kHz
3. 48 Hz - 4.8 kHz
4. 98 Hz - 9.8 kHz
5. 160 Hz - 16 kHz
6. 260 Hz - 26 kHz  

Using the formula to find the coefficient values:
1. -0.997908 - -0.809784
2. -0.995690 - -0.640142
3. -0.993737 - -0.509525
4. -0.987253 - -0.144993
5. -0.979272 - 0.267949
6. -0.966532 - 1.303225  

The last one is above 1 because it goes beyond the Nyquist. Don't really know what to do with this tbh, but i'll test it i guess  

result with first set of values: crash
result with second set of values: some dips across

Testing with more values:
1. 160 Hz -> a = -0.979272
2. 330 Hz -> a = -0.957710
3. 480 Hz -> a = -0.939063
4. 980 Hz -> a = -0.879295
5. 1600 Hz -> a = -0.809784
6. 2600 Hz -> a = -0.706730

Result: 3 dips

uhhh okay so i just tested some values
and doing number 6 (-0.706730) for each of the apf's seems to work very finely
So i'm happy with that hahahaha.

## Double phaser

okay but i kind of want to try the double phaser now, sounds easy.  
stereo phaser: the channels have a 0.5 oscillation-phase difference  

doing that with LFODirection variable  
Very easy, just a 1 or -1 with the LFO sample. Works!  
Sounds way more stereo now, which is pretty nice.  

# Mapping
Doing the mapping as well!

# Phaser mapping

did some tests with phaser mapping when it comes to:
- Drywet
- LFOSpeed
- LFODepth
- Feedback
looks good sounds good is good

# Final Mapping

- Testing with the 3 effects
- changed waveshaper mapping (less)
- added in effect.cpp: ```if(dryWet < 0) {dryWet = 0};```
- Waveshaper gain was wrong, fixed it so its better  

Testing volume compensation (trial and error)  
Finished!
committing this and then moving on to final code cleanup.  

# Cleanup

- did float prevParameter = 0.1f; so that plugin starts active
- allPassFilter: removed lfomod thing
- allPassFilter: removed comments and unused code
- allPassFilter: removed m_makeUpGain
- nope nvm did not remove m_makeUpGain
- NestedAPF's: moved buffer methods to public so "nestedception" is possible
- RoomReverb: removed valuesets, only one now
- Deleted outcommented code, unused things, corrected spacings and stuff
+ Changed plugineditor for fun (:  
