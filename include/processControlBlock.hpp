#ifndef PROCESS_CONTROL_BLOCK_H
#define PROCESS_CONTROL_BLOCK_H

#include "states.hpp"

#include <iostream>
#include <string>
#include "../include/logs.hpp"

using namespace std;


/**
  * Class: Represents a process control block structure
  */
class PCB {
  private: 
    int PID;
    State state;
    PCB * next;
    double createdTime = 0;
    double estimatedTime = 0;
    double remainingTime = 0;

  public:

  /**
  * Funtion: Process control block contructor
  * @param {int} - Process ID
  * @param {double} - created Time
  * @returns {PCB} - PCB instance
  * 
  * @precondition: none
  * @postcondition: Process created, state = ready
  */
  PCB(int _PID, double _createdTime);

  /**
  * Funtion: Process control block contructor
  * @param {int} - Process ID
  * @param {double} - created Time
  * @param {double} - estimatedTime
  * @returns {PCB} - PCB instance
  * 
  * @precondition: none
  * @postcondition: Process created, state = ready
  */
  PCB(int _PID, double _createdTime, double _estimatedTime);

  /**
  * Funtion: Process control block contructor
  * @returns {PCB} - PCB instance
  * 
  * @precondition: none
  * @postcondition: Process created, state = ready, PID = -1
  */
  PCB();

  /**
  * Funtion: Set all data of PCB base in other PCB
  * @param {PCB} - Process control block
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: Al data changed
  */
  void setPCB(PCB _other);

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
  * Funtion: get the current state of the process
  * @returns {string} - Current state of the process
  * 
  * @precondition: none
  * @postcondition: none
  */
  string getStateString();

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

  /**
  * Funtion: Change the next PCB
  * @param {PCB*} - adress of the next PCB || NULL
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: this->next changed
  */
  void setNext(PCB * _next);

  /**
  * Funtion: Get the next PCB adress
  * @returns {PCB*}
  * 
  * @precondition: none
  * @postcondition: none
  */
  PCB * getNext();

  /**
  * Funtion: Get the PID
  * @returns {int}
  * 
  * @precondition: none
  * @postcondition: none
  */
  int getPID();

  /**
  * Funtion: Get the remainingTime
  * @returns {double}
  * 
  * @precondition: none
  * @postcondition: none
  */
  double getRemainingTime();

  /**
  * Funtion: Set the remainingTime
  * @param {double}
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: none
  */
  void setRemainingTime(double _remainingTime);

  /**
  * Funtion: Get the estimated time
  * @returns {double}
  * 
  * @precondition: none
  * @postcondition: none
  */
  double getEstimatedTime();

  /**
  * Funtion: Simulate the process execution
  * @param {double} - Quantum available for execution
  * @returns {double} - if the process execute throughout all quantum return 0, else return the remaining time of the quantum
  * 
  * @precondition: state = running
  * @returns {double} - Return the remaining time of the quantum
  */
  double execute(double _quantum);

};


#endif
