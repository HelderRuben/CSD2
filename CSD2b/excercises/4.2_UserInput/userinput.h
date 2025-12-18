#ifndef _USERINPUT_H_
#define _USERINPUT_H_

#include <iostream>
//include this bc i actually need it now
#include <string>
#include <list>

namespace userinput {
  //FUNCTIONS AKA QUESTION-TYPESSS
  float UIReturnFloat(float rangeStart, float rangeEnd);
  bool UIReturnBool(std::string boolQuestion);

  std::string UIReturnString(std::string optionList[], int optionAmount);
  bool checkStringValidity(std::string optionList[], std::string userString, int optionAmount);
  //boolean bc its valid or not
  // bool validateSelection(std::string)
}

#endif
