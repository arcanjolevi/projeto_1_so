#include "../include/read_file.hpp"
#include <cstdio>
#include <fstream>

/*bool findBeginPcb (ifstream &fn) {
	string aux;

	while(!fn.eof()) {
		getline(fn, aux);
		if (aux == "{") {
			return true;
		}
	}
	return false;

}*/

string lineToDigit(string line) {
	string aux = "";
	for (int i = 0; i < (int)line.size(); i++) {
		if (isdigit(line[i])) {
			aux += line[i];
		}
	}
	return aux;
}

int readNumberProcesses(ifstream &fn) {
	int tam;
	char delimitator = 'v';
	fn >> tam;
	while( delimitator != '\n') fn.get(delimitator);
	return tam;
}

int readPid (ifstream &fn) {
	string line;
	while(!fn.eof()) {
		getline(fn, line);
		if (isdigit(line[0])) {
			return stoi(lineToDigit(line));
		}
	}
	return false;
}

double readTime (ifstream &fn) {
	char delimitator = 'v';
	double aux;
	fn >> aux;
	while( delimitator != '\n') fn.get(delimitator);
	return aux;
}

string readState (ifstream &fn) {
	//Coloquei codigo aqui porque tava dando warnning
	return "";
}

bool readFile (string file_name, Queue * readyProcesses, double * quantum, bool isRR) {


	/**
	 * Mano tu pode fazer o seguinte:
	 * 
	 * int _PID; double _createdTime; double _estimatedTime;
	 * 
	 * _PID = read(...);
	 * _createdTime = 0;
	 * _estimatedTime = readFile(...);
	 * 
	 * PCB aux(_PID, _createdTime, double _estimatedTime); // Aqui voce irá criar uma varaivel local auxiliar do tipo PCB
	 * 
	 * //Obs: Veja que alterei os parametros da função, adicionando ponteiros para a lista de processos prontos e para uma variavel que guardará o quantum
	 * 
	 * Caso seja o ShortestJobFirst devemos usar o método que insere os processos na lista de forma ordenada
	 * readyProcesses->pushInOrder(aux);
	 * 
	 * Caso seja o Round Robin podemos inserir os processos na ordem de leitura mesmo
	 * 
	 * readyProcesses->push(aux);
	 * 
	 * Isso é tudo, na questão dos processos
	 * 
	 * Na questão do quantum tu pode ler e jogar no conteudo do ponteiro quantum
	 * 
	 */




	ifstream inputFile;

	inputFile.open(file_name);

	if( !inputFile.is_open() ) {
		//errorMessagesRead(7);
		return false;
	}
	int _PID; double _createdTime; double _estimatedTime;

	int tam = 0;
	tam = readNumberProcesses(inputFile);
	cout << "O arquivo tem " << tam << "processos\n";
	//return true;
	if (isRR) {
		*quantum = readTime(inputFile);
	}else {
		char c= 'v';
		while( c != '\n') inputFile.get(c);
	}

	for (int i = 0; i < tam ; i++) {
		_PID = readPid(inputFile);
		cout << "Li o PID num:" << i + 1 << " = " << _PID << endl;
		_createdTime = readTime(inputFile);
		cout << "Li o tempo de criação num:" << i + 1 << " = " << _createdTime << endl;
		_estimatedTime = readTime(inputFile);
		cout << "Li o tempo estimado num:" << i + 1 << " = " << _estimatedTime << endl;

		PCB aux(_PID, _createdTime, _estimatedTime);
		if (isRR) {
			readyProcesses->push(aux);
		}else {
			readyProcesses->pushInOrder(aux);
		}



		///*PCB.state = */readState(inputFile);//Acho que podemos tirar essa informação da leitura, e deixar pro programa fazer isso, consif=derando que todos os processos que chegam para executar estao em estado pronto(ready)
		///*PCB.createdTime = */readTime(inputFile);
	}
	inputFile.close();
	return true;
}
