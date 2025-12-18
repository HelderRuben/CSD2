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
        std::cout << "\nWithin range please.\n--------------------\n";
      }
    }
    catch (const std::exception& nonFloatInput) {
     std::cout << "\nNumber(floating point) please.\n";
    }
  }
  std::cout << "\n+----You picked " << userFloat << "----+\n";
  return userFloat;
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
        std::cout << "\n1 or 0 please.\n-------------\n";
      }
    }
    catch (const std::exception& nonFloatInput) {
     std::cout << "\nNumber(integer) please.\n-----------------------\n";
    }

    if (userFloat == 1) {
      std::cout << "\n+----You picked yes----+\n";
      return true;
    };
    if (userFloat == 0) {
      std::cout << "\n+----You picked no----+\n";
      return false;
    };
  }
}

std::string userinput::UIReturnString(std::string optionList[], int optionAmount) {
  std::string userString = "";
  bool notRightInput = true;
  bool checkValidity = false;

  while(notRightInput) {
    //question asked
    std::cout << "\nType one of these options to choose:";
    for (int option = 0; option < optionAmount; option++) {
      std::cout << "\n" << optionList[option];
    };
    std::cout << "\n";

    //retrieve a string from user
    std::getline(std::cin, userString);
    //is the answer possible?
    checkValidity = checkStringValidity(optionList, userString, optionAmount);
    if (checkValidity) {notRightInput = false;};
    if(notRightInput) {
      std::cout << "\nTake some typing or spelling lessons\n------------------------------------\n";
    };
  }
  std::cout << "\n+----You picked " << userString << "----+\n";
  return userString;
}

bool userinput::checkStringValidity(std::string optionList[], std::string userString, int optionAmount) {
  //cycling through options to check if its there
  for(int option = 0; option < optionAmount; option++) {
    if (userString == optionList[option]) {
      return true;
    }
  }
  return false;
}
