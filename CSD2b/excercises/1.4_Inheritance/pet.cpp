//What this object can do:
  //It can be made with constructor
  //It can sleep (method)
  //It can eat (method)
  //It can be destructed with constructor


#include "pet.h"

//constructor
Pet::Pet(std::string name) {
  std::cout << "Pet constructor, name is " << name << "\n";
  //define pet name
  this->name = name;
}

//destructor
Pet::~Pet() {
  std::cout << "Pet destructed, name was " << name << "\n";
}

//sleep method
void Pet::sleep() {
  std::cout << "Be quiet, " << name << " is asleep\n";
}

//eat method
void Pet::eat() {
  std::cout << name << "is eating\n";
}
