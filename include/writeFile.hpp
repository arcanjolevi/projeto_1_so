#ifndef WRITE_FILE_H
#define WRITE_FILE_H
#include "roundRobin.hpp"

#include <fstream>
#include <time.h> 
#include <chrono> 
#include <ctime> 
#include <iostream>
using namespace std;

/**
 * Funtion: Print output in the RR file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void roundRobinOutput(string _string);

/**
 * Funtion: Print output in the RR file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printFileHeader(string readyList);

/**
 * Funtion: Print execution data in the output file
 * @param {process*} Running process
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecution(PCB * process);

/**
 * Funtion: Print algorithm info in the uotput file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printAlgorithmInfo(string readyList, string terminatedList);

/**
 * Funtion: Print the process terminated data
 * @param {PCB} Terminated process
 * @param {double} process resposne time
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printProcessTerminated(PCB * process, double responseTime);

/**
 * Funtion: Print execution data
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @param {double} average response time
 * @param {int} number of context changes
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionEnd(string readyList, string terminatedList, double averageResponseTime, int contextChanges);


#endif