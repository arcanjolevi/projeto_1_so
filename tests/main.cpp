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

  Queue * readyProcesses = new Queue();
  double quantum;
  
  bool teste = readFile("files/f1.txt", readyProcesses, &quantum, 0);

  cout << "Pressione qualquer tecla para encerrar... "; 
  getchChar();
  

  return 0;
}
