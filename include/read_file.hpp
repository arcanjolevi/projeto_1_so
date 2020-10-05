#ifndef READ_FILE
#define READ_FILE

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool findBeginPcb (ifstream &fn);

void readId (ifstream &fn, string &id);

void readTime (ifstream &fn, int &t);

bool readFile (string file_name/*, coloca o objeto PCB aqui*/);


#endif
