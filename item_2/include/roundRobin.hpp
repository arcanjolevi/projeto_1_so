#ifndef RR_H
#define RR_H

#include "queue.hpp"
#include "../include/logs.hpp"
#include "../include/states.hpp"

#include "../include/writeFile.hpp"

/**
  * Class: Represents a RR algorithm
  */
class RR{
  private:
    Queue * ready;   
    Queue * terminated; 
    PCB * processRunning;    
    double quantum;
    

  public:

  /**
  * Function: RR contructor
  * @param {Queue} - Ready process queue
  * @returns {SJF} - RR instance
  * 
  * @precondition: none
  * @postcondition: RR created
  */
  RR(Queue * _ready, double _quantum);

  /**
  * Function: RR destructor
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: RR destroyed
  */
  ~RR();

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
