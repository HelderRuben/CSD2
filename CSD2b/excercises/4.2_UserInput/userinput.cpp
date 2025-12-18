#include <iostream>
#include <string>

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

float UserInput::UIReturnString(array optionList) {
  //Asking questions
  std::cout << "\nType one of these options to choose:";
  for (option in optionList.length) {
    std::cout << "\n" << optionList[option];
  };
  std::cout << "\n";
  //don't know what im doing here, this looks more like pseudo code

  std::cin >> string userString;
  //and then check for legitness
  return userFloat;
}
