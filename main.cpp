#include <iostream>
using namespace std;

#include "include/keyboard.hpp"
#include "include/example.hpp"
#include "include/read_file.hpp"

int main () {

  //cout << "Main program" << endl;
  //cout << "Pressione qualquer tecla para encerrar... "; 
  //getchChar();
  bool teste = readFile("files/f1.txt");
  cout << teste << endl;
  

  return 0;
}
