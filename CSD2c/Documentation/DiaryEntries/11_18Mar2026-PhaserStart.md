# Hey Diary!

Starting with Phaser and LFO!  
I'll be doing this in the PP Focus first again and then moving things over.  

I don't even know if i will put the LFO as a separate class or incorporated into the phaser.  

# Pirkle on LFO's and Phasers

Things i learned:
- My phaser will have 6 APF's
- Phaser: creating a flanging effect without a delayline
- The notches are related in a complex fashion (not just multiples of each other)
- "A LFO modulates the center frequency of the all-pass filters together, where each APF Fc value modulates between a minimum and maximum value that is established for that stage."
- Very nice but these things i don't really know:
  - What value should the feedbackgain for each APF be for the Fc's of the notches to be at 100Hz, 1kHz and 10kHz?
  - How many samples should the delayLength of each APF be?
  - How much should the LFO modulate the feedbackgain of each APF?
- So it seems i didn't really gain the information i needed
