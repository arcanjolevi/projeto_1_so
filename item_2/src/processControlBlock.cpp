#include "../include/processControlBlock.hpp"

/**
* Function: Process control block contructor
* @param {int} - Process ID
* @param {string} - Process name
* @returns {PCB} - PCB instance
* 
* @precondition: none
* @postcondition: Process created, state = ready
*/
PCB::PCB(int _PID, string _name){
  this->PID = _PID;
  this->createdTime = 0;
  this->name = _name;
  this->state = ready;
  this->next = NULL;
  log("PCB created");
}

/**
* Function: Process control block contructor
* @param {int} - Process ID
* @param {string} - Process name
* @param {double} - estimatedTime
* @returns {PCB} - PCB instance
* 
* @precondition: none
* @postcondition: Process created, state = ready
*/
PCB::PCB(int _PID, string _name, double _estimatedTime){
  this->PID = _PID;
  this->createdTime = 0;
  this->name = _name;
  this->state = ready;
  this->next = NULL;
  this->estimatedTime = _estimatedTime;
  this->remainingTime = estimatedTime;
}


/**
* Function: Process control block contructor
* @returns {PCB} - PCB instance
* 
* @precondition: none
* @postcondition: Process created, state = ready, PID = -1
*/
PCB::PCB(){
  this->PID = -1;
  this->state = ready;
  this->next = NULL;
}

/**
* Function: Set all data of PCB base in other PCB
* @param {PCB} - Process control block
* @returns {void}
* 
* @precondition: none
* @postcondition: Al data changed
*/
void PCB::setPCB(PCB _other){
  this->PID = _other.getPID();
  this->createdTime = 0;
  this->state = _other.getState();
  this->next = _other.getNext();
  this->estimatedTime = _other.getEstimatedTime();
  this->remainingTime = _other.getRemainingTime();
  this->name = _other.getName();
}

/**
* Function: Change the process state
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
* Function: get the current state od the process
* @returns {State} - Current state of the process
* 
* @precondition: none
* @postcondition: none
*/
State PCB::getState(){
  return this->state;
}


/**
* Function: Print the current data of PCB
* @returns {void}
* 
* @precondition: none
* @postcondition: none
*/
void PCB::show(){
  string _log = "Process: " + this->name + " - PID: " + to_string(this->PID) + " - State: ";
  if(this->state == terminated){
    _log += "Terminated";
  }else if(this->state == ready){
    _log += "Ready";
  }else{
    _log += "Running";
  }
  _log += " - EstimatedTime: " + to_string(this->estimatedTime);

  int aux = (unsigned long int) this->next;

  _log += " - Next adress: " + to_string(aux);

  log(_log);
}



/**
* Function: PCB desctructor
* @returns {void}
* 
* @precondition: none
* @postcondition: none
*/
PCB::~PCB(){

}



/**
* Function: Change the next PCB
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
* Function: Change the next PCB
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
* Function: Get the PID
* @returns {int}
* 
* @precondition: none
* @postcondition: none
*/
int PCB::getPID(){
  return this->PID;
}


/**
* Function: Get the estimated time
* @returns {double}
* 
* @precondition: none
* @postcondition: none
*/
double PCB::getEstimatedTime(){
  return this->estimatedTime;
}


/**
* Function: Get the remainingTime
* @returns {double}
* 
* @precondition: none
* @postcondition: none
*/
double PCB::getRemainingTime(){
  return this->remainingTime;
}


/**
* Function: Set the remainingTime
* @param {double}
* @returns {void}
* 
* @precondition: none
* @postcondition: none
*/
void PCB::setRemainingTime(double _remainingTime){
  this->remainingTime = _remainingTime;
}



/**
* Function: Simulate the process execution
* @param {double} - Quantum available for execution
* @returns {double} - Return the remaining time of the quantum
* 
* @precondition: state = running
* @postcondition: process executed over quantum
*/
double PCB::execute(double _quantum){

  if(this->state != running)
    return _quantum;

  if(this->remainingTime >= _quantum){
    this->remainingTime -= _quantum;
    return 0;     
  }

  _quantum -= this->remainingTime;
  this->remainingTime = 0;

  return _quantum;
}



/**
* Function: get the current state of the process
* @returns {string} - Current state of the process
* 
* @precondition: none
* @postcondition: none
*/
string PCB::getStateString(){
  if(this->state == ready){
    return "Ready";
  }else if(this->state == running){
    return "Running";
  }else{
    return "Terminated";
  }
}



/**
* Function: Get process name
* @returns {string}
* 
* @precondition: none
* @postcondition: none
*/
string PCB::getName(){
  return this->name;
}