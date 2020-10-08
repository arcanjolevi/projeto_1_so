#ifndef SJF_H
#define SJF_H

#include "queue.hpp"

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
  * Funtion: SJF contructor
  * @param {Queue} - Ready process queue
  * @returns {SJF} - SJF instance
  * 
  * @precondition: none
  * @postcondition: SJF created
  */
  SJF(Queue * _ready);

  /**
  * Funtion: SJF destructor
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: SJF destroyed
  */
  ~SJF();

  /**
  * Funtion: Run ready processes
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: Processes run
  */
  void run();
};


#endif