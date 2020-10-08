#include <iostream>
using namespace std;

#include "include/keyboard.hpp"
#include "include/states.hpp"
#include "include/example.hpp"
#include "include/logs.hpp"
#include "include/processControlBlock.hpp"
#include "include/queue.hpp"
#include "include/shortestJobFirst.hpp"
#include "include/roundRobin.hpp"
#include "include/keyboard.hpp"
#include "include/read_file.hpp"

int main () {

  Queue * readyProcesses = new Queue();
  double quantum;
  
  bool teste = readFile("files/f1.txt", readyProcesses, &quantum);
  cout << teste << endl;

  RR * algorithm = new RR(readyProcesses, quantum);


  algorithm->run();

  
  delete(algorithm);
  algorithm = NULL;


  cout << "Main program" << endl;
  cout << "Pressione qualquer tecla para encerrar... "; 
  getchChar();
  return 0;
}
