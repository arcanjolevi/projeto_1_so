#ifndef READ_FILE
#define READ_FILE

#include "queue.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string lineToDigit(string line);

void readNumberProcesses(ifstream &fn);

int readPid (ifstream &fn);

double readTime (ifstream &fn);

string readState (ifstream &fn);

bool readFile (string file_name/*, PCB*/, Queue * readyProcesses, double * quantum);

#endif
