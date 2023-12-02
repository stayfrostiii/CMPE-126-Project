
#include <iostream>
#include <queue>;

#include "game.h"

using namespace std;

Game::Game(Player& p1, Player& p2)
{
	players.push(p1);
	players.push(p2);
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

void Game::print()
{
	for (int i = 0; i < 8; i++)
	{
		cout << "| " << *board[i][0] << " " << *board[i][1] << " " << *board[i][2] << " " << *board[i][3] << " " <<
			*board[i][4] << " " << *board[i][5] << " " << *board[i][6] << " " << *board[i][7] << " |" << endl;
	}
}