#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED
#include "useful.h"
//A header file is a file with extension .h which contains C function declarations
//and macro definitions to be shared between several source files.

void displayState(int* pListOfNumbers, int  positionOfCursor, int number_of_digits, int numberOfGoes); 
void moveCursorRight(int* positionOfCursor, int number_of_digits);
void moveCursorLeft(int* positionOfCursor, int number_of_digits);
void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor);
void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor);
boolean isPalindrome(int* pListOfNumbers, int number_of_digits);
char get_command();
void processCommand(int* pListOfNumbers, int* positionOfCursor, int number_of_digits, char command,int numberOfGoes);
#endif // PAL_H_INCLUDED
