#include "TuringMachine.h"

//constructor using the path to init all the elements and the print steps option
TuringMachine::TuringMachine(string path, bool printSteps){
  reader.readLines(path, &elements);
  currentState = elements.getInitState().sname;
  this->printSteps = printSteps;

}

//get the tape
string TuringMachine::getTape(){
    return tape;
}

//feed the machine 1 symbol from the input
bool TuringMachine::feed(string input) {
  vector<Transition> t_set = elements.getTransitions();

  //looking for a transition matching the current state + the input
  for (int i = 0; i < t_set.size(); i++) {
    //changing the current state + updating the cursor position and the tape accordingly
    if (t_set[i].currentState == currentState && t_set[i].currentSymbol == input) {
      Transition t = t_set[i];

      //printing the operation if the "-step" option is given to the program
      if (printSteps) {
        cout << "(" << currentState << ", " << input << ") -> (" << t.nextSymbol << ", " << t.nextSymbol << ", " << t.move << ")" << endl;
      }

      currentState = t.nextState;
      writeSymbol(t.nextSymbol);
      pos += ((t.move == "R") ? t.nextSymbol.size() : -(t.nextSymbol.size()));

      //return if the current state is a final
      if (getCurrentState().isFinal) return true;
      return false;
    }
  }

  return false;
}

//write a symbol on the tape
void TuringMachine::writeSymbol(string s) {
  //if the cursor is at the left of the tape
  if (pos == -1) {
    pos = 0;
    tape = s + tape;
    return;
  }

  //if the cursor is at the right of the tape
  if (pos == tape.size()) {
    tape = tape + s;
    return;
  }

  //if the cursor is on the tape, replace the symbol on the cursor by the given one
  if (s.size() == 1) {
    tape[pos] = s[0];
    return;
  }

}

//get the current state, used by the main for the output
State TuringMachine::getCurrentState() {
  return elements.getState(currentState);
}

//feed the machine the blank symbol
bool TuringMachine::feed_blank() {
  return feed(elements.getBlank());
}
