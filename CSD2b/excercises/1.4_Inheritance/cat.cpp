//What this cat can do:
  //Constructor makes Cat
  //.sleep makes it sleep
  //.eat makes it eat
  //.climb makes it climb
  //Destructor destructs Cat
#include "cat.h"

Cat::Cat(std::string name) : Pet(name) {
  std::cout << "Cat named " << name << " is born!\n";
  this->name = name;
}

Cat::~Cat() {
  std::cout << name << "(cat) is gone.\n";
}

void Cat::climb() {
  std::cout << "Watch out, " << name << " is climbing everywhere\n";
}
