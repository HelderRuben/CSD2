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
