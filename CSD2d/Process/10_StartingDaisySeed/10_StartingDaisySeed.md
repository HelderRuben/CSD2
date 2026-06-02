# Daisy


**SUMMARY OF THIS MD, WRITTEN AFTERWARDS**  
Doing Daisy things! That's for sure a prio, bc the whole project depends on it.  
Step 10 (this md) was written at the same time as Step 11, because things with code and with creative process are developing at the same time. Somehow in my workflow, Step 10 became a thing where I'm actively working in (working with priorities and small diaries), and Step 11 became the place where I'm actually documenting the things i think about design-wise. Hope this is kind of intuitive.  
*Steps taken in this md:*  
- First prio-list
- -> leads to First prototype
- Conclusions about the prototype
- Second prio-list


# 1: First prio-list
1. Installing things
2. Making Daisy Blink
3. Attaching pushbutton
4. Attaching LED
5. Processing Serial Info
6. Attaching potentiometer (multiple)
7. Attaching Multiplexer + potentiometers
8. Attaching Encoder
9. Coding Simple step sequencer (without audio)
10. Attaching RGB LED  
-> and then go to audio stuff  

## 1.1: Simple diary on doing these things
- Did step 1-6 succesfully
- Did step 7 succesfully (see *10.pic1*)
- Did step 8 succesfully
+ Got audio working (felt it more important for an audio-project)
+ Made overview *10.pic2* for imagining daisy pin configuration  
  - Very nice to follow this. For now i don't need another Multiplexer (i fortunately ordered multiple) but if i have extra's at the end I can (like a randomiser, pre-sets, etc. I've got some ideas :D )  
- Did step 9 succesfully
- Skipping the RGB LED (step 10) for now
+ Made 4-step sequencer with:
  - 4 Rotary Encoder pitch knobs
  - Octave Potmeter
  - Tempo Potmeter
  - Jack output
  - Cardboard lol
See *10.pic3* for this prototype!

## 1.2: Conclusions with this First prototype
Here are some challanges and conclusions i ran into due to making this prototype:  

**Soldering is needed but is hard**  
I wasn't looking forward to soldering things, but i couldn't not do it anymore because of my "only having a small breadboard". I do like when soldering works, but it feels foreign to me. Once I got in a little bit of a flow it was quite nice though, I was just scared sometimes that the connections i made weren't good enough to last for a longer time.  

**Needing (more) wires**  
I don't have a lot of jumper wires in my possession, and i never thought that would be an issue until i saw the scale of this project. The endproduct is going to be a lot bigger than the Daisy itself, so i'll be needing some long wires to connect the Daisy pins to the components.   

**Needing multiple Multiplexers**  
Looking at the pin overview i made (*10.pic1*), I totally forgot that i'd be implementing all sorts of LEDs. So i definitely need more multiplexers! I have 4, so that'll be good enough.  

**Conclusion**  
I ordered another breadboard to work with and another little box of wires.

# 2: New Prio-list
**SECOND LIST:**  
1. Testing MUX with 6 potentiometers and 2 buttons
2. Testing (full) MUX together with other inputs
3. Add LPF to sound
4. Let extra potentiometer control LPF cutoff
5. Add another MUX with the 4 effect knobs attached
6. Connect more FX! / Figure out FX mapping for the 4 knobs

## 2.1: Doing new Prio-List

- Did step 1 succesfully, expanded prototype; see *10.pic4*
- Did step 2-6 succesfully
- Wrote down lots of extra ideas and stuff in step 11 (played with LEGO a lot)

# 3: Another New Prio-list
**THIRD LIST:**  
1. Order extra components needed based on conclusions in Step 11 md
2. Connect button and Code "holding down and changing parameter"-system
3. Let Button in this way control stepLength changes
4. Let another Button in this way control Scale changes (+code scales)
5. Let another Button in this way control Harmony changes (+code harmony)
6. Code 1 RGB LED
7. Code series of RGB LEDs
8. Code series of RGB LEDs based on steps
9. Expand series of RGB LEDs based on steps + scale/harmony/steplength
10. Make pin config overview (with complete list of everything needed)
11. Code Mute buttons

## 3.1: Doing Another New Prio-List
- Ordered some switches and 6.35mm Jack things
- Completed system of step 2, was so fun to work on
- Completed step 3-5
- Skipped RGB stuff and first did step 10
- Completed step 11
Didn't code RGB LEDs anymore, wasn't prio compared to building it
