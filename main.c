#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pal.h"
#include "useful.h"
//BY DAN COLEMAN R00151926
/**
*Start game: Is the set up for the game
*/
void start_game()
{
	//int listOfNumbers[] = { 1,2,5,0,5,2,2 };
	int number_of_digits = 15; //Changes the size of array 
	int positionOfCursor = 1;//Where the cursor is at a given time
	int numberOfGoes = 0; //Number of moves taken
	srand(time(NULL)); //seeds the random number generator used by the function rand.
	positionOfCursor = rand() % number_of_digits;
	int* pNumbers = (int*)malloc(sizeof(int)*number_of_digits); //allocate memory for 6 numbers like an array
	int i;//declares i for loop
	srand(time(NULL));//seeds the random number generator used by the function rand.
	for (i = 0; i < number_of_digits; i++) //Loops for size of game 
		*(pNumbers + i) = rand() % 10;//Randomizes numbers


	displayState(pNumbers, positionOfCursor, number_of_digits, numberOfGoes); //Shows initial game state
	boolean b = isPalindrome(pNumbers, number_of_digits); //Sets b to not a palindrome, or skips to win if already solved.
	while (b == 0) { //Loop for the main game. Ends upon completion of Palindrome 
		char command = get_command(); //Gets the char (from useful.c provided)
		processCommand(pNumbers, &positionOfCursor, number_of_digits, command, numberOfGoes); //Deals with button inputs
		numberOfGoes += 1;//Counts up a Go
		displayState(pNumbers, positionOfCursor, number_of_digits, numberOfGoes);//Shows current game state
		b = isPalindrome(pNumbers, number_of_digits);//Checks if you win
	}
	printf("\nWon in %d goes!\n", numberOfGoes);//Number of goes taken to win
	free(pNumbers); //Frees space taken by malloc
}
int main()
{
	start_game();//Starts game
}
