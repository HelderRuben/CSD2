#ifndef _USERINPUT_H_
#define _USERINPUT_H_

#include <iostream>
//include this bc i actually need it now
#include <string>

class UserInput() {
public:
  //constructor
  // UserInput();

  //destructor
  //Im realising as i type this i dont even need a con/destructor sooo nvm

  //MEMBER FUNCTIONS AKA QUESTION-TYPESSS
    //nooooo clue if this syntax is right, probably totally not but i'll learn from it
  std::string UIReturnString(array optionList);

  float UIReturnFloat(float rangeStart, float rangeEnd);
}

#endif
