#pragma once
#include <iostream>
#include "pet.h"

//Class Cat *is a* pet
class Cat : public Pet {
public:
  //constructor
  Cat(std::string name);
  //destructor
  ~Cat();

  //methods
  void climb();
};
