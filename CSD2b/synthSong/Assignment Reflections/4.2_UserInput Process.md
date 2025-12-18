# User Input

Next thing to work on: Asking the user all these questions to *make stuff happen based on choices* (a.k.a. life).  
I've written these questions to make sure i know what i wanna do:
1. Q: What kinda Synth you want?
  - A: FM, RM
2. Q: What's the waveform of the CARRIER?
  - A: sine, saw, square
3. Q: What's the waveform of the MODULATOR?
  - A: sine, saw, square
4. Q: What's the carrier-modulator ratio?
  - Float between 0 and 5 (or something i'll test it)
5. Q: How many modulation you want? (in percentage)
  - Float between 0 and 1 (probably, haven't even thought about this...)

# Attempt without knowing syntax

Okay so now i know the questions. I also know that i need a function for retrieving a float (in range), and a function for retrieving a string (with specific options).  
Time to learn from the Ciska-code! I took a quick look and started writing, without actually knowing any syntax for this. I made a new class called userinput and made a header plus cpp from scratch. I'm pushing this attempt to see how it goes!!
Im writing code now and i've written this:

```
//constructor
// UserInput();

//destructor
//Im realising as i type this i dont even need a con/destructor sooo nvm

//MEMBER FUNCTIONS AKA QUESTION-TYPESSS
  //nooooo clue if this syntax is right, probably totally not but i'll learn from it
std::string UIReturnString(array optionList);

float UIReturnFloat(float rangeStart, float rangeEnd);
```

And for the cpp...
```
float UserInput::UIReturnFloat(float rangeStart, float rangeEnd) {
  //Asking questions
  std::cout << "\nEnter a float between " << rangeStart << " and " << rangeEnd << ".\n";

  //don't know what im doing here, this looks more like pseudo code

  std::cin >> float userFloat;
  //And then something to check if its legit or no, something like:
  if(userFloat < rangeStart or userFloat > rangeEnd) {
    std::cout << "\nRead correctly and try again.\n"
    //ask question again
    return nothing lol;
  }
  return userFloat;
}
```

Just wanted to drop it here bc i thought it was entertaining. This is like a journal after all.  
Anyway im just committing to it...  

# Getting to itttt

OKAYYYY now it's time to fix the horrible things i have just written down. This is things i did:
- i saw Vida use ```namespace``` i.o. ```class``` and i thought that was very genius (after looking it up) so i'm doing that as well.  
- fixed wrong string/array syntax
- fixed for-loop syntax (i thought it was python for a second but nah)
- Tried to write a "validateSelection" function myself but then i thought nah that'll be the next step it's okay
- Googled what ```getline``` is and implemented it (it gets a string from user and stores it in string variable)  
- Looked at ```while(notInRange)``` thing and decided that's what i'm doing next
- Found out that you first have to capture UserInput as a float and try to convert it to a string(interesting)
- Googled ```std::stof``` (has nothing to do with dust but its "s to f")
- Tested user functions in main to actually get feedback i did something
  - Figured out how to array-syntax
  - Figured out how to namespace call syntax
  - Struggled and finally found out i didn't include the userinput.h in the cpp......
  - Struggled with corrected error when implementing list as string (i learned how to do list in c++ yay)

# Adding another question

i didn't know why i didn't do this in my first attempt, but suddenly i realised there was another question type:
1. Q: Would you like to play again? yes = 1, no = 0
  - A: 0 or 1
Yes plays again, 0 quits application

So i did a little testing with bools and added this question as well

# float Range

Its time for the range of the answer to work properly. I liked the idea of a boolean "notInRange" in a while-loop so thats what im doing. I googled how to do try and catch and then i kind of did it(thanks w3schools).
Saw Vida using std::exception, googled it, implemented it.  

Also added this range thing to the boolean question so the answer is 1 or 0 (but then with std::stoi i.o. std::stof).  
Note: Maybe this isn't very clean because, if answering with a float, it gets rounded off (0.5 = 0, 1.2 = 1) But i'm accepting it bc it's **4:18 AM** right now.  

# Correct String

Now the same thing but with the string question. I'm making a function to check the validity of the string, by for-looping through the string and checking if it's one of the options or not.  
Just like the usual, i first tried myself and then looked at Ciska-code to try to learn something.  
Uhhh no i'm not for-looping through the string, i'm for-looping through the options to check every one of them. Somehow i thought i needed to check every string-character but okay nvm.  
But it went pretty smoothly actually!  
Okay the error-fixing went smoothly but now im stuck on the bug that everything that i type is wrong, even if its right.  
Nvm, was something to do with a wrong for-loop.  

I still have a bug left, the UIReturnBool also accepts specific string values as 0, like "sdfg". Don't exactly know why.

# Correct questions

Implemented the correct questions in main function (for testing) and connected the values to right variables. (Not the FM, RM and modAmount yet, but the waveforms and ratio).  

In main:
NOTE: I know the questions can be implemented in the functions(small duplicate code) as well but this is very readable...

I'm using * and & with pointers for the first time to make these "user-chosen" variables accessible for the functions that need them. I think that's just very easy to do that from the main, since the main.cpp is the source of the questions code.
**Nope never mind that's not what i'm doing**
I'm gonna make the Callback *use* the userinput, just like it says in my class diagram.

I am so close, i already have that the synth starts playing AFTER the questions are answered. The only thing that's bothering me is how the Synth has to be initialised by the Callback constructor, before i can have the variables ready (so now its just always the standard values of the synth-parameters, because they are defined in the callback-header).  
I think the solution would be to have pointers, because i seem to need dynamic memory allocation.  
testing that now...
I just found out that it's purely logical to work with pointers here. In the class diagram, the callback *HAS A* Synth, so im gonna connect the synth to the callback in the same way i connected the oscillator to the synth; a pointer.
I got "Bus error: 10", i think bc i didn't use a ```delete synthPtr;```. So im making a destructor for the Callback to delete it.  

# Error "Segmentation fault: 11"

Not really sure what it means fully, but it shows up when i complete one question. Doesn't matter which question, as soon another one wants to come in its over.  
I'm getting frustrated with this error because its stopping me from doing things i want. It seems like the ```CarrAndMod[0]``` pointer can't store ```new Saw();``` which is really annoying and i dont know what im missing.  
**I GOT IT.**
Through trial and error though. I did ```synthPtr = NULL;``` and made the ```new Synth();``` in the function when setting the waveforms, instead of initialising the synthPtr in ```Callback::Callback```.  

# Clean up time(:

- Removed and changed some commentary
- Improved readability
