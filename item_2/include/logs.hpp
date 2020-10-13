#ifndef LOGS_H
#define LOGS_H

#include <fstream>
#include <time.h> 
#include <chrono> 
#include <ctime> 
#include <iostream>
using namespace std;

/**
 * Function: Print log in the log file
 * @param {string} log message
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void log(string _log);

/**
 * Function: Clear logs file
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: Logs file cleared
 */
void clearLogsFile();


#endif