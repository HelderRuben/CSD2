#ifndef _USERINPUT_H_
#define _USERINPUT_H_

#include <iostream>
#include <string>
#include <list>

namespace userinput {
  //different types of questions
  float UIReturnFloat(float rangeStart, float rangeEnd);
  bool UIReturnBool(std::string boolQuestion);
  std::string UIReturnString(std::string optionList[], int optionAmount);
  //function for checking validity of user input
  bool checkStringValidity(std::string optionList[], std::string userString, int optionAmount);
}

#endif
