#ifndef SJF_H
#define SJF_H

#include "queue.hpp"
#include "../include/logs.hpp"
#include "../include/states.hpp"
#include "../include/writeFile.hpp"

/**
  * Class: Represents a SJF algorithm
  */
class SJF{
  private:
    Queue * ready;
    Queue * terminated;
    PCB * processRunning;
    
  public:

  /**
  * Function: SJF contructor
  * @param {Queue} - Ready process queue
  * @returns {SJF} - SJF instance
  * 
  * @precondition: none
  * @postcondition: SJF created
  */
  SJF(Queue * _ready);

  /**
  * Function: SJF destructor
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: SJF destroyed
  */
  ~SJF();

  /**
  * Function: Run ready processes
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: Processes run
  */
  void run();
};


#endif
