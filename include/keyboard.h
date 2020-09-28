#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
using namespace std;
#include <unistd.h>
#include <termios.h>

/**
 * Funtion: Read and return a character without the need for enter.
 * @param {void}
 * @returns A read char
 */
char getchChar();


#endif