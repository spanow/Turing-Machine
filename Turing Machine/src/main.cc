#include <iostream>
#include "machine/Read.h"
#include "machine/Elements.h"
#include "machine/TuringMachine.h"

using namespace std;

int main(int argc, char *argv[]){
  //-------- Acquiring arguments --------//

  if (argc <= 3) {
    cout << "Missing parameters, found " << argc - 1 << ", expected at least 3 !" << endl;
    return 0;
  }

  //variables created to store the arguments values
  bool showSteps = false;
  bool showState = false;
  bool showTape = false;
  string path = "";
  string input = "";


  //get the -steps, -state, -tape options
  for (int i = 1; i < argc - 2; i++) {
    string s(argv[i]); // convert char* -> string
    showSteps = ((s == "-steps") ? true : showSteps);
    showState = ((s == "-state") ? true : showState);
    showTape = ((s == "-tape") ? true : showTape);
  }

  //get path and input
  path = argv[argc - 2];
  input = argv[argc - 1];

  //-------- Starting the turing machine / tests --------//

  TuringMachine tm(path, showSteps);
  bool done = false;
  for (int i = 0; i < input.size(); i++) {
    string s(1, input[i]); //just to transform char -> string
    done = tm.feed(s); // done = true if the symbol fed leads the machine to a final state
    if (done) break; //if the actual machine state is final, stop the execution
  }

  //the input is virtually filled with blanks at the end (contnue until reaching a final state)
  while (!done) done = tm.feed_blank();

  //if the option is set, show the final machine state
  if (showState) {
    cout << "Final State: " << tm.getCurrentState().sname << endl;
  }

  //if the option is set, show the final tape
  if (showTape) {
    cout << "Final Tape: " << tm.getTape() << endl;
  }

  return 0;
}
