#include <iostream>
#include <string>

#include "userinput.h"

float userinput::UIReturnFloat(float rangeStart, float rangeEnd) {
  //Asking questions
  std::cout << "\nEnter a float between " << rangeStart << " and " << rangeEnd << ".\n";

  //store input as string and test for float
  std::string userFloatInput;
  std::cin >> userFloatInput;
  float userFloat = std::stof(userFloatInput);
  return userFloat;
}

std::string userinput::UIReturnString(std::string optionList[], int optionAmount) {
  //Asking questions
  std::cout << "\nType one of these options to choose:";
  for (int option = 0; option < optionAmount ;option++) {
    std::cout << "\n" << optionList[option];
  };
  std::cout << "\n";

  //retrieve a string from user
  std::string userString = "";
  std::getline(std::cin, userString);
  //and then check for legitness in some way
  return userString;
}
