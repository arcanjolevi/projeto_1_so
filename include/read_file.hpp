#ifndef READ_FILE
#define READ_FILE

#include "queue.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

/**
 * function: take the digits from the beginning of a string
 * @param {string} - a line from the file
 * @returns {string} - the digits that appears in the begin of the string

* @precondition: none
* @postcondition: none
 */
string lineToDigit(string line);

/**
 * function: read from file the total number of process from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {int} - the total number of process

 * @precondition: none
 * @postcondition: none
 */
int readNumberProcesses(ifstream &fn);

/**
 * function: read from file the process identification from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {int} - the PID of process

 * @precondition: none
 * @postcondition: none
 */
int readPid (ifstream &fn);

/**
 * function: read a string from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {string} - Name of the process

 * @precondition: none
 * @postcondition: none
 */
string readName (ifstream &fn);


/**
 * function: read a float point from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {double} - time

 * @precondition: none
 * @postcondition: none
 */
double readTime (ifstream &fn);

/**
 * Funtion: controls file reading
 * @param {file_name} - the name or path associated with a file
 * @param {readyProcesses} - the linked list of all ready processes
 * @param {quantum} - a pointer to the duration of a quantum
 * @param {isRR} - allow the function to fill the list to both algorithms
 * @returns {bool} - true = read the file correctly

 * @precondition: none
 * @postcondition: none
 */
bool readFile (string file_name, Queue * readyProcesses, double * quantum, bool isRR);

#endif
