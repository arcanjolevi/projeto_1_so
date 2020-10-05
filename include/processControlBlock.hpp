#ifndef PROCESS_CONTROL_BLOCK_H
#define PROCESS_CONTROL_BLOCK_H

#include "states.hpp"

class PCB {
  private: 
    int PID;
    State state;
    int createdTime = 0;

  public:

  /**
  * Funtion: Process control block contructor
  * @param {int} - Process ID
  * @param {int} - created Time
  * @returns {PCB} - PCB instance
  * 
  * @precondition: none
  * @postcondition: Process created, state = ready
  */
  PCB(int _PID, int _createdTime);

  /**
  * Funtion: Change the process state
  * @param {State} - Process state
  * @returns {bool} if opration performed then true else false
  * 
  * @precondition: process not terminated
  * @postcondition: Process state changed
  */
  bool setState(State _state);

  /**
  * Funtion: get the current state od the process
  * @returns {State} - Current state of the process
  * 
  * @precondition: none
  * @postcondition: none
  */
  State getState();

  /**
  * Funtion: Print the current data of PCB
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: none
  */
  void show();

  /**
  * Funtion: PCB desctructor
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: none
  */
  ~PCB();

};


#endif