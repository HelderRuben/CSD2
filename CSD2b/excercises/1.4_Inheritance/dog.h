#pragma once
#include <iostream>
#include "pet.h"

//Class Dog *is a* pet
class Dog : public Pet {
public:
  //constructor with dog's name
  Dog(std::string name);
  //destructor
  ~Dog();

  //methods
  void bark();
};
