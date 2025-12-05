#pragma once
#include <iostream>
#include "dog.h"

//Class Corgy *is a* Dog
class Corgy : public Dog {
public:
  //constructor
  Corgy(std::string name);
  //destructor
  ~Corgy();

  //methods
  void lookCute();
};
