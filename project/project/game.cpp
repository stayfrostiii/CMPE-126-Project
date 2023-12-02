
#include <iostream>
#include <queue>;

#include "game.h"

using namespace std;

/*
	Game(...) adds the 2 players in the parameters to the queue and initializes the board to the default
*/

Game::Game(Player& p1, Player& p2)
{
	players.push(p1);
	players.push(p2);
	gameOver = false;
	create();
}

void Game::create()
{
	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
			// Creating Black Special Pieces at top of board
			case 0: 
				board[0][0] = new Rook(false);
				board[0][1] = new Knight(false);
				board[0][2] = new Bishop(false);
				board[0][3] = new Queen(false);
				board[0][4] = new King(false);
				board[0][5] = new Bishop(false);
				board[0][6] = new Knight(false);
				board[0][7] = new Rook(false);
				break;

			// Creating Black Pawns at 2nd to top of board
			case 1:
				for (int x = 0; x < 8; x++)
				{
					board[i][x] = new Pawn(false);
				}
				break;

			// Creating White Pawns at 2nd to bottom of board
			case 6:
				for (int x = 0; x < 8; x++)
				{
					board[i][x] = new Pawn(true);
				}
				break; 

			// Creating White Special Pieces at bottom of board
			case 7:
				board[7][0] = new Rook(true);
				board[7][1] = new Knight(true);
				board[7][2] = new Bishop(true);
				board[7][3] = new Queen(true);
				board[7][4] = new King(true);
				board[7][5] = new Bishop(true);
				board[7][6] = new Knight(true);
				board[7][7] = new Rook(true);
				break;

			// Creates empty space
			default:
				for (int x = 0; x < 8; x++)
				{
					board[i][x] = new Piece();
				}
				break;
		}
	}
}

/*
	makeMove() moves pieces across the board and will determine whether game is over or not.
	The order of operations:
	1) Ask user for move. I.e. A4 to A8
	2) Check to see if move is valid (using move function of piece on A4)
		- If A8 reports a piece back, then isKilling is true
		- Else, isKilling is false
	3) Move is made, returns if both king is alive on both sides

*/

bool Game::makeMove()
{
	return true;
}



void Game::redo()
{

}

/*
	takeTurn() is the main function of the game class.
	1) Asks user what to do
		- Redo turn
		- Make Move
	2) Calls function accordingly
		- If makeMove() returns false, increments first player in queue, decrements second player in queue, ends game
*/

void Game::takeTurn()
{

}

/*
	print() is the current method for printing the board. Using must use the asterik because it is a 2d array of pointers
*/

void Game::print()
{
	for (int i = 0; i < 8; i++)
	{
		cout << "| " << *board[i][0] << " " << *board[i][1] << " " << *board[i][2] << " " << *board[i][3] << " " <<
			*board[i][4] << " " << *board[i][5] << " " << *board[i][6] << " " << *board[i][7] << " |" << endl;
	}
}