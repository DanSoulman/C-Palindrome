#include <stdio.h>
#include "pal.h"
#include "useful.h"
//BY DAN COLEMAN R00151926

/**
*display state: Shows your current location in the game, along with each number allowing you to see a 
*visualisation of the palindrome
*/
void displayState(int* pListOfNumbers, int  positionOfCursor, int number_of_digits, int numberOfGoes)
{
	printf("\nGame State:\n<"); //Front of display
	int i;//i loops to print each number
	for (i = 0; i<number_of_digits; i++) {
		printf("%d", pListOfNumbers[i]);
	}
	printf(">");//End of Display 
	printf(" Cursor at %d \n", positionOfCursor); //Cursor position number displayed 
	for (i = 0; i<positionOfCursor; i++)//Loops as many spaces as needed to put ^ below the number (< accounted for)
		printf(" ");
	printf("^");//Points to number you are affecting
	printf("\nNumber of goes: %d \n", numberOfGoes); //Displays number of goes currently taken 
}
/**
*move cursor right: moves the ^ over one place right
*/
void moveCursorRight(int* positionOfCursor, int number_of_digits)
{
	if (*(positionOfCursor) < number_of_digits) {
		*positionOfCursor += 1; //Moves cursor one space right if it's not the last number
		}
	else
		printf("\nINVALID: Cursor all the way to the right!\n"); //If it exceeds this you are stopped
}
/**
*move cursor left: moves the ^ over one place left
*/
void moveCursorLeft(int* positionOfCursor, int number_of_digits)
{

	if (*(positionOfCursor) > 1) {
		*positionOfCursor -= 1;//Moves cursor one space left if it's not the first number
	}
	else
		printf("\nINVALID: Cursor all the way to the left!\n"); //If it exceeds this you are stopped
}
/**
*increment digit in list at position: increases the number you are currently pointing to by 1
*/
void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor) {//Minus one to PosOfCursor as you don't want to account for opening <
	if (*(pListOfNumbers+ (positionOfCursor-1)) < 9) { //If the number at that spot is less than 9 
		*(pListOfNumbers+ (positionOfCursor-1)) = *(pListOfNumbers + (positionOfCursor-1)) + 1; //Adds one to it 
	}
	else {
		printf("\n\nINVALID: Number cannot exceed 9\n\n"); //Stops the number hitting double digits
	}
}
/**
*decrement digit in list at position: decreases the number you are currently pointing to by 1
*/
void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor) {
	if (*(pListOfNumbers + positionOfCursor-1) > 0) {//If the number at that spot is greater than 0
		*(pListOfNumbers + positionOfCursor-1) = *(pListOfNumbers + positionOfCursor-1) - 1;//Takes one from it 
	}
	else
		printf("\n\n INVALID: Number cannot go below 0\n\n");//Stops the number hitting minus digits
}
/**
*is palindrome :checks if list of numbers is the same backwards as forwards
*/
boolean isPalindrome(int* plist_of_numbers, int number_of_digits) {
	int* pFirst = plist_of_numbers; //Points to first number
	boolean b = True; //Sets 'boolean' enum to true by default
	int i = 0;//For forward loop
	int j = number_of_digits - 1; //For backward loop
	for (i; i<number_of_digits / 2, j >= number_of_digits / 2; i++, j--) { //Loops for half of the array each
		if (*(pFirst + i) != *(pFirst + j)) {//If at any point they don't match
			b = False;//it's not a Palindrome
		}
	}
	if (b == True) { //If it stays true prints a win message
		printf("\nWinner!");
	}

	return b;//returns if its true/false
}
/**
*get command: prompts for char, if it's a valid option returns it
*/
char get_command()
{
	char command = ' '; //Have to initialize 
	char  validCharacters[] = { 'a','d', 'w', 's' }; //the four valid choices

	while (command != validCharacters[0] && command != validCharacters[1] && command != validCharacters[2] && command != validCharacters[3]) {
	//Loops while not a valid choice
		printf("\nmove cursor left -a \nmove cursor right -d  \nincrement number -w \ndecrement number -s ");
		//Prints the options
		printf("\nPlease input a valid character: ");
		//prompt for input
		command = my_get_char(); //Gets command from my get char method given to us in useful.c
	}
		//printf("%c", command); //used to test
		return command;//returns the command
}

/**
*process command: does whatever the selected char is told to do
*/
void processCommand(int * pListOfNumbers, int * positionOfCursor, int number_of_digits, char command, int numberOfGoes)
{
	//We can use if statements because we validated in the get command method
	if (command == 'a') {
		moveCursorLeft(positionOfCursor, number_of_digits); //calls move left method
	}
	else if (command == 'd') {
		moveCursorRight(positionOfCursor, number_of_digits);//calls move right method
	}
	else if (command == 'w') {
		incrementDigitInListAtPos(pListOfNumbers, *positionOfCursor);//calls increment method
	
	}
	else if (command == 's') {
		decrementDigitInListAtPos(pListOfNumbers, *positionOfCursor);//calls decrement method
	}
}