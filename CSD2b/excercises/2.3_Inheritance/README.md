# Starting Assignment
First i wanted to try building from the Ciska-repo-clone and running the code, but i had some complications.  
I learned that there wasn't a "add_executable" commant anymore in the CMakeLists.txt, so after some time trying to figure it out and **asking questions** about it in the group and to Daan, i figured out i needed to build from the top-level where JUCE was in and then navigate to the example_artifacts to run ```make``` and then run the executable.  

When making it to my own repo, I carefully copied every part of every file in 5_SoundingSine, so i would kno wit was structured and connected to each other.  
I added some comments here and there to make sure I knew what was in the file.  

# Adding Square
I started copying the sine.h and sine.cpp to make them into a square. Pi wasn't necessary anymore, so i removed it from the calculation. I included the square.h where it needed to be and implemented the square-calculation.  

# Adding Inheritance

Since there is now a lot of duplicate code (same members in different classes defined), the right option was to add an Oscillator class (abstract). In **simpleClassDiagram.png**, you can see the inheritance (with member functions) I implemented for this assignment. I started by linking the Sine class to the Oscillator class.  
I started with make oscillator.cpp + header files, and including the waveform headers in the oscillator header instead of the callback.  
I took some time with compiling this and fixing syntax errors i made along the way.  
For me to understand how linking Oscillator to Waveform works:  
Essentially, oscillator is an abstract class object that initialises anything to do with the oscillators itself, but uses the calculate() function to activate which waveform is going to be used.  
The oscillator itself is not the object, the waveform is and takes its characteristics from the oscillator class.  
Removing the duplicate code was easy, now that i knew the waveforms were only different in their calculations.  
Therefore, tick() in Oscillator now only updates the phase, and calculate() in Sine and Square calculates the sample.  
Also, the constructor is linked to Oscillator (with " : Oscillator(parameters)"). The initialiser list is in the constructor of Oscillator, not Sine/Square anymore.  
I also started looking at 3_sineSquareSaw in _session3 to compare my code and learn syntax.  
After this, it was a matter of changes some #include's and linking the callback to oscillator i.o. the waveforms.
-> Never mind, that's what i thought but i forgot to do things with protected/private and virtual. I also kept getting the error that "Oscillator" wasn't a class name (in Sine-constructor line) which i was very confused about, but by painfully looking at where my #include's were, i learned that i did it wrong (I included sine.h in the oscillator.h which messed up the defining of headers).  
And i forgot to include the sine.h in the callback (I am learning to include things in my life apparantly).  
Aaaand something's wrong again.
