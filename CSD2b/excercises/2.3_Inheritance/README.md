# Starting Assignment
First i wanted to try building from the Ciska-repo-clone and running the code, but i had some complications.  
I learned that there wasn't a "add_executable" commant anymore in the CMakeLists.txt, so after some time trying to figure it out and **asking questions** about it in the group and to Daan, i figured out i needed to build from the top-level where JUCE was in and then navigate to the example_artifacts to run ```make``` and then run the executable.  

When making it to my own repo, I carefully copied every part of every file in 5_SoundingSine, so i would kno wit was structured and connected to each other.  
I added some comments here and there to make sure I knew what was in the file.  

# Adding Square
I started copying the sine.h and sine.cpp to make them into a square. Pi wasn't necessary anymore, so i removed it from the calculation. I included the square.h where it needed to be and implemented the square-calculation.
