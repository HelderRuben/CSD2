# Step 9: Writing the classes previously researched

Working on:
1. Bitcrusher
2. LPF
3. Compressor

## 1: Bitcrusher
Wrote class according to 8.3.  
Testing setN mapping to knob: Works, 10 to 3 bits is a nice range for the effect to kick in.  

## 2: LPF (and Linkwitz-Riley)
Wrote class according to 8.2.  
Works! Did a quick look again and found out i wanted a Linkwitz-Riley instead of a normal 1st order LPF...
Going back to step 8 to make a thing on Linkwitz-Riley.  
-> Wrote Linkwitz-Riley LPF according to 8.2.  
Works!  
Experienced with some mapping: [100Hz, 19000Hz] is nice
Implemented breakFreq calculation (from [0, 1] to [100Hz, 19000Hz]) in class as well.  
It would be very nice if the filter had a resonance peak. I'll research this as an extra if i'm done in time with the compressor.  
I like this, pretty much everything is going smoothly and i'm absolutely enjoying myself

## 3: Compressor
Started writing class according to 8.1 and had some trouble, so dicided to dive deeper.   
Looked at classes wrote by *ChunkWare Music Software (OPEN-SOURCE)* and made a simple class diagram as overview, see 9.1.  
The steps were clear now.    
Ah to be honest i feel like i almost got it but it's not top priority to have this right now. I first want to focus on the Daisy Seed itself and getting it to work.  

# Concluding

**I HAVE:**  
- Reverb
- Delay
- Phaser
- Waveshaper
- LPF (no resonance)
- Bitcrush

**I WOULD WANT LATER:**  
- Compressor (working)
- LPF with resonance
