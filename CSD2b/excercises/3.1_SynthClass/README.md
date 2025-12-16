# Back again with another Assignment!

This time for making different Synths. Things i did:
- Copied everything from 2.3_Inheritance assignment
- Tried to make an organ by adding multiple oscillators in Callback
Couldn't figure out why it wasn't working so i checked the Ciska-code.  
Pretty obvious fix: the sample-values need to be added to each other to make the total value of sample (oscillators combined).  

Still can't quite figure out why the callback doesn't want ```Sine oscName(440, 44100);``` but only accepts ```Sine oscName;```...
