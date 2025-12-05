#include "dog.h"

//constructor and Dog part of Pet class
Dog::Dog(std::string name) : Pet(name) {
  std::cout << "Dog named " << name << " is born!\n";
  this->name = name;
}

//destructor
Dog::~Dog() {
  std::cout << name << "(dog) is no more.\n";
}

//barking method
void Dog::bark() {
  std::cout << name << " says WOOF\n";
}
