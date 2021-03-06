#include "../include/queue.hpp"

/**
* Function: Queue contructor
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
  this->size++;
}

/**
* Function: Queue destructor
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

  if(head != NULL){
    delete(this->head);
    this->head = NULL;
  }
  if(tail != NULL){
    delete(this->tail);
    this->tail = NULL;
  }
  log("Queue Destroyed");
}


/**
* Function: Push a PCB in to the queue
* @param {PCB} - Process control block
* @returns {bool} if opration performed then true else false
* 
* @precondition: The process ID must be unique
* @postcondition: PCB queued
*/
bool Queue::push(PCB _newPCB){
  if(this->isEmpty()){
    this->head = new PCB();
    this->head->setPCB(_newPCB);
    this->tail = this->head;      
  }else{
    this->tail->setNext(new PCB());
    this->tail = this->tail->getNext();
    this->tail->setPCB(_newPCB);
  }
  this->tail->setNext(NULL);  
  this->size++;

  return true;
}



/**
* Function: Push a PCB in to the queue in order
* @param {PCB} - Process control block
* @returns {bool} if opration performed then true else false
* 
* @precondition: The process ID must be unique
* @postcondition: PCB queued
*/
bool Queue::pushInOrder(PCB _newPCB){
  PCB * aux = this->head;

  if(this->isEmpty()){
    this->push(_newPCB);
    return true;
  }
  while(aux){
    if(aux->getEstimatedTime() > _newPCB.getEstimatedTime()){
      PCB * aux2 = new PCB();
      *aux2 = *aux;      
      aux->setPCB(_newPCB);
      aux->setNext(aux2);
      if(this->tail == aux){
        this->tail = aux2;
      }
      this->size++;
      return true;
    }
    aux = aux->getNext();
  }
  
  this->push(_newPCB);
  return true;  
}

/**
* Function: Pop a PCB from queue
* @returns {PCB} a PCH if queue is not empty
* 
* @precondition: Queue not empty
* @postcondition: PCB removed from queue
*/
PCB Queue::pop(){
  if(!this->isEmpty()){
    PCB * aux = this->head;
    this->head = this->head->getNext();
    this->size--;
    if(this->size == 1){
      this->tail = this->head;
    }
    PCB aux2;
    aux2.setPCB(*aux);
    delete(aux);
    return aux2;
  }else{
    log("Queue pop not performed, queue empty");
    return PCB();
  }
}

/**
* Function: Check if the queue is empty
* @returns {Bool} if empty then true else false
* 
* @precondition: none
* @postcondition: none
*/
bool Queue::isEmpty(){
  return this->size == 0;
}



/**
* Function: Change the head
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
* Function: Get the head
* @returns {PCB*}
* 
* @precondition: none
* @postcondition: none
*/
PCB * Queue::getHead(){
  return this->head;
}



/**
* Function: Change the tails
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
* Function: Get the tail
* @returns {PCB*}
* 
* @precondition: none
* @postcondition: none
*/
PCB * Queue::getTail(){
  return this->tail;
}



/**
* Function: Print in to the log file the queue content
* @returns {void}
* 
* @precondition: none
* @postcondition: none
*/
void Queue::show(){
  string _log = "Queue: \n";
  
  if(this->isEmpty()){
    _log += " Queue empty";
  }else{ 
    _log += " Head: " + to_string((unsigned long int) this->head);
    _log += " Tail: " + to_string((unsigned long int) this->tail);
    _log += "";
    _log += " Size: " + to_string(this->size);
    _log += "\nPCBs:\n";
  }
  PCB * aux = this->head;
  while(aux){
    _log += "PID: " + to_string(aux->getPID()) + "\n";
    aux = aux->getNext();
  }

  log(_log);
}



/**
* Function: return queue content in string
* @returns {string} queue elements
* 
* @precondition: none
* @postcondition: none
*/
string Queue::queueToString(){
  string content = "[";
  PCB * aux = this->head;
  while(aux){
    content += to_string(aux->getPID());
    if(aux != this->tail){
      content += ", ";
    }
    aux = aux->getNext();
  }
  content += "]";
  return content;
}

/**
* Function: Get size
* @returns {int}
* 
* @precondition: none
* @postcondition: none
*/
int Queue::getSize(){
  return this->size;
}
