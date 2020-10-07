#include "../include/writeFile.hpp"

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
void roundRobinOutput(string _string){
  ofstream myfile;
  auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  myfile.open ("output/roundRobin.txt", std::ios_base::app);
  myfile << _string;
  myfile.close();
}


/**
 * Funtion: Print header in the RR file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printFileHeader(string readyList){
  roundRobinOutput( "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\nShortest Job First\n▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n");
  roundRobinOutput( "\n");
  roundRobinOutput( "->Before Start Execution  \n \n");
  roundRobinOutput( "    ⇨ List of ready processes(PID): " + readyList + "\n");
}

/**
 * Funtion: Print execution data in the output file
 * @param {process*} Running process
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecution(PCB * process){
    roundRobinOutput( "\n ════════════════════════════════════════════════════════\n");  
    roundRobinOutput( "->Execution: \n \n");
    roundRobinOutput( "    ⇨ Process selected for execution(Running):\n        ⇝ PID: ");
    roundRobinOutput( to_string(process->getPID()));
    roundRobinOutput(", Estimated Time: ");
    roundRobinOutput(to_string(process->getEstimatedTime()));
    roundRobinOutput( ", Remaining Time: " + to_string(process->getRemainingTime()) + "\n" + "\n");
}

/**
 * Funtion: Print algorithm info in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printAlgorithmInfo(string readyList, string terminatedList){
  roundRobinOutput("    ⇨ List of ready processes:\n");
  roundRobinOutput( "        ⇝ " + readyList + "\n\n");
    
  roundRobinOutput( "    ⇨ List of terminated processes:\n");
  roundRobinOutput( "        ⇝ " + terminatedList + "\n\n");
}

/**
 * Funtion: Print the process terminated data in the output file
 * @param {PCB} Terminated process
 * @param {double} process resposne time
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printProcessTerminated(PCB * process, double responseTime){
  roundRobinOutput( "\n════════════════════════════════════════════════════════\n");
  roundRobinOutput( "->Process terminated:\n\n");
  roundRobinOutput( "   ⇨ PID: " + to_string(process->getPID()) + "\n");
  roundRobinOutput( "        Estimated Time: " + to_string(process->getEstimatedTime()) + "\n");
  roundRobinOutput( "        Remaining Time: " + to_string(process->getRemainingTime()) + "\n");
  roundRobinOutput( "        Response Time: "+ to_string(responseTime) + "\n");
  roundRobinOutput( "        Process State: "+ process->getStateString() + "\n");
}

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
void printExecutionEnd(string readyList, string terminatedList, double averageResponseTime, int contextChanges){

  roundRobinOutput( "▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n\n->Execution end:\n\n");

  roundRobinOutput( "    ⇨ List of ready processes:\n");
  roundRobinOutput( "        ⇝ " + readyList +"\n\n");

  roundRobinOutput( "    ⇨ List of terminated processes:\n");
  roundRobinOutput( "        ⇝ " + terminatedList + "\n\n");

  roundRobinOutput( "    ⇨ Average response time:");
  roundRobinOutput( to_string(averageResponseTime) + "\n\n");

  roundRobinOutput( "    ⇨ Context changes:");
  roundRobinOutput( to_string(contextChanges) + "\n\n");
}