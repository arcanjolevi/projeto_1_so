#ifndef QUEUE_H
#define QUEUE_H

#include "processControlBlock.hpp"



/**
  * Class: Represents a queue of PCBs
  */
class Queue {
  private:
    PCB * head;
    PCB * tail;
    int size = 0;
  public:

  /**
  * Funtion: Queue contructor
  * @param {PCB} - Process control block
  * @returns {Queue} - Queue instance
  * 
  * @precondition: none
  * @postcondition: Queue created
  */
  Queue(PCB _newPCB);

  /**
  * Funtion: Queue destructor
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: Queue destroyed
  */
  ~Queue();

  /**
  * Funtion: Push a PCB in to the queue
  * @param {PCB} - Process control block
  * @returns {bool} if opration performed then true else false
  * 
  * @precondition: The process ID must be unique
  * @postcondition: PCB queued
  */
  void push(PCB _newPCB);

  /**
  * Funtion: Pop a PCB from queue
  * @returns {PCB} a PCH if queue is not empty
  * 
  * @precondition: Queue not empty
  * @postcondition: PCB removed from queue
  */
  PCB pop();

  /**
  * Funtion: Check if the queue is empty
  * @returns {Bool} if empty then true else false
  * 
  * @precondition: none
  * @postcondition: none
  */
  bool isEmpty();

  /**
  * Funtion: Change the head
  * @param {PCB*} - adress of the next PCB || NULL
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: this->head changed
  */
  void setHead(PCB * _head);

  /**
  * Funtion: Get the head
  * @returns {PCB*}
  * 
  * @precondition: none
  * @postcondition: none
  */
  PCB * getHead();

  /**
  * Funtion: Change the tails
  * @param {PCB*} - adress of the PCB || NULL
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: this->tail changed
  */
  void setTail(PCB * _tail);

  /**
  * Funtion: Get the tail
  * @returns {PCB*}
  * 
  * @precondition: none
  * @postcondition: none
  */
  PCB * getTail();

  /**
  * Funtion: Print in to the log file the queue content
  * @returns {void}
  * 
  * @precondition: none
  * @postcondition: none
  */
  void show();

};


#endif