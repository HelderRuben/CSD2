

//Icluding Header files of classes
#include "dog.h"
#include "cat.h"
#include "corgy.h"
#include "husky.h"

#include <iostream>

int main() {
  //Dog named Barry
  std::cout << "    BARRY THE DOG:\n";
  Dog dogObj("Barry");
  dogObj.sleep();
  dogObj.eat();
  dogObj.bark();

  //Cat named Herculus
  std::cout << "    HERCULUS THE CAT:\n";
  Cat catObj("Herculus");
  catObj.sleep();
  catObj.eat();
  catObj.climb();

  //Corgy named Pip
  std::cout << "    PIP THE CORGY:\n";
  Corgy corgyObj("Pip");
  corgyObj.sleep();
  corgyObj.eat();
  corgyObj.bark();
  corgyObj.lookCute();

  //Cat named Herculus
  std::cout << "    XANDER THE HUSKY:\n";
  Husky huskyObj("Xander");
  huskyObj.sleep();
  huskyObj.eat();
  huskyObj.bark();
  huskyObj.lookCool();

  //Ending program
  std::cout << "    SAY BYE BYE TO ALL THE PETS\n";
  return 0;
};
