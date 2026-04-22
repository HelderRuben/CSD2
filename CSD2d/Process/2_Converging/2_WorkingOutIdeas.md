# Converging: Working out 4 ideas

I did this in 4 days, to really let my mind be creative and think about random things to apply musical programming to. It made me think about some things i want to accomplish this block.  

## Conditions for Good Idea
So these are 3 things the idea has to have in order for me to possibly go through with it
1. I want to make a finished product that looks aesthetic
  - I see this block as an opportunity to challenge myself to finish a project (cleanly) to the very end
  - I always enjoy a design-process and i want to go through multiple iterations of the product, with different ideas and prototypes
2. I want to make use of it
  - I see this block as an opportunity to make something hardware that i'll actually use inside other projects/productions/daily life
3. I want to do something with hardware
  - I love hardware and want to grow in designing it/using it/soldering and everything that comes with it
  - I would love to have a tangible end product that works  

## Top 4 Ideas
According to these things I made a top 4 of projects i want to do some research on how to do them:  
1. 8-Step Sequencer
2. Synthesizer
3. Effect Pressure Plates
4. Effect Blockchain  

This list is also in the order of in-my-mind most likely to work on, but I want to intentionally research them in the opposite order to go against my "I-have-one-best-idea-and-want-to-only-do-that" mindset. So in the next chapter:  

4. 8-Step Sequencer
3. Synthesizer
2. Effect Pressure Plates
1. Effect Blockchain  

# Working out the 4 Ideas
*In this chapter, I'm making 4 subchapters of working out each of these 4 ideas*  

**This is how**:  
These steps in every one of the 4 ideas:
1. Thoughts
  - Short opinion
  - A view of what the endproduct would be in a perfect world
  - A speculation on how to build/code it
2. Small Selfstudy
  - On a topic for specifically the design idea
  - Not like an entire study and reading/watching everything, just collecting some sources on what i can find, maybe i'll use them later on. I'll include them all in *0_SelfStudySources.md*
3. Improved sketch
  - A finished-looking design based on the signal flow in my head
  - Not too much effort, its an in-between-sketch for the purpose of thinking about all the effects/parameters and the design

## 1: Effect Blockchain  

See file *2.1.1*.  

**Thoughts**  
*Opinion so far*  
Would be a cool end-product, but somewhere I feel like i would be messing a lot with getting the hardware to work, that's why it's at the bottom of my list so far. Also feels kind of unintuitive to make a literal chain, because breaking it apart (to change the effect order) stops the sound. Therefore the idea is nice to me but the practical concept is less attractive.  
*Perfect End Result*  
A clean, finished design of the following blocks and signal flow:  
1. An Input-Block  
  - A Jack female ->
  - A USB output
2. An Output Block
  - A USB male ->
  - A Jack cable (male)
3. Effect 1: A Filter Block
  - A USB male ->
  - LPF (with Cutoff and Resonance) ->
  - HPF (with Cutoff and Resonance) ->
  - Dry/Wet ratio ->
  - A USB output
  + A display visualising the filter would be cool
4. Effect 2: A Delay Block
  - A USB male ->
  - Delay (with delayTime and Feedback) ->
  - Dry/Wet ratio ->
  - A USB output
5. Effect 3: A Waveshaper Block
  - A USB male ->
  - Waveshaper (with drive and shape-switch)
  - Dry/Wet ratio ->
  - A USB output
6. Effect 4: A Tremelo Block  
  - A USB male ->
  - Tremelo (with frequency and amount) ->
  - Dry/Wet ratio ->
  - A USB output
7. BONUS: Effect 5: A Reverb Block (would be cool if possible, but probably takes too much time)
  - A USB male ->
  - Reverb (delaytime and diffuse) ->
  - Dry/Wet ratio ->
  - A USB output

*Speculation on building and complications*  
**Power**: Because it being 6 individual module, i guess giving it power is going to be weird? I could probably do it with a battery and an off switch. But does every module need some kind of Teensy?  Or, could I actually do them in a chain, so that every USB-port can provide both power and audio to the next module? Therefore only the first module has to be powered. That option would be optimal, only one Teensy is needed.  
**Signal Flow**: The USB-ports connected to the effect blocks would pass on the audio, but also the potmeter-information of every effect. But I won't really know how to do this.  
**Coding**: I could have a basic template for each of the 4 effect modules i'll be using.  
**Priorities**: The prio-list would look a bit like this (assuming i've done research):  
1. Get input and output block to work
2. Add gain volume button to output block
3. Code template for effect blocks (receiving information, dry/wet knob)
4. Code filter and link to the 4 potmeters
5. Make prototype for input, output and filter blocks
6. Code delay and link to potmeters
7. Code waveshaper and link to potmeters
8. Code tremelo and link to potmeters
9. Make all prototypes work
10. Design casing
11. Soldering & Assembling

**Small Study**  
For this, I will do some research on connecting a Jack input/output to Arduino. Partly because it's helpful for the other projects as well, and after thinking about this one i kind of know already that I won't be doing this... I think i just like the others more.  
*Jack input/output*  
I already know connecting a 3.5 mm Jack (female) to teensy is possible, because we used it last year during hardware.  
Nice blog post: https://forum.arduino.cc/t/trying-to-get-audio-output-from-a-1-4-jack-using-pwm-and-an-rc-filter/1407908  
- Talks about RC Filters
How is a 1/4" jack input/output possible?
*Idea*  
Maybe I can use the HKU mic+dac we used last year. Then I would already have the weird audio-config (that i don't understand i think). I would just use a minijack-jack cable instead of a jack-jack. I would need to look at the code I made last time, easy.  

**Improved Sketch**  
See file *2.1.2*.  
*Sketch takeaway/conclusion:*  
- I now know the parameters and effects I would use in the block chain
- I now know the order of effects in the block chain  

## 2: Effect Pressure Plates  
See file *2.2.1*.  

**Thoughts**  
*Opinion so far*  
Original way to add effects to your effects-chain! Feels cool to apply effects by applying more force (or weights) to pressure plates which control effect mappings. I would be happy to make this. I would love to make it with a XLR/Jack input (both possible), for more input possibilities.  
*Perfect End Result*  
A clean, finished design of the following signal flow with effects modulated by the pressure plates:  
- Input: A XLR/Jack female ->
- Waveshaper (dry/wet) ->
- Filter (HPF -> LPF -> dry/wet) ->
- Delay (time -> feedback -> dry/wet) ->
- Reverb (time -> dry/wet) ->
- Output: Jack cable male
- BONUS: Bypass button on the side  

*Speculation on building and complications*  
The main complication is the pressure plate itself, and if/how i can get it to work. If that works (with Teensy), than I am confident that I can manage this project.

**Improved Sketch**  
See file *2.2.2*.  
I'm thinking of 2 options on how to build this idea:  
1. 4 pressure plates for dry/wet, and buttons on the side for effect parameters  
2. 9 pressure plates for all effect parameters and dry/wet  
*Sketch takeaway/conclusion:*  
After drawing them both out, I do think the second option is the best, because it focusses fully on the "getting-the-effect-due-to-the-weight" mechanic. Conceptually it's the most pleasing, and I also know that if I have 1 pressure plate working, I can easily get 9 through repetition.  

**Small Study**  
I already have a hardware pressure meter component, let's figure out if I can hook it up to the Teensy.  
But before I do that i need more ideas, going to step 3
