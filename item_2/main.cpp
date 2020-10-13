#include <iostream>
using namespace std;

#include "include/keyboard.hpp"
#include "include/states.hpp"
#include "include/logs.hpp"
#include "include/processControlBlock.hpp"
#include "include/queue.hpp"
#include "include/shortestJobFirst.hpp"
#include "include/roundRobin.hpp"
#include "include/keyboard.hpp"
#include "include/read_file.hpp"

string getFileName(){
  system("clear");
  string arquivo;
  cout << "Certifique-se de que o arquivo de entrada está na pasta input e no mesmo diretório do programa.\n"; 
  cout << "Arquivos disponiveis na pasta input:\n";
  system("ls input");
  cout <<" ⇨ Insira o nome do arquivo com a sua extensão: "; 
  cin >> arquivo;
  system("clear");
  return arquivo;
}

int main () {

  clearLogsFile();

  string arquivo;
  Queue * readyProcesses = new Queue();
  bool readFileOk = false;
  double quantum;

  cout << "Main Program" << endl << endl << endl;
  cout << "Pressione qualquer tecla para Iniciar..."; 
  getchChar();
  system("Clear");


  while(!readFileOk){
    arquivo = getFileName();
    readFileOk = readFile("input/" + arquivo , readyProcesses, &quantum, true);
  }

  cout << "Os dados dos processos serão processados de acordo com os algoritmos Round Robin e Shortest Job First." << endl;
  cout << "Os arquivos correspondentes aos algoritmos estarão nos seguites destinos:" << endl;
  cout << "output/roundRobin.txt e output/shortestjobFirst.txt" << endl << endl;

  cout << "Pressione qualquer tecla para Continuar..."; 
  getchChar();
  system("clear");

  

  //Round robin algorithm  
  
  RR * algorithm1 = new RR(readyProcesses, quantum);
  algorithm1->run();
  delete(algorithm1);


  //SJF algorithm
  readyProcesses = new Queue();
  readFile("input/" + arquivo , readyProcesses, &quantum, false);
  SJF * algorithm2 = new SJF(readyProcesses);
  algorithm2->run();
  delete(algorithm2);


  cout << "Processamento realizado." << endl;
  cout << "Pressione qualquer tecla para encerrar..."; 
  getchChar();

  return 0;
}
