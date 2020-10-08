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
 * Funtion: Clear file for output
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void clearOutputFileRR();

/**
 * Funtion: Clear file for output
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void clearOutputFileSJF();

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
 * Funtion: Print output in the SJF file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void SJFOutput(string _string);

/**
 * Funtion: Print output in the RR file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printFileHeaderRR(string readyList, double quantum);

/**
 * Funtion: Print output in the SJF file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printFileHeaderSJF(string readyList);

/**
 * Funtion: Print execution data in the output file
 * @param {process*} Running process
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionRR(PCB * process);

/**
 * Funtion: Print algorithm info in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printAlgorithmInfoRR(string readyList, string terminatedList);

/**
 * Funtion: Print the process terminated data in the output file
 * @param {PCB} Terminated process
 * @param {double} process resposne time
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printProcessTerminatedRR(PCB * process, double responseTime);

/**
 * Funtion: Print execution data int the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @param {double} average response time
 * @param {int} number of context changes
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionEndRR(string readyList, string terminatedList, double averageResponseTime, int contextChanges);



/**
 * Funtion: Print execution data in the output file
 * @param {process*} Running process
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionSJF(PCB * process);

/**
 * Funtion: Print algorithm info in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printAlgorithmInfoSJF(string readyList, string terminatedList);

/**
 * Funtion: Print the process terminated data int the output file
 * @param {PCB} Terminated process
 * @param {double} process resposne time
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printProcessTerminatedSJF(PCB * process, double responseTime);

/**
 * Funtion: Print execution data in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @param {double} average response time
 * @param {int} number of context changes
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionEndSJF(string readyList, string terminatedList, double averageResponseTime, int contextChanges);

#endif