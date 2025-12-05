#pragma once
#include <iostream>
#include "dog.h"

//Class Husky *is a* Dog
class Husky : public Dog {
public:
  //constructor
  Husky(std::string name);
  //destructor
  ~Husky();

  //methods
  void lookCool();
};
