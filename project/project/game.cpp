
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <string>

#include "game.h"

using namespace std;

int convertPos(string pos)
{
	return (pos.at(1) - '0') * 10 + (pos.at(0) - 64) - 11;
}

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
				board[i][x] = new Null();
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

bool::Game::makeMove(string curPos, string newPos)
{
	int c = convertPos(curPos);
	int n = convertPos(newPos);

	if (players.front().getTeam() && board[c / 10][c % 10]->getType().at(0) == 'B')
		return false;
	else if (!players.front().getTeam() && board[c / 10][c % 10]->getType().at(0) == 'W')
		return false;

	cout << board[c / 10][c % 10]->getType() << " moving from " << curPos << " -> " << newPos << endl;

	bool canMakeMove = board[c / 10][c % 10]->move(curPos, newPos, board);
	bool gameOver;

	if (canMakeMove)
	{
		gameOver = board[n / 10][n % 10]->getType().at(1) == 'K';
		
		Piece* temp = board[c / 10][c % 10];

		board[c / 10][c % 10] = new Null();
		board[n / 10][n % 10] = temp;

		if (gameOver)
		{
			endGW(players.front(), players.back());
			exit(0);
		}

	}
	return canMakeMove;
}

void Game::redo()
{
	for (int i = 0; i < 8; i++)
	{
		for (int x = 0; x < 8; x++)
		{
			board[i][x] = prevTurns.top()[i][x];
		}
	}
	prevTurns.pop();
}

/*
	takeTurn() is the main function of the game class.
	1) Asks user what to do
		- Redo turn
		- Make Move
*/

void Game::takeTurn()
{
	string curPos;
	string newPos;
	bool done = false;
	//prevTurns.push(board);

	do
	{
		cout << "Current Position: ";
		cin >> curPos;
		cout << "New Position: ";
		cin >> newPos;

		done = makeMove(curPos, newPos);
		if (!done)
		{
			cout << "invalid move" << endl;
		}

	} while (!done);

	cout << endl;
	print();
}

void Game::run()
{
	bool isWhite = true;
	while (true)
	{
		cout << endl;
		cout << players.front().getName() << "'s turn";
		if (isWhite)
			cout << " (W)..." << endl;
		else
			cout << " (B)..." << endl;
		takeTurn();
		players.push(players.front());
		players.pop();
		isWhite = !isWhite;
	}
}

void Game::addRecord(Player& p)
{
	vector<string> lines;
	string line;
	string temp;

	ifstream ifile("names.txt");
	if (ifile.is_open())
	{
		while (getline(ifile, line))
		{
			temp = "";
			for (int i = 0; i < line.size(); i++)
			{
				if (line.at(i) == ' ')
					i = line.size();
				else
					temp += line.at(i);
			}
			if (temp != p.getName())
			{
				lines.push_back(line);
			}
		}
		ifile.close();
	}
	lines.push_back(p.getInfo());

	ofstream ofile;
	ofile.open("names.txt");

	for (int i = 0; i < lines.size(); i++)
	{
		ofile << lines.at(i) << endl;
	}

	ofile.close();
}

void Game::endGW(Player& winner, Player& loser)
{
	++winner;
	--loser;
	print();
	cout << winner.getName() << " has won the game" << endl;

	addRecord(winner);
	addRecord(loser);
}

/*
	print() is the current method for printing the board. Using must use the asterik because it is a 2d array of pointers
*/

void Game::print()
{
	cout << "  A  B  C  D  E  F  G  H" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "|" << *board[i][0] << " " << *board[i][1] << " " << *board[i][2] << " " << *board[i][3] << " " <<
			*board[i][4] << " " << *board[i][5] << " " << *board[i][6] << " " << *board[i][7] << "|  " << i + 1 << endl;
	}
}


// PAWN TEST CASE

/*

bool Game::makeMove()
{
	cout << *board[1][2] << endl;
	bool canMakeMove = board[1][2]->move("C2", "C4", false, board);
	if (canMakeMove)
	{
		int newPos = convertPos("C4");
		int oldPos = convertPos("C2");

		Piece* temp = board[oldPos / 10][oldPos % 10];

		board[oldPos / 10][oldPos % 10] = new Null();
		board[newPos / 10][newPos % 10] = temp;

	}
	return canMakeMove;
}

*/

// KNIGHT TEST CASE

/*

bool Game::makeMove()
{
	cout << *board[0][1] << endl;
	bool canMakeMove = board[0][1]->move("B1", "C3", false, board);
	if (canMakeMove)
	{
		int newPos = convertPos("C3");
		int oldPos = convertPos("B1");

		Piece* temp = board[oldPos / 10][oldPos % 10];

		board[oldPos / 10][oldPos % 10] = new Null();
		board[newPos / 10][newPos % 10] = temp;

	}
	return canMakeMove;
}


/*

bool Game::makeMove()
{
	cout << *board[0][0] << endl;
	bool canMakeMove = board[0][0]->move("A1", "A7", false, board);
	if (canMakeMove)
	{
		int newPos = convertPos("A7");
		int oldPos = convertPos("A1");

		Piece* temp = board[oldPos / 10][oldPos % 10];

		board[oldPos / 10][oldPos % 10] = new Null();
		board[newPos / 10][newPos % 10] = temp;

	}
	return canMakeMove;
}

*/

// QUEEN TEST CASE

/*

bool Game::makeMove()
{
	cout << *board[7][3] << endl;
	bool canMakeMove = board[7][3]->move("D8", "A8", false, board);
	if (canMakeMove)
	{
		int newPos = convertPos("A8");
		int oldPos = convertPos("D8");

		Piece* temp = board[oldPos / 10][oldPos % 10];

		board[oldPos / 10][oldPos % 10] = new Null();
		board[newPos / 10][newPos % 10] = temp;

	}
	return canMakeMove;
}

*/

// BISHOP TEST CASE

/*

bool Game::makeMove()
{
	cout << *board[0][2] << endl;
	bool canMakeMove = board[0][2]->move("C1", "E3", false, board);
	if (canMakeMove)
	{
		int newPos = convertPos("E3");
		int oldPos = convertPos("C1");

		Piece* temp = board[oldPos / 10][oldPos % 10];

		board[oldPos / 10][oldPos % 10] = new Null();
		board[newPos / 10][newPos % 10] = temp;

	}
	return canMakeMove;
}

*/
