#include "../include/logs.hpp"

/**
 * Function: Print log in the log file
 * @param {string} log message
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void log(string _log){
  ofstream myfile;
  auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  myfile.open ("logs/logFile.txt", std::ios_base::app);
  myfile << ctime(&timenow) << _log << "\n-------------------------------------\n";
  myfile.close();
}