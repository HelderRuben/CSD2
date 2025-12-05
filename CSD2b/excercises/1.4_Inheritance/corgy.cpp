#include "corgy.h"

//Corgy is a dog (constructor)
Corgy::Corgy(std::string name) : Dog(name) {
  std::cout << "Corgy named " << name << " is born!\n";
  this->name = name;
}

//Corgy destructor
Corgy::~Corgy() {
  std::cout << name << "(corgy) wandered off and went missing.\n";
}

//For when corgy looks cute
void Corgy::lookCute() {
  std::cout << "Aww, " << name << " is looking so cute\n";
}
