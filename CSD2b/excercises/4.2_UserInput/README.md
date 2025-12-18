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
