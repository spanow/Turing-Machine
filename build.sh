#!/bin/sh
#using c++11 fonctionnalities !
g++ -std=gnu++0x -o Turing src/main.cc src/machine/Elements.cc src/machine/Read.cc src/machine/TuringMachine.cc

#Exemple of execution
./Turing -steps -state -tape machines_test/RandomTest2.tm 1100
