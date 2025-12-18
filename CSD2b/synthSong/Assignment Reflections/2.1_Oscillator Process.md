# Approach to Assignment

For this assignment, I didn't even look at the main.cpp and other files at first, but only the notes.md with 7 steps.
I'm very happy with all the syntax mistakes I made, so I could fix them by following the error messages.
Eventually I had to resort to the ciska-code for help, but I learned so much already.

# Steps

## Private and Public
See **changingFreqPublicConsole.png** for illustration that the field *freq* can be changed if we add code in the main.cpp, and if the field is public.  
See **changingFreqPrivateConsole.png** for illustration that the field *freq* cannot be changed if it is in private.  

## Adding Setter & Getter

Here I made lots of mistakes in syntax and tried a lot of fixes myself and eventually fixed them looking at the step 3 code.  
I get the flow even more now.  

## Delegating Constructors

At first, I thought I understood constructor delegation and I tried it, but completely failed.  
After looking at the ciska-code I realised it was much simpler than I thought.  
I also found it interesting to find out things about the flow of C++. If the default constructor is using delegation, lets say with frequency 440, It first activates "Osc(440)", and then the default constructor.  
I tested this by changing the frequency again in the default constructor.  
See **delegatingConstructorFlow.png** for a side-by-side view of this example.  

I decided to do more testing with delegating constructors, so I added the variable "amplitude" and made another constructor with 2 parameters (frequency and amplitude).  
I delegated my extra constructor to the frequency constructor. In this way, I could have one constructor for connecting the frequency variable to the freq field, and another for the extra amplitude variable. This seemed to work pretty efficiently.  

## Initialiser List

But, correction: It wasn't, because you can't do both delegation and initialisation in the same line, example:  
##### "Osc::Osc(float frequency, float amplitude) : Osc(frequency), amp(amplitude) {"  

Switching the constructors fixed this problem. Now, the frequency constructor delegates to the freq/amp constructor with a default value for amplitude, and the freq/amp constructor initialises both the frequency and amplitude.  

This was nice assignment. (:
