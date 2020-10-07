#include <iostream>
using namespace std;

#include "../include/keyboard.hpp"
#include "../include/states.hpp"
#include "../include/example.hpp"
#include "../include/logs.hpp"
#include "../include/processControlBlock.hpp"
#include "../include/queue.hpp"
#include "../include/shortestJobFirst.hpp"

#include <fstream>
#include <string>

int main () {

  cout << "Test program" << endl << endl << endl;




  PCB a(0, 0, 8);
  PCB b(1, 0, 4);
  PCB c(2, 0, 4);
  PCB d(3, 0, 4);

  Queue * ready = new Queue(a);

  ready->pushInOrder(b);
  ready->pushInOrder(c);
  ready->pushInOrder(d);

  SJF * algorithm = new SJF(ready);

  algorithm->run();


  cout << "Pressione qualquer tecla para encerrar... "; 
  getchChar();
  

  return 0;
}
