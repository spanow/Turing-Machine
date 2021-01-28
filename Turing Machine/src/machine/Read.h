#ifndef __READ_H__
#define __READ_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "Elements.h"
using namespace std;

/*
  Low level class made to read the description file and fill an instance of Elements (see Elements.h for a short description)

  readLines : read every lines from the description file
  readWords : From one line, extract an instruction and its parameters
*/

class Read{
  private:
    string filePath;
  public:
    Read();
    void readLines(string, Elements*);
    void readWords(string, Elements*);
};

#endif
