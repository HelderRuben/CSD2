

//Icluding Header files of classes
#include "dog.h"

#include <iostream>

int main() {

  //Make a pet

  //Pet does something
  std::cout << "    LIFE STORY OF BARRY THE DOG:\n";
  Dog testDog("Barry");
  testDog.sleep();
  testDog.eat();
  testDog.bark();
  testDog.sleep();
  testDog.bark();
  testDog.bark();
  testDog.sleep();
  //Ending program
  return 0;
};
