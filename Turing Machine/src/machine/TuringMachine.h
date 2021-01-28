#ifndef __TURING_MACHINE__
#define __TURING_MACHINE__

#include <string>
#include <vector>
#include <iostream>
#include "Elements.h"
#include "Read.h"
using namespace std;

/*
  Turing machine class : the central class of the program
    -elements : attribute containing all the transitions / symbols / states of the machine
    -reader : attribute used to init the elements object from a file
    -currentState : the name of the current state, initialized with the initial state of the machine
    -tape : string representing the tape, initialized empty
    -pos : the position of the cursor on the tape

    -Constructor : need the path to the file containing the definition of the machine and the option printSteps, init elements using reader and path
    -getTape : return the tape (as a string)
    -feed : feed ONE symbol from the inputs to the machine, the tape, the pos and the current state accordingly
    -feed_blank : feed a blank symbol to the machine
    -getCurrentState : get the current state

  ADDITIONAL NOTE : in the current version, the machine can only be used with 1 characters symbols !
*/

class TuringMachine {

private:
  Elements elements;
  Read reader;

  string currentState;

  string tape;
  int pos;

  void writeSymbol(string s);
  bool printSteps;

public:
  TuringMachine(string path, bool printSteps);
  string getTape();
  bool feed(string input);
  bool feed_blank();
  State getCurrentState();

};

#endif
