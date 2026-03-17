# Hey Diary!

Today i'm hoping to be done with the reverb. I'm revisiting the 2 video's i've watched on creating a reverb and writing down specific things i can use to make something sound diffuse, and then using a delay to delay that sound, giving a reverb its tail.

**Looking Into This Video**
- https://www.youtube.com/watch?v=XLyrEKX4Q2g  

Delaytimes he uses in the video:
- 30.94
- 33.76
- 38.46
- 45.05
- 53.51

Turn those into sampleAmounts:

- 1485
- 1621
- 1846
- 2162
- 2568

```
AllPassFilter apf6{0.5, 1485, 2600};
AllPassFilter apf7{0.6, 1621, 2600};
AllPassFilter apf8{0.7, 1846, 2600};
AllPassFilter apf9{0.56, 2162, 2600};
AllPassFilter apf10{0.65, 2568, 2600};
```

That was kind of a test thing but in the video it sounds okay.
Nah nevermind, sounds wayyy more metallic than the Pircle one

**Looking into This book**
- https://archive.org/details/physicalaudiosig0000juli/page/96/mode/2up

# Realisation

Okay made me realise some things:
+ Schroeders Reverbs are pretty cool
+ This book is very detailed in the specific delay times that are used to make sure it sounds incommensurate
+ It even has C++ CODE TO MAKE A REVERB
+ I like the Idea of making a *parallel bank of feedback combfilters* and a *mixing matrix* to make the sound diffuse and reverberated
- I need way more time to look into this
- I still need to make an LFO and a Phaser
+ I (kind of) have a reverb already
+ **CONCLUSION**: I don't have anough time to do this and i should've started earlier.

Choice I'm making now:
- Checking out 3 successive APF's with incommensurate timings from the book
- Moving on to the phaser and seeing this as something i can expand on

# Testing incommensurate Timings
Based on page 95:
```
AllPassFilter apf6{0.7, 1052, 1100};
AllPassFilter apf7{0.7, 337, 350};
AllPassFilter apf8{0.7, 113, 130};
```

- veeery metallic, very noticable how low frequencies mess it up
- adding delay -> went well
- Experimented with multiple parallel delays and it sounded really promising.

# Final thoughts before moving on to Phaser

**I think the "diffuser -> delaystack" is the way to go for the reverb.** If i spend more time on it now i probably will regret it in the future. For now i am content with my reverb not sounding that good (and very metallic), that's fine. the "diffuser -> delaystack" method only requires some trial and error with timings and feedbacks, but it doesn't have to be a large complicated model which is good.
Moving on to Phaser!
