#include "../include/roundRobin.hpp"

#include "../include/logs.hpp"
#include "../include/states.hpp"

#include "../include/writeFile.hpp"

/**
* Funtion: RR contructor
* @param {Queue} - Ready process queue
* @returns {SJF} - RR instance
* 
* @precondition: none
* @postcondition: RR created
*/
RR::RR(Queue * _ready, double _quantum){
  this->ready = _ready;
  this->terminated = new Queue();
  this->quantum = _quantum;
  this->processRunning = NULL;
  log("RR Created\n");
}



/**
* Funtion: RR destructor
* @returns {void}
* 
* @precondition: none
* @postcondition: RR destroyed
*/
RR::~RR(){
  if(ready != NULL){
    delete(ready);
    ready = NULL;
  }  
  if(processRunning != NULL){
    delete(processRunning);
    processRunning = NULL;
  }

  log("RR destroyed\n");
}



/**
* Funtion: Run ready processes
* @returns {void}
* 
* @precondition: none
* @postcondition: Processes run
*/
void RR::run(){

  

  PCB * process = new PCB();
  int antPID = -1;
  double responseTime = 0;
  double responseTimeSum = 0;
  int contextChanges = 0;
  double quantumRemainingTime = 0;  

  clearOutputFileRR();

  printFileHeaderRR(this->ready->queueToString(), this->quantum);  

  while(!this->ready->isEmpty()){     

    antPID = process->getPID();
    process->setPCB(this->ready->pop());//Pop a process of the queue of ready processes
    process->setState(State::running);//Change the state of the process to running

    this->processRunning = process;

    if(process->getPID() != -1 && antPID != -1)//Verify context change
      contextChanges++;    

    printExecutionRR(process);

    quantumRemainingTime = process->execute(this->quantum);//Execute the process over quantum

    printAlgorithmInfoRR(this->ready->queueToString(), this->terminated->queueToString());

    if(quantumRemainingTime == 0){//Process used all quantum
      responseTime+=this->quantum;
      this->ready->push(*process);
    }else{//Process used a quantum part and finished
      process->setState(State::terminated);
      responseTime += this->quantum - quantumRemainingTime;
      responseTimeSum += responseTime;
      this->terminated->push(*process);  
      this->processRunning = NULL;
      
      printProcessTerminatedRR(process, responseTime);
    }
  }

  

  delete(process);
  process = NULL;


  
  printExecutionEndRR(this->ready->queueToString(), this->terminated->queueToString(), responseTimeSum/this->terminated->getSize(), contextChanges);

  

}

