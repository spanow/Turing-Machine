#include "Elements.h"

//Empty constructor
Elements::Elements(){}

//Add a state to the machine
void Elements::addState(string stateName, bool init, bool done){
  State s;

  s.sname = stateName;
  s.isInit = init;
  s.isFinal = done;

  stateVec.push_back(s);
}

//Add a transition between two states
void Elements::addTransition(string currS, string currSym,
                             string nextS, string nextSym, string mv){
  Transition t;

  t.currentState = currS;
  t.currentSymbol = currSym;
  t.nextState = nextS;
  t.nextSymbol = nextSym;
  t.move = mv;

  transitionsVec.push_back(t);
}

//Add a symbol to the machine's symbole set
void Elements::addSymbols(string in, bool isVal){
  Symbol sym;

  sym.input = in;
  sym.isValid = isVal;

  symbolVec.push_back(sym);
}

//set the blank symbol
void Elements::setBlank(string b){
  this->blank = b;
}

//get the blank symbol
string Elements::getBlank(){
  return blank;
}

//get the initial state
State Elements::getInitState() {
  State res;
  for (int i = 0; i < stateVec.size(); i++) {
    if (stateVec[i].isInit) res = stateVec[i];
  }

  return res;
}

//get all the transitions
vector<Transition> Elements::getTransitions() {
  return transitionsVec;
}

//get the state with the given name <- all the states name must be unique !
State Elements::getState(string name) {
  State res;

  for (int i = 0; i < stateVec.size(); i++) {
    if (stateVec[i].sname == name) res = stateVec[i];
  }

  return res;
}
