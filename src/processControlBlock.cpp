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
  this->next = NULL;
}


/**
* Funtion: Process control block contructor
* @returns {PCB} - PCB instance
* 
* @precondition: none
* @postcondition: Process created, state = ready, PID = -1
*/
PCB::PCB(){
  this->PID = -1;
  this->createdTime = 0;
  this->state = ready;
  this->next = NULL;
}

/**
* Funtion: Set all data of PCB base in other PCB
* @param {PCB} - Process control block
* @returns {void}
* 
* @precondition: none
* @postcondition: Al data changed
*/
void PCB::setPCB(PCB _other){
  this->PID = _other.PID;
  this->createdTime = _other.createdTime;
  this->state = _other.state;
  this->next = _other.next;
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
    _log += "Terminated";
  }else if(this->state == ready){
    _log += "Ready";
  }else{
    _log += "Running";
  }
  _log += " - Created Time: " + to_string(this->createdTime);

  int aux = (unsigned long int) this->next;

  _log += " - Next adress: " + to_string(aux);

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
 
}



/**
* Funtion: Change the next PCB
* @param {*PCB} - adress of the next PCB || NULL
* @returns {void}
* 
* @precondition: none
* @postcondition: this->next changed
*/
void PCB::setNext(PCB * _next){
  this->next = _next;
}


/**
* Funtion: Change the next PCB
* @param {*PCB} - adress of the next PCB || NULL
* @returns {void}
* 
* @precondition: none
* @postcondition: this->next changed
*/
PCB * PCB::getNext(){
  return this->next;
}


/**
* Funtion: Get the PID
* @returns {int}
* 
* @precondition: none
* @postcondition: none
*/
int PCB::getPID(){
  return this->PID;
}