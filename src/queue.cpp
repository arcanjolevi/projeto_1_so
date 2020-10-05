#include "../include/queue.hpp"

#include "../include/logs.hpp"


/**
* Funtion: Queue contructor
* @param {PCB} - Process control block
* @returns {Queue} - Queue instance
* 
* @precondition: none
* @postcondition: Queue created
*/
Queue::Queue(PCB _newPCB){
  this->head = new PCB();
  this->head->setPCB(_newPCB);
  this->tail = this->head;
}

/**
* Funtion: Queue destructor
* @returns {void}
* 
* @precondition: none
* @postcondition: Queue destroyed
*/
Queue::~Queue(){
  PCB * next;
  while(this->head){
    next = this->head->getNext();
    delete(this->head);
    this->head = next;
  }
  log("Queue Destroyed");
}


/**
* Funtion: Push a PCB in to the queue
* @param {PCB} - Process control block
* @returns {bool} if opration performed then true else false
* 
* @precondition: The process ID must be unique
* @postcondition: PCB queued
*/
void Queue::push(PCB _newPCB){
  this->tail->setNext(new PCB());
  this->tail = this->tail->getNext();
  this->tail->setPCB(_newPCB);
  this->size++;
}
/**
* Funtion: Pop a PCB from queue
* @returns {PCB} a PCH if queue is not empty
* 
* @precondition: Queue not empty
* @postcondition: PCB removed from queue
*/
PCB Queue::pop(){
  if(!this->isEmpty()){
    PCB * aux = this->head;
    this->head = this->head->getNext();
    return *aux;
  }else{
    log("Queue pop not performed, queue empty");
    return PCB();
  }
}

/**
* Funtion: Check if the queue is empty
* @returns {Bool} if empty then true else false
* 
* @precondition: none
* @postcondition: none
*/
bool Queue::isEmpty(){
  return this->size == 0;
}



/**
* Funtion: Change the head
* @param {PCB*} - adress of the next PCB || NULL
* @returns {void}
* 
* @precondition: none
* @postcondition: this->head changed
*/
void Queue::setHead(PCB * _head){
  this->head = _head;
}


/**
* Funtion: Get the head
* @returns {PCB*}
* 
* @precondition: none
* @postcondition: none
*/
PCB * Queue::getHead(){
  return this->head;
}



/**
* Funtion: Change the tails
* @param {PCB*} - adress of the PCB || NULL
* @returns {void}
* 
* @precondition: none
* @postcondition: this->tail changed
*/
void Queue::setTail(PCB * _tail){
  this->tail = _tail;
}

/**
* Funtion: Get the tail
* @returns {PCB*}
* 
* @precondition: none
* @postcondition: none
*/
PCB * Queue::getTail(){
  return this->tail;
}