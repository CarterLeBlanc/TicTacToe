#include "pch.h"
#include <iostream>

using namespace std;

//Sets the grid for all available moves
char grid[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkWin() 
{
	//If all of the spaces match in the top row, return 1
	if (grid[1] == grid[2] && grid[2] == grid[3]) 
	{
		return 1;
	}

	//If all of the spaces match in the middle row, return 1
	else if (grid[4] == grid[5] && grid[5] == grid[6]) 
	{
		return 1;
	}

	//If all of the spaces match in the bottom row, return 1
	else if (grid[7] == grid[8] && grid[8] == grid[9]) 
	{
		return 1;
	}

	//If all of the spaces match in the first column, return 1
	else if (grid[1] == grid[4] && grid[4] == grid[7])
	{
		return 1;
	}

	//If all of the spaces match in the second column, return 1
	else if (grid[2] == grid[5] && grid[5] == grid[8])
	{
		return 1;
	}
	
	//If all of the spaces match in the third column, return 1
	else if (grid[3] == grid[6] && grid[6] == grid[9])
	{
		return 1;
	}

	//If all of the spaces match diagnally, return 1
	else if (grid[1] == grid[5] && grid[5] == grid[9])
	{
		return 1;
	}

	//If all of the spaces match diagnolly, return 1
	else if (grid[3] == grid[5] && grid[5] == grid[7])
	{
		return 1;
	}

	//If all spaces are filled but there aren't three of the same marks in a row, return 0
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
		grid[4] != '4' && grid[5] != '5' && grid[6] != '6' &&
		grid[7] != '7' && grid[8] != '8' && grid[9] != '9') 
	{
		return 0;
	}

	//Else, return -1
	else 
	{
		return -1;
	}
}

//Prints a visual representation of the game board
void gameBoard() 
{
	system("cls");
	cout << "Tic Tac Toe\n";

	cout << "Player 1 (X) - Player 2 (O)\n";
	cout << endl;

	cout << "   |   |   \n";
	cout << " " << grid[1] << " | " << grid[2] << " | " << grid[3] << endl;

	cout << "___|___|___\n";
	cout << "   |   |   \n";

	cout << " " << grid[4] << " | " << grid[5] << " | " << grid[6] << endl;

	cout << "___|___|___\n";
	cout << "   |   |   \n";

	cout << " " << grid[7] << " | " << grid[8] << " | " << grid[9] << endl;

	cout << "   |   |   \n";
}

void main()
{
	//Initializes the player
	int player = 1, choice;
	//Holds the character that marks the player's choice
	char mark;

	//Calls gameBoard()
	gameBoard();

	//Loop as long as checkWin() returns -1
	while (checkWin() == -1) 
	{
		//Check if any player has won
		checkWin();
		//Swap betwenn player 1 and 2
		player = (player % 2) ? 1 : 2;

		//Print a message that says which player's turn it is
		cout << "Player " << player << ", eneter a number: ";
		//Gets input from the player
		cin >> choice;

		//Changes the mark depending on the player
		mark = (player == 1) ? 'X' : 'O';

		//Mark the spot that the player chooses as long as it has not already been marked
		if (choice == 1 && grid[1] == '1') 
		{
			grid[1] = mark;
		}

		else if (choice == 2 && grid[2] == '2')
		{
			grid[2] = mark;
		}

		else if (choice == 3 && grid[3] == '3')
		{
			grid[3] = mark;
		}

		else if (choice == 4 && grid[4] == '4')
		{
			grid[4] = mark;
		}

		else if (choice == 5 && grid[5] == '5')
		{
			grid[5] = mark;
		}

		else if (choice == 6 && grid[6] == '6')
		{
			grid[6] = mark;
		}

		else if (choice == 7 && grid[7] == '7')
		{
			grid[7] = mark;
		}

		else if (choice == 8 && grid[8] == '8')
		{
			grid[8] = mark;
		}

		else if (choice == 9 && grid[9] == '9')
		{
			grid[9] = mark;
		}

		//Otherwise, print an error message and give the player another chance
		else 
		{
			cout << "You cannot move there.";

			player--;
			cin.ignore();
			cin.get();
		}

		//Redraw the game board and switch to the next player
		gameBoard();
		player++;

		//If checkWin() returns 1, announce the winner
		if (checkWin() == 1)
		{
			cout << "Player " << --player << " wins";
		}

		//If checkWin() returns 0, tell the players that the game is a draw
		else if (checkWin() == 0)
		{
			cout << "The game is a draw.";
		}

		cin.get();
	}
}