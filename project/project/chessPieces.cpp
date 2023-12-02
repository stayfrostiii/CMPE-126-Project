
#include <iostream>
#include <string>

#include "chessPieces.h"

using namespace std;

Piece::Piece()
{
	this->isWhite = -1;
	this->pieceType = "--";
}

string Piece::getType()
{
	return pieceType;
}

/*
	operator<<(...) allows for direct printing of a piece. W or B is attached depending on value of isWHite. 
	If a null piece, no W or B is attached.
*/

ostream& operator<<(ostream& os, Piece& piece)
{
	if (piece.isWhite == 1)
		os << "W" << piece.pieceType;
	else if (piece.isWhite == 0)
		os << "B" << piece.pieceType;
	else
		os << piece.pieceType;
	return os;
}

/*
	convert(...) will convert each position on the board into an int that can be used to determine whether
	a move is legal or not. The first integer of the int (in the 10 place) represents the x coordinate while
	the second integer of the int (in the 1 place) represents the y coordinate.
*/

int convert(string pos)
{
	return (pos.at(0) - 64) * 10 + pos.at(1) - '0' - 11;
}

// Pawn class

Pawn::Pawn(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "P";
}

/*
	A pawn can only move forward one space
	Exceptions:
	- First turn it can move 2 forward
	- When killing, it can only move diagonally
*/

bool Pawn::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	int c = convert(curPos);
	int n = convert(newPos);

	if (isWhite == 1)
	{
		// If pawn is going to kill
		if (isKilling)
		{
			// Using chart, checks to see if next pos is diagonal one space forward
			return n - c == 9 || n - c == -11;
		}
		else if (c / 10 == 6 && c / 10 - n / 10 == 2)
		{
			return board[c / 10 - 1][c % 10]->getType() == "--" && board[c / 10 - 2][c % 10]->getType() == "--";
		}
		else if (c / 10 != 0)
		{
			return board[c / 10 - 1][c % 10]->getType() == "--";
		}
	}
	else
	{
		// If pawn is going to kill
		if (isKilling)
		{
			// Using chart, checks to see if next pos is diagonal one space forward
			return n - c == -9 || n - c == 11;
		}
		else if (c % 10 == 1 && n % 10 - c % 10 == 1)
		{
			return board[c / 10 + 1][1]->getType() == "--";
		}
		else if (c % 10 == 7 && n % 10 - c % 10 == 2)
		{
			return board[c / 10 + 1][1]->getType() == "--" && board[c / 10 + 1][2]->getType() == "--";
		}
		else if (c / 10 != 0)
		{
			return board[c / 10 + 1][c % 10]->getType() == "--";
		}
	}

	return false;
}

// Rook class

Rook::Rook(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "R";
}

/*
	A rook can only move in horizontal or vertical directions
*/

bool Rook::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	return false;
}

// Knight class

Knight::Knight(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "H";
}

/*
	A knight has a strange movement mechanic
	1) Must move two spaces horizontal or vertical
	2) move perpendicular one space from direction you chose
*/

bool Knight::move(string curPos, string newPos)
{
	return false;
}

// Bishop class

Bishop::Bishop(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "B";
}

/*
	A bishop can move in diagonal directions
*/

bool Bishop::move(string curPos, string newPos)
{
	return false;
}

// Queen class

Queen::Queen(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "Q";
}

/*
	A queen can move in diagonal, horizontal, and vertical
*/

bool Queen::move(string curPos, string newPos)
{
	return false;
}

// King class

King::King(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "K";
}

/*
	A king can move in any direction one space
*/

bool King::move(string curPos, string newPos)
{
	return false;
}
