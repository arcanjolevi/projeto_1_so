#include "../include/read_file.hpp"
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

void readNumberProcesses(ifstream &fn, int &tam) {
	fn >> tam;
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
	double aux;
	fn >> aux;
	return aux;
}

string readState (ifstream &fn) {

}

bool readFile (string file_name/*, PCB*/) {
	
	ifstream inputFile;

    inputFile.open(file_name);

	if( !inputFile.is_open() ) {
		//errorMessagesRead(7);
		return false;
	}
	int tam = 0;
	readNumberProcesses(inputFile, tam);
	cout << "O arquivo tem " << tam << "processos\n";
	return true;

	for (int i = 0; i < tam ; i++) {
		/*PCB.PID = */readPid(inputFile);
		/*PCB.state = */readState(inputFile);
		/*PCB.createdTime = */readTime(inputFile);
		/*PCB.estimatedTime = */readTime(inputFile);
	}
	inputFile.close();
	return true;
}
