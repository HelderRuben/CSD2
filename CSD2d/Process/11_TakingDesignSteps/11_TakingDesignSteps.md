# DESIGN THINGS

I'm excited when it comes to my creative proces and documenting it. For the past few weeks, it has been a project that's on my mind A LOT, especially in small moments like at a bus stop or just throughout the day. **In this md, I'm documenting what I've been thinking about when it comes to the design and functionality of the LEGO sequencer.**  
These are the subjects!:  
- Glitch Figurine
- Figurine Visual Presentation
- Functional On/Off button
- Extra Ideas
- Visual Configuration of the Total Picture


# 1: Glitch Figurine
I was really pleased with 3 FX figurines I arleady had: Beast, Diver and Astronaut  
Some early concepts for a 4th one were: History (knight or soldier), Rockstar, and Glitch:  
- History would have some tape emulator and noise stuff
- Rockstar would have some saturation and/or (multiband)compression
- Glitch would have some kind of phaser in combination with (multiband)compression  
Then I found an interesting LEGO figurine on the King's Day Market and I wanted to use it, It looks like this: *11.1*.  
I was planning on doing some kind of stereo effect with it, but didn't know what yet. More on that in chapter 4.  

# 2: Figurine Visual Presentation
Instead of just putting the figurines on top of the build, i had the idea of making a little chamber for them. An environment. It's also just practical, they can easily fall off the build, and the build not being flat is not helping either. See *11.2.1* for the first building test. The chamber looked pretty dark, so an LED would be great. Look at *11.2.2* for the final result.  

# 3: Functional On/Off button
Small idea but practical one. I bought a nice on/off button that lights up when On. At first I thought I could just put every processing code inside an if-statement, so when the switch is On, the machine works. But i've chosen to do it in a more sophisticated way:
- bought a 30cm micro USB extension cord
- going to cut it open and connect the red power-cable to the on/off switch
This way, the switch actually decides the Daisy getting power and turning on.

# 4: Extra Ideas
These are the extra ideas that have been forming in my mind, and that i wrote down somewhere to think about. They are things that are already somewhat developed (because i've been thinking about them), and i will highlight them shortly per idea. Plus reasoning for choices, to do with the eventual use of the end product and stuff.

## 4.1: Scale, Harmony and StepLength
**CONCEPTUALLY:**  
I've been working with steps on a chromatic scale. But because I want to eventually use this in actual productions, I want to be able to work with melodies in scales.  
Another seperate idea was that every step could have a harmony as well, just a melody of only fifths or something. With this, I also got the idea of a "Chord Mode", in which every step would form a triad on the step itself.  
That's when I also got the idea of the chords taking 'longer' than just a 16th note. So I figured I could have another control for the stepLength, in which i can scroll through quarter, 8th or 16th notes for the length of each step. I guess this would be an addition to the BPM-knob I already have, so the BPM makes everything go faster/slower, and the stepLength-knob decides the length of one step in the bar.  
**PHYSICALLY**  
Of course, I wanted to have some way of visually presenting these paramters on the end product so that I can play with them. I do not have fancy OLED screens on it. And I also don't want to use text on the sequencer itself, because I want everything to be LEGO and represented in an original way that satisfies me. This is because I love working with a system that you're like "Ohhhh, this is how it works!". (Editoral note: I'm going to explain this motive later and write down reasoning on this take.)  
*So I thought of a way to do that:*  
- These 3 parameters (Scale, Harmony and StepLength) each have a button
- This button increments a variable that decides which mode is going to be implemented in the sound
- This is made visual by one RGB LED, showing a color that represents the chosen option
- Next to the RGB LED, are different colored LEGO pieces showing the available options
- ---> This is easiest explained if I just show what I made with LEGO --->>>  
**SMALL BUILDING PROCESS**  
See *11.4*.

## 4.2: Doing Something Cool with the Glitch
At first i thought Phaser and Compression would sound kind of glitchy. But now I'm falling in love with the idea of actual 'glitch-sounds' triggering in the audio. More of the glitch effect means more, faster glitches.  
*List of Possible Glitches (in order of most likely/easy to implement):*  
- Silence
- Bitcrush
- Noise
- Phaser
- Square LFO on volume
- Compression
- FM
- Grain  
All of the above can happen to either the Left or Right channel.  
I can write a simple class for this with this algorhythm.  
With this algorhythm, *I want to make sure some things are randomised:*  
- What channel is affected (Left or right)
- How often glitches occur
- How long a glitch is  
I guess the easiest option would be to have 2 separate (but the same) algorhythms on the Left and on the Right, and then just map the timings and ranges to the Effect Knob potentiometer.  

**Another open realisation: The fact that this wonderful idea came out of one knob, means that I can do more with the other effect knobs as well.**  

## 4.3: Pre-Sets & Saving States
Just something I wrote down. It would be pretty cool to be able to switch between different pre-sets you made yourself. I could use the same system as the scale/harmony/steplength-system to store different pre-sets linked to a variable you can scroll through with a button. You can have a green "SAVE" button to save the parameters to that preset and scroll through others to get them again.  
**Parameters that are able to be SAVED:**  
+ Pitches (and which are muted)
+ Scale
+ Harmony
+ Steplength within a bar
+ Which Octave
**Parameters that are NOT able to be SAVED:**  
- Att/Dec
- Oscillators Mix
- FX amount
- Sequencer Speed

## 4.4: Randomiser Button
This would be cool! I got this out of the Pre-sets idea. The same parameters that can be saved (due to the variables not depending on a pre-determined input variable like potentiometers), could also be randomised with the press of a button.  

**Follow-up on this idea:**  
The randomiser knob could be a rotary encoder with these functions:  
- Turning the encoder increments all sequencer steps by -1 or 1 (in their respective scale)
- Pressing the encoder is what actually randomises all the (available) parameters

## 4.5: LED Idea
2 small ideas having to do with programming (normal) LEDs:  
1. The Sequencer step LED's can follow the att/dec variable when it comes to brightness
2. The Figurine Chamber LEDs can be connected to the potentiometer of the efffect they belong to  
--> Would be even cooler if the chamber LEDs were RGB and they react to the effect amount  
These are just 2 visual things that would be cool, but I have them marked on my todo list as "LAAAAST PRIO"  

## 4.6: Adding Input
PRETTY PROUD OF THIS ONE. Not because it's an original idea, but because it's so obvious and adds so much functionality. I'm definitely going to add an input Jack to the sequencer, and then a 2-way switch to decide whether to use the Sequencer as source-audio for the effects, or the input audio itself. This way, I can run guitars and mics and stuff through the effectschain. Now that I think about it, If it's a 3-way switch i would have another nice option: Using the att/dec variables ON THE INPUT. I love this idea so much.  
***I. WANT. THIS.***  

# 5: Visual Configuration of the Total Picture
Made some sketches of blueprints for the end product. See *11.5*.  
I'm going to use #5 as base for the lay-out of all the parameters.  
