#include <iostream>
#include <string>

#include "userinput.h"

float userinput::UIReturnFloat(float rangeStart, float rangeEnd) {
  float userFloat = 0;
  bool notInRange = true;

  while(notInRange) {
    std::cout << "\nEnter a float between " << rangeStart << " and " << rangeEnd << ".\n";

    //store input as string and test for float
    std::string userFloatInput;
    std::cin >> userFloatInput;
    try {
      userFloat = std::stof(userFloatInput);
      if (userFloat >= rangeStart && userFloat <= rangeEnd) {
        //stops while-loop to return value (conditions are met)
        notInRange = false;
      } else {
        std::cout << "\nWithin range please.\n";
      }
    }
    catch (const std::exception& nonFloatInput) {
     std::cout << "\nNumber(floating point) please.\n";
    }
  }
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

bool userinput::UIReturnBool(std::string boolQuestion) {
  float userFloat = 0;
  bool notInRange = true;
  std::cout << boolQuestion;
  std::cout << "\n  1 = yes\n  0 = no\n";
  while(notInRange) {
    std::string userFloatInput;
    std::cin >> userFloatInput;
    try {
      userFloat = std::stoi(userFloatInput);
      if (userFloat == 1 || userFloat == 0) {
        //stops while-loop to return value (conditions are met)
        std::cout << userFloat;
        notInRange = false;
      } else {
        std::cout << "\n1 or 0 please.\n";
      }
    }
    catch (const std::exception& nonFloatInput) {
     std::cout << "\nNumber(integer) please.\n";
    }
    if (userFloat == 1) {return true;};
    if (userFloat == 0) {return false;};
  }
}
