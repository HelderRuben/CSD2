# Experience of this assignment
I am learning a lot by doing this assignment and i think it is important to reflect on it.  
I did not use copy/paste at all during this, so by repetition i learned a lot about syntax and how classes work. Also, using terms like constructor, methods and members is normal now.  
I did lots of testing regarding using multiple files. At first it was hard because i thought it was very chaotic.  
Right now i have finished both the dog and the cat. It was very nice to repeat the process of the dog again.  
I didn't look at the ciska-code anymore, only my own code sometimes as example.  


# Overview of project:
  MAIN.CPP: Running the program, included with headers linking to different classes  
  HEADERS: Class definition and linking to other headers in inheritance  
  CPP FILES: Classes functions and linked to header  
  CLASSES:  
  Dog: Able to eat, sleep and *bark*  
  Cat: Able to eat, sleep and *climb*

# TESTING

## Private and Protected  
 If 'protected' is changed into 'private' in line 15 of pet.h, the other files (see dog.cpp) can't access the *name* variable anymore, therefore the console gives an error (**see protectedAndPrivateError image**).  

## Dog Tries to Climb
  Obviously, because eat and sleep are both inside pet.h, cat and dog can access them both.
  But if i add "**dogObj.climb();**" to main.cpp, a simple error occurs, saying the dog physically can't climb (:
  (**see dogTriesToClimb**).
