#pragma once
#include <iostream>

class Pet {
public:
  //constructor
  Pet(std::string name);
  //destructor
  ~Pet();

  //methods
  void sleep();
  void eat();

protected:
  std::string name;
};
