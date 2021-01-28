#include "Read.h"

//For a short description of these methods, see Read.h

Read::Read(){}

//classic c++ code to read a file line by line
void Read::readLines(string path, Elements *el){
  string line;
  ifstream file_obj(path.c_str());
  if (file_obj.is_open()){
    while (getline(file_obj, line)){
        readWords(line, el);
    }
    file_obj.close();
  }else{
    cout << "No file found, check your file path : " << path << endl;
  }
}

//just playing with strings, lines pattern : INSTRUCTION(PARAMETERS)
void Read::readWords(string l, Elements *e){
  string delimiter1 = "(";
  string delimiter2 = ")";

  size_t d1_pos = l.find(delimiter1);
  size_t d2_pos = l.find(delimiter2);

  if (d1_pos == string::npos || d2_pos == string::npos) {
    cout << "Bad formating in line : '" << l << "'. Ignoring this line." << endl;
    return;
  }

  regex rgx ("[(,)]");

  sregex_token_iterator iter(l.begin(), l.end(), rgx, -1);
  sregex_token_iterator end;
  vector<string>temp;

  while(iter != end){
    temp.push_back(*iter);
    iter++;
  }

  //processing all the *valid* possibilities
  for (int i = 0; i <temp.size(); ++i) {
    if (temp[i]== "initial") {
      e->addState(temp[i+1], true, false);
    }else if(temp[i] == "state") {
      if(temp[i+2]=="T") {
        e->addState(temp[i+1],false, true);//(Done, T) Final state.
      } else{
        e->addState(temp[i+1],false, false);// (Done,F) | neither Init nor Finale.
      }
    } else if(temp[i] == "blank") {
        e->setBlank(temp[i+1]);
    } else if(temp[i]=="symbol") {
      if(temp[i+2]=="T"){
        e->addSymbols(temp[i+1], true);// Input valid
      } else {
        e->addSymbols(temp[i+1], false); // Input not valid
        cout << "a symbol red is not valid : '" << temp[i+1]<< "' On line "<< l <<endl;
      }
    } else if(temp[i]=="transition") {
        e->addTransition(temp[i+1], temp[i+2], temp[i+3], temp[i+4], temp[i+5]);
    }
  }
}
