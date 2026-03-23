# Hey Diary!

First of all, did some code cleanup bc my head is getting messy.

The setBreakFrequency is also kind of messing with my head and i don't like it. I am planning on just using the formula to calculate good feedbackvalues myself and then using them for the APF.  

# Testing Phaserprinciple in Plugin focus

Testing with a chain of 4 APF's, with 1 sample delay and all different feedbacks. this chain is added to the input again, inverting it in the points where the phase shift is 180º different.  

**A notch appeared!**  

Okay this is good and i'm motivated now let's go.  
Playing with different feedbackvalues:
- (0.25, 0.35, 0.45, 0.55): dip at 10kHz and 20kHz
- (0.15, 0.25, 0.35, 0.45): dip at 9kHz and 18kHz
- (0.01, 0.06, 0.11, 0.16): dip at 6.5kHz and ~16kHz
+ Update: very confused how this works, i need to read some things  
+ Saw Vida increment the APF's by 0.06 each in the chain, so:
- (0.06, 0.12, 0.18, 0.24): dip at 6.5kHz and ~16kHz (???)
+ Testing with 7 APF's (like Vida):
- (0.06, 0.12, 0.18, 0.24, 0.30, 0.36, 0.42): dip at 4.9kHz, 12kHz, 18 kHz
+ Testing with same things but 6 APF's:
- (0.06, 0.12, 0.18, 0.24, 0.30, 0.36): dip at 5.3kHz, 14.5kHz, ~20kHz
+ Testing with different increment values
- (0.08, 0.16, 0.24, 0.32, 0.40, 0.48): dip at 6kHz, 15kHz, 20kHz
- (0.02, 0.04, 0.06, 0.08, 0.1, 0.12): dip at 4.1kHz, 12.5kHz, 18kHz
- (0.002, 0.004, 0.06, 0.008, 0.01, 0.012): dip at 3.6kHz, 11.5kHz, ~18kHz
- (0.000002, 0.000004, 0.00006, 0.000008, 0.00001, 0.000012): dip at 3.6kHz, 11.5kHz, ~18kHz

# Phaser Class

Doing some testing again with the class, this time with 6 different arguments for the APF's.  

Using setFeedback i.o. setBreakFrequency now, so basically setBreakFrequency is for now unused.

Still not working, testing without feedback inside Phaser.
