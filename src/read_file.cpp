#include "../include/read_file.hpp"

bool findBeginPcb (ifstream &fn) {
	string aux;

	while(!fn.eof()) {
		getline(fn, aux);
		if (aux == "{") {
			return true;
		}
	}
	return false;

}

void readId (ifstream &fn, string &id) {

}

void readTime (ifstream &fn, int &t) {

}

bool readFile (string file_name/*, coloca o objeto PCB aqui*/) {
	
	ifstream inputFile;

	if( !inputFile.is_open() ) {
		//errorMessagesRead(7);
		return false;
	}

	int i;
	for (i = 0; /* acha o comeco do PCB*/ ; i++) {
		// toda a leitura
	}
	//PCB.tam = i;
	return true;
}
