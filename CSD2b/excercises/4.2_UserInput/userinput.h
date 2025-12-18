#ifndef _USERINPUT_H_
#define _USERINPUT_H_

#include <iostream>
//include this bc i actually need it now
#include <string>
#include <list>

namespace userinput {
  //FUNCTIONS AKA QUESTION-TYPESSS
  std::string UIReturnString(std::string optionList[], int optionAmount);
  float UIReturnFloat(float rangeStart, float rangeEnd);
  //boolean bc its valid or not
  // bool validateSelection(std::string)
}

#endif
