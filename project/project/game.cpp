
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <array>

#include "game.h"

using namespace std;

/*
	convertPos(...) converts the given position into an int that can be used as an index
	in the 2d array board
*/

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

/*
	create() creates the initial board with each piece in their respective location
*/

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
	makeMove() moves pieces across the board. The function will return a boolean that determines whether
	the move is valid or not. The order of operations are:
		1) Convert string positions into int positions
		2) Determine that player isnt moving opposing pieces (if so, return false)
		3) Determine if move can be made (if not, return false)
		4) Move piece, check win condition (new position is opposing king = win)
		5) If win, increment winner, decrement loser, and exit program
*/

bool::Game::makeMove(string curPos, string newPos)
{
	int c = convertPos(curPos);
	int n = convertPos(newPos);

	if (players.front().getTeam() && board[c / 10][c % 10]->getType().at(0) == 'B')
		return false;
	else if (!players.front().getTeam() && board[c / 10][c % 10]->getType().at(0) == 'W')
		return false;

	bool canMakeMove = board[c / 10][c % 10]->move(curPos, newPos, board);
	bool gameOver;

	if (canMakeMove)
	{
		cout << board[c / 10][c % 10]->getType() << " moving from " << curPos << " -> " << newPos << endl;
		gameOver = board[n / 10][n % 10]->getType().at(1) == 'K';
		
		Piece* temp = board[c / 10][c % 10];

		board[c / 10][c % 10] = new Null();
		board[n / 10][n % 10] = temp;
		if(((board[n / 10][n % 10]->getType().at(0) == 'B') && (board[n / 10][n % 10]->getType().at(1) == 'P')) && ((n / 10) == 7))
		{
			board[n / 10][n % 10] = new Queen(false);
		}
		else if(((board[n / 10][n % 10]->getType().at(0) == 'W') && (board[n / 10][n % 10]->getType().at(1) == 'P')) && ((n / 10) == 0))
		{
			board[n / 10][n % 10] = new Queen(true);
		}

		if (gameOver)
		{
			endGW(players.front(), players.back());
			exit(0);
		}

	}
	return canMakeMove;
}

void Game::undo() {
	if (!currentPosition.empty()) {

		string curPos = currentPosition.top(); 
		string newPos = newPosition.top();
		
		int c = convertPos(curPos);
		int n = convertPos(newPos);

		board[c / 10][c % 10] = movingPiece.top();
		board[n / 10][n % 10] = stillPiece.top();

		newPosition.pop();	
		currentPosition.pop();
		movingPiece.pop(); 
		stillPiece.pop();

		print(); 
		
		cout << "Undo successful." << endl;
	}
	else {
		cout << "Cannot undo further." << endl;
	}
}

/*
	takeTurn() allows for player to take their turn. Order of operations:
		1) Ask player for current position and new position (use graphic to determine positions)
		2) If move is valid, loop is closed
		3) Prints current board after turn is done
*/

void Game::takeTurn()
{
	string curPos, newPos;
	int c, n;

	bool done = false;

	string choice;
	char es;
	
	while (!done)
	{
		cout << "Do you want to undo (0) or move (1)?" << endl;
		cin >> choice;
		if (choice == "0" || choice == "1")
			done = true;
		else
			cout << "Invalid input" << endl;
	} 

	if (choice == "1") {
		do
		{
			cout << "Current Position: ";
			cin >> curPos;
			cout << "New Position: ";
			cin >> newPos;

			c = convertPos(curPos);
			n = convertPos(newPos);

			newPosition.push(newPos);
			currentPosition.push(curPos);
			movingPiece.push(board[c / 10][c % 10]);
			stillPiece.push(board[n / 10][n % 10]);

			done = makeMove(curPos, newPos);
			if (!done)
			{
				cout << "invalid move" << endl;

				newPosition.pop();		//for undo function if move is invalid
				currentPosition.pop();
				movingPiece.pop();
				stillPiece.pop();
			}

		} while (!done);
	}
	else {
		undo();
	}
	cout << endl;
	print();
}

/*
	run() is the main function of the game class. This function will loop infinitely through until:
		1) Termination of program when game is won
		2) Player resigns (NOT IMPLEMENTED YET)
*/

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

/*
	addRecord(...) adds the information of a player to the names.txt file. Special cases are accounted
	for when a player already exists in the names.txt file
*/

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
			for (size_t i = 0; i < line.size(); i++)
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

/*
	endGW(...) increments winner and decrements loser
*/

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
