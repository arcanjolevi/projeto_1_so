#include "../include/processControlBlock.hpp"
#include "../include/logs.hpp"
#include <string>
using namespace std;

/**
* Funtion: Process control block contructor
* @param {int} - Process ID
* @param {int} - created Time
* @returns {PCB} - PCB instance
* 
* @precondition: none
* @postcondition: Process created, state = ready
*/
PCB::PCB(int _PID, int _createdTime){
  this->PID = _PID;
  this->createdTime = _createdTime;
  this->state = ready;
}


/**
* Funtion: Change the process state
* @param {State} - Process state
* @returns {bool} if opration performed then true else false
* 
* @precondition: process not terminated
* @postcondition: Process state changed
*/
bool PCB::setState(State _state){
  if(this->state != terminated){
    this->state = _state;
    return true;
  }
  
  return false;
  
}


/**
* Funtion: get the current state od the process
* @returns {State} - Current state of the process
* 
* @precondition: none
* @postcondition: none
*/
State PCB::getState(){
  return this->state;
}


/**
* Funtion: Print the current data of PCB
* @returns {void}
* 
* @precondition: none
* @postcondition: none
*/
void PCB::show(){
  string _log = "PID: " + to_string(this->PID) + " - State: ";
  if(this->state == terminated){
    _log + "Terminated";
  }else if(this->state == ready){
    _log + "Ready";
  }else{
    _log + "Running";
  }

  log(_log);
}



/**
* Funtion: PCB desctructor
* @returns {void}
* 
* @precondition: none
* @postcondition: none
*/
PCB::~PCB(){
  string _log = "Killing Process -> PID: " + to_string(this->PID);
  log(_log);
}