#include "../include/writeFile.hpp"

/**
 * Function: Clear file for output
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void clearOutputFileRR(){
  ofstream myfile;
  auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  myfile.open ("output/roundRobin.txt");
  myfile << "[roundRobin.txt]\n\n";
  myfile.close();
}


/**
 * Function: Clear file for output
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void clearOutputFileSJF(){
  ofstream myfile;
  auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  myfile.open ("output/shortestJobFirst.txt");
  myfile << "[shortestJobFirst.txt]\n\n";
  myfile.close();
}


/**
 * Function: Print output in the RR file
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
 * Function: Print output in the RR file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void sjfOutput(string _string){
  ofstream myfile;
  auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  myfile.open ("output/shortestJobFirst.txt", std::ios_base::app);
  myfile << _string;
  myfile.close();
}


/**
 * Function: Print header in the RR file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printFileHeaderRR(string readyList, double quantum){
  roundRobinOutput( "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\nRound Robin\n    ->Quantum:" + to_string(quantum) +"\n▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n");
  roundRobinOutput( "\n");
  roundRobinOutput( "->Before Start Execution  \n \n");
  roundRobinOutput( "    ⇨ List of ready processes(PID): " + readyList + "\n");
}


/**
 * Function: Print output in the SJF file
 * @param {string} Data
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printFileHeaderSJF(string readyList){
  sjfOutput( "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\nShortest Job First\n▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n");
  sjfOutput( "\n");
  sjfOutput( "->Before Start Execution  \n \n");
  sjfOutput( "    ⇨ List of ready processes(PID): " + readyList + "\n");
}

/**
 * Function: Print execution data in the output file
 * @param {process*} Running process
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionRR(PCB * process){
    roundRobinOutput( "\n ════════════════════════════════════════════════════════\n");  
    roundRobinOutput( "->Execution: \n \n");
    roundRobinOutput( "    ⇨ Process selected for execution(Running):\n        ⇝ Process: " + process->getName() + ", PID: ");
    roundRobinOutput( to_string(process->getPID()));
    roundRobinOutput(", Estimated Time: ");
    roundRobinOutput(to_string(process->getEstimatedTime()));
    roundRobinOutput( ", Remaining Time: " + to_string(process->getRemainingTime()) + "\n" + "\n");
}

/**
 * Function: Print algorithm info in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printAlgorithmInfoRR(string readyList, string terminatedList){
  roundRobinOutput("    ⇨ List of ready processes:\n");
  roundRobinOutput( "        ⇝ " + readyList + "\n\n");
  roundRobinOutput( "    ⇨ List of terminated processes:\n");
  roundRobinOutput( "        ⇝ " + terminatedList + "\n\n");
}

/**
 * Function: Print the process terminated data in the output file
 * @param {PCB} Terminated process
 * @param {double} process resposne time
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printProcessTerminatedRR(PCB * process, double responseTime){
  roundRobinOutput( "\n════════════════════════════════════════════════════════\n");
  roundRobinOutput( "->Process terminated:\n\n");
  roundRobinOutput( "   ⇨ Process: " + process->getName() + ", PID: " + to_string(process->getPID()) + "\n");
  roundRobinOutput( "        Estimated Time: " + to_string(process->getEstimatedTime()) + "\n");
  roundRobinOutput( "        Remaining Time: " + to_string(process->getRemainingTime()) + "\n");
  roundRobinOutput( "        Response Time: "+ to_string(responseTime) + "\n");
  roundRobinOutput( "        Process State: "+ process->getStateString() + "\n");
}

/**
 * Function: Print execution data in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @param {double} average response time
 * @param {int} number of context changes
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionEndRR(string readyList, string terminatedList, double averageResponseTime, int contextChanges){

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


/**
 * Function: Print execution data in the output file
 * @param {process*} Running process
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionSJF(PCB * process){
  sjfOutput( "\n ════════════════════════════════════════════════════════\n");  
  sjfOutput( "->Execution: \n \n");
  sjfOutput( "    ⇨ Process selected for execution(Running):\n        ⇝ Process: " + process->getName() + ", PID: ");
  sjfOutput( to_string(process->getPID()));
  sjfOutput(", Estimated Time: ");
  sjfOutput(to_string(process->getEstimatedTime()));
  sjfOutput( ", Remaining Time: " + to_string(process->getRemainingTime()) + "\n" + "\n");
}

/**
 * Function: Print algorithm info in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printAlgorithmInfoSJF(string readyList, string terminatedList){
  sjfOutput("    ⇨ List of ready processes:\n");
  sjfOutput( "        ⇝ " + readyList + "\n\n");
  sjfOutput( "    ⇨ List of terminated processes:\n");
  sjfOutput( "        ⇝ " + terminatedList + "\n\n");
}

/**
 * Function: Print the process terminated data int the output file
 * @param {PCB} Terminated process
 * @param {double} process resposne time
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printProcessTerminatedSJF(PCB * process, double responseTime){
  sjfOutput( "\n════════════════════════════════════════════════════════\n");
  sjfOutput( "->Process terminated:\n\n");
  sjfOutput( "   ⇨ Process: " + process->getName() + ", PID: " + to_string(process->getPID()) + "\n");
  sjfOutput( "        Estimated Time: " + to_string(process->getEstimatedTime()) + "\n");
  sjfOutput( "        Remaining Time: " + to_string(process->getRemainingTime()) + "\n");
  sjfOutput( "        Response Time: "+ to_string(responseTime) + "\n");
  sjfOutput( "        Process State: "+ process->getStateString() + "\n");
}

/**
 * Function: Print execution data in the output file
 * @param {string} Algorithm ready processes list
 * @param {string} Algorithm terminated processes list
 * @param {double} average response time
 * @param {int} number of context changes
 * @returns {void}
 * 
 * @precondition: none
 * @postcondition: none
 */
void printExecutionEndSJF(string readyList, string terminatedList, double averageResponseTime, int contextChanges){
  sjfOutput( "▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n\n->Execution end:\n\n");
  sjfOutput( "    ⇨ List of ready processes:\n");
  sjfOutput( "        ⇝ " + readyList +"\n\n");
  sjfOutput( "    ⇨ List of terminated processes:\n");
  sjfOutput( "        ⇝ " + terminatedList + "\n\n");
  sjfOutput( "    ⇨ Average response time:");
  sjfOutput( to_string(averageResponseTime) + "\n\n");
  sjfOutput( "    ⇨ Context changes:");
  sjfOutput( to_string(contextChanges) + "\n\n");
}
