#include "../include/read_file.hpp"
#include <iostream>
using namespace std;

/**
 * function: take the digits from the beginning of a string
 * @param {string} - a line from the file
 * @returns {string} - the digits that appears in the begin of the string

* @precondition: none
* @postcondition: none
 */
string lineToDigit(string line) {
	string aux = "";
	for (int i = 0; i < (int)line.size(); i++) {
		if (isdigit(line[i])) {
			aux += line[i];
		}
	}
	return aux;
}

/**
 * function: read from file the total number of process from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {int} - the total number of process

 * @precondition: none
 * @postcondition: none
 */
int readNumberProcesses(ifstream &fn) {
	int tam;
	char delimitator = 'v';
	fn >> tam;
	while( delimitator != '\n') fn.get(delimitator);
	return tam;
}

/**
 * function: read from file the process identification from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {int} - the PID of process

 * @precondition: none
 * @postcondition: none
 */
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

/**
 * function: read a string from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {string} - Name of the process

 * @precondition: none
 * @postcondition: none
 */
string readName (ifstream &fn) {
	char delimitator = 'v';
	string aux;
	fn >> aux;
	while( delimitator != '\n') fn.get(delimitator);
	return aux;
}

/**
 * function: read a float point from the file
 * @param {fn} - a implicit pointer to the open file
 * @returns {double} - time

 * @precondition: none
 * @postcondition: none
 */
double readTime (ifstream &fn){
	char delimitator = 'v';
	double aux;
	fn >> aux;
	while( delimitator != '\n' && delimitator != fn.eof()) fn.get(delimitator);
	return aux;
}

/**
 * Function: controls file reading
 * @param {file_name} - the name or path associated with a file
 * @param {readyProcesses} - the linked list of all ready processes
 * @param {quantum} - a pointer to the duration of a quantum
 * @param {isRR} - allow the function to fill the list to both algorithms
 * @returns {bool} - true = read the file correctly

 * @precondition: none
 * @postcondition: none
 */
bool readFile (string file_name, Queue * readyProcesses, double * quantum, bool isRR) {

	ifstream inputFile;

	inputFile.open(file_name);

	if( !inputFile.is_open() ) {
		//errorMessagesRead(7);
		return false;
	}
	int _PID; double _estimatedTime; string _processName;

	int tam = 0;
	tam = readNumberProcesses(inputFile);
	//cout << "O arquivo tem " << tam << "processos\n";
	if (isRR) {
		*quantum = readTime(inputFile);
	}else {
		char c = 'v';
		while( c != '\n') inputFile.get(c);
	}

	for (int i = 0; i < tam ; i++) {
		_PID = readPid(inputFile);

		_processName = readName(inputFile);
		
		_estimatedTime = readTime(inputFile);				

		PCB aux(_PID, _processName, _estimatedTime);

		aux.show();
		
		if (isRR) {
			readyProcesses->push(aux);
		}else {
			readyProcesses->pushInOrder(aux);
		}
	}
	inputFile.close();
	return true;
}
