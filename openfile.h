/***********************************************************
Name: Cory Munselle
Assignment: 04
Purpose: has all of the necessary includes and function prototypes for openfile.cpp
Notes: 
***********************************************************/

#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

bool dumpToArray(string, vector<float>*);

#endif /* OPEN_FILE_H */