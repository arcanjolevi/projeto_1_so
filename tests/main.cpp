#include <iostream>
using namespace std;

#include "../include/keyboard.hpp"
#include "../include/states.hpp"
#include "../include/example.hpp"
#include "../include/logs.hpp"
#include "../include/processControlBlock.hpp"
#include "../include/queue.hpp"
#include "../include/shortestJobFirst.hpp"
#include "../include/roundRobin.hpp"
#include "../include/keyboard.hpp"
#include "../include/read_file.hpp"

#include <fstream>
#include <string>

int main () {

  cout << "Test program" << endl << endl << endl;
  cout << "Pressione qualquer tecla para Iniciar os testes..."; 
  getchChar();
  system("clear");

  Queue * readyProcesses = new Queue();
  double quantum;
  
  readFile("files/f1.txt", readyProcesses, &quantum, true);

  RR * algorithm1 = new RR(readyProcesses, quantum);

  algorithm1->run();

  delete(algorithm1);


  readyProcesses = new Queue();

  readFile("files/f1.txt", readyProcesses, &quantum, false);

  SJF * algorithm2 = new SJF(readyProcesses);

  algorithm2->run();

  delete(algorithm2);


  cout << "Pressione qualquer tecla para encerrar... "; 
  getchChar();
  system("clear");
  

  return 0;
}
