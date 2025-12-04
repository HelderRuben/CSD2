//Assignment 3 overgetypt + commentary, with added woofer

//I structured the console feedback around steps, so I know the flow of the program.

#include <iostream>

//New class inside speaker: tweeter
class Tweeter{
//public means accessible from any function
public:
  //constructor: automatically called when the object is created (same name as class)
  Tweeter();
  //overloaded constructor: different constructor for same object for when the
  //object is called with specific parameters, in this case a diameter
  Tweeter(float diam);

  //fields: variables belonging to object, with specific data types
  float diameter;
  float conePosition;

  //Delegating constructors gives error "permitted only in C++11"
  //Therefore an Initialization function for removing duplicate code:
  void init() {
    diameter = 2.5f;
    conePosition = 0.0f;
  }
};

//constructor with no paramteres defined
Tweeter::Tweeter(){
  //using the console to say the default constructor is used, \n for enter
  std::cout << "Step 1: Tweeter default constructor init by Speaker\n";
  //Initializing fields
  init();
};
//Constructor delegation:
Tweeter::Tweeter(float diam) {
  std::cout << "Step 1: Tweeter constructor with float diam parameter init by Speaker\n";
  init();
  this->diameter = diam;
};

//Adding woofer object
class Woofer {
public:
  //default constructor
  Woofer();
  //constructor with diameter and shape
  Woofer(float diam);
  float diameter;
};

Woofer::Woofer() {
  std::cout << "Step 2: Woofer default constructor init by Speaker\n";
  //Standard value of diameter
  diameter = 6;
};

Woofer::Woofer(float diam) {
  std::cout << "Step 2: Woofer constructor with float diameter init by Speaker\n";
  //Variable value of diameter
  diameter = diam;
};

//Speaker class
class Speaker {
//Accessible anywhere
public:
  //Default constructor with standard values for Tweeter and Woofer
  Speaker();
  //Constructor with variable values for Tweeter and Woofer
  Speaker(float tweeterDiam, float wooferDiam);
  //Adding objects
  //a speaker *has a* tweeter and *has a* woofer
  Tweeter TweeterInSpeaker;
  Woofer WooferInSpeaker;
};

Speaker::Speaker() {
  std::cout << "Step 3: Inside Speaker default constructor\n";

  //define diameter value
  TweeterInSpeaker.diameter = 2.9;
  std::cout << "Step 4: The tweeter-diameter is: " << TweeterInSpeaker.diameter << "\n";
  WooferInSpeaker.diameter = 5;
  std::cout << "Step 5: The Woofer-diameter is: " << WooferInSpeaker.diameter << "\n";
};

Speaker::Speaker(float tweeterDiam, float wooferDiam) {
  std::cout << "Step 3: Inside Speaker second constructor with diameters defined\n";
  //define diameter value
  TweeterInSpeaker.diameter = tweeterDiam;
  std::cout << "Step 4: The tweeter-diameter is: " << TweeterInSpeaker.diameter << "\n";
  WooferInSpeaker.diameter = wooferDiam;
  std::cout << "Step 5: The Woofer-diameter is: " << WooferInSpeaker.diameter << "\n";
};

//Testing
int main() {
  std::cout << "MAKING FIRST SPEAKER\n";
  Speaker SpeakerOne;
  std::cout << "MAKING SECOND SPEAKER WITH DIFFERENT VALUES\n";
  Speaker SpeakerTwo(2, 4);
  //In console: Step-by-step of making 2 speakers with tweeter and woofer
};
