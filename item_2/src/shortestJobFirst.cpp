#include "../include/shortestJobFirst.hpp"

/**
* Function: SJF contructor
* @param {Queue} - Ready process queue
* @returns {SJF} - SJF instance
* 
* @precondition: none
* @postcondition: SJF created
*/
SJF::SJF(Queue * _ready){
  this->ready = _ready;
  this->terminated = new Queue();
  log("SJF Created\n");
}


/**
* Function: SJF destructor
* @returns {void}
* 
* @precondition: none
* @postcondition: SJF destroyed
*/
SJF::~SJF(){

  if(ready != 0){
    delete(ready);
    ready = NULL;
  }
  if(processRunning != 0){
    delete(processRunning);
    processRunning = NULL;
  }
  log("SJF destroyed\n");
}

/**
* Function: Run ready processes
* @returns {void}
* 
* @precondition: ready queue not empty
* @postcondition: Processes run
*/
void SJF::run(){  

  PCB * process = new PCB();
  int antPID = -1;
  double responseTime = 0;
  double responseTimeSum = 0;
  int contextChanges = 0; 

  clearOutputFileSJF();

  printFileHeaderSJF(this->ready->queueToString()); 

  while(!this->ready->isEmpty()){    

    antPID = process->getPID();
    process->setPCB(this->ready->pop());//Pop a process of the queue of ready processes
    process->setState(State::running);//Change the state of the process to running

    this->processRunning = process;

    if(process->getPID() != -1 && antPID != -1)//Verify context change
      contextChanges++; 

    printExecutionSJF(process);
    
    
    
    printAlgorithmInfoSJF(this->ready->queueToString(), this->terminated->queueToString());
    

    process->execute(process->getRemainingTime());

    if(process->getRemainingTime() == 0){//Process terminated
      process->setState(State::terminated);
      responseTime+= process->getEstimatedTime();
      responseTimeSum += responseTime;

      printProcessTerminatedSJF(process, responseTime);
    }
    this->terminated->push(*process);  
    this->processRunning = NULL;
    
  }

  delete(process);
  process = NULL;

  printExecutionEndSJF(this->ready->queueToString(), this->terminated->queueToString(), responseTimeSum/this->terminated->getSize(), contextChanges);
}
