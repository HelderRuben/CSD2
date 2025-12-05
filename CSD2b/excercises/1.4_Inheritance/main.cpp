

//Icluding Header files of classes
#include "dog.h"
#include "cat.h"

#include <iostream>

int main() {
  //Dog named Barry
  std::cout << "    LIFE STORY OF BARRY THE DOG:\n";
  Dog dogObj("Barry");
  dogObj.sleep();
  dogObj.eat();
  dogObj.bark();
  dogObj.sleep();
  dogObj.bark();
  dogObj.bark();
  dogObj.sleep();

  //Cat named Herculus
  std::cout << "    LIFE STORY OF HERCULUS THE CAT:\n";
  Cat catObj("Herculus");
  catObj.sleep();
  catObj.eat();
  catObj.climb();
  catObj.sleep();
  catObj.climb();
  catObj.climb();
  catObj.sleep();

  //Ending program
  std::cout << "    SAY BYE BYE TO BARRY AND HERCULUS\n";
  return 0;
};
