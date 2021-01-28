#ifndef __ELEMENTS_H
#define __ELEMENTS_H

#include <string>
#include <vector>
#include <iostream>
#include <istream>
using namespace std;

/*
  Struct state : a machine's state
  Struct Transition : Represent one transition of the machine
  Struct symbol : A symbol

  Elements : Contains the sets of states, transitions and symbols (+ the blank symbol)
  defining the turing machine. This class is filled once with the description file and then
  used to process the input.

*/

struct State{
  string sname;
  bool isInit;
  bool isFinal;
};

struct Transition{
  string currentState;
  string currentSymbol;
  string nextState;
  string nextSymbol;
  string move;
};

struct Symbol{
  string input;
  bool isValid;
};

class Elements {

private:
  string blank;
  vector<State>stateVec;
  vector<Symbol> symbolVec;
  vector<Transition>transitionsVec;

public:
  Elements();

  void addState(string, bool, bool);
  void addTransition(string, string, string, string, string);
  void addSymbols(string, bool);
  void setBlank(string);
  string getBlank();

  State getInitState();
  vector<Transition> getTransitions();
  State getState(string name);

};

#endif
