#include "../include/shortestJobFirst.hpp"
#include "../include/logs.hpp"


/**
* Funtion: SJF contructor
* @param {Queue} - Ready process queue
* @returns {SJF} - SJF instance
* 
* @precondition: none
* @postcondition: SJF created
*/
SJF::SJF(Queue * _ready){
  this->ready = _ready;
  this->terminated = new Queue();
}


/**
* Funtion: SJF destructor
* @returns {void}
* 
* @precondition: none
* @postcondition: SJF destroyed
*/
SJF::~SJF(){
  log("SJF destroyed\n");
}

/**
* Funtion: Run ready processes
* @returns {void}
* 
* @precondition: ready queue not empty
* @postcondition: Processes run
*/
void SJF::run(){  

  PCB running;

  
  running = this->ready->pop();
  cout << "Running: " << running.getPID() << " - ";
  cout << "Ready: " << this->ready->queueToString() << " - \n";

  while(!this->ready->isEmpty()){
    
    
    running = this->ready->pop();
    this->running = running;
    cout << "Running: " << running.getPID() << " - ";
    cout << "Ready: " << this->ready->queueToString() << " - \n";
  }
}