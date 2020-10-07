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
  log("SJF Created\n");
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
  int antPID = running.getPID();
  int responseTime = 0;
  int responseTimeSum = 0;
  int contextChanges = 0;

  cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\nShortest Job First\n▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n";
  cout << endl;
  cout << "->Before Start Execution" << endl << endl;
  //Print the queue of ready processes
  cout << "    ⇨ List of ready processes(PID): " << this->ready->queueToString() << endl;

  while(!this->ready->isEmpty()){  
    cout << endl << "════════════════════════════════════════════════════════" << endl;  
    cout << "->Execution:" << endl << endl;
    cout << "    ⇨ Process selected for execution(Running):\n        ⇝ PID: ";

    antPID = running.getPID();
    running = this->ready->pop();
    this->running = running;

    if(running.getPID() != -1 && antPID != -1)
      contextChanges++;

    cout << running.getPID() << ", Estimated Time: " << running.getEstimatedTime();
    responseTime+= running.getEstimatedTime();
    responseTimeSum += responseTime;
    cout << ", Response Time: "<< responseTime << endl << endl;
    
    cout << "    ⇨ List of ready processes:" << endl;
    cout << "        ⇝ " << this->ready->queueToString() << endl << endl;
      
    cout << "    ⇨ List of terminated processes:" << endl;
    cout << "        ⇝ " << this->terminated->queueToString() << endl << endl;

   
    this->terminated->push(running);  
    
    
  }


  cout << "▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n\n->Execution end:" << endl << endl;

  cout << "    ⇨ List of ready processes:" << endl;
  cout << "        ⇝ " << this->ready->queueToString() << endl << endl;

  cout << "    ⇨ List of terminated processes:" << endl;
  cout << "        ⇝ " << this->terminated->queueToString() << endl << endl;

  cout << "    ⇨ Average response time:";
  cout << responseTimeSum/this->terminated->getSize() << endl << endl;

  cout << "    ⇨ Context changes:";
  cout << contextChanges << endl << endl;
}