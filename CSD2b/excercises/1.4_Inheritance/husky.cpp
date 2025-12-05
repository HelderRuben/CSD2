#include "husky.h"

//Husky is a dog (constructor)
Husky::Husky(std::string name) : Dog(name) {
  std::cout << "Husky named " << name << " is born!\n";
  this->name = name;
}

//Husky destructor
Husky::~Husky() {
  std::cout << name << "(husky) ran away and never came back.\n";
}

//For when husky looks cute
void Husky::lookCool() {
  std::cout << "Aww, " << name << " is looking so COOL\n";
}
