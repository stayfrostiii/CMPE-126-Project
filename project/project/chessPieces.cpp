
#include <iostream>
#include <string>

#include "chessPieces.h"

using namespace std;

/*
	convert(...) will convert each position on the board into an int that can be used to determine whether
	a move is legal or not. The first integer of the int (in the 10 place) represents the x coordinate while
	the second integer of the int (in the 1 place) represents the y coordinate.
*/

int convert(string pos)
{
	return (pos.at(0) - 64) * 10 + pos.at(1) - '0';
}

// Pawn class

Pawn::Pawn(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "Pawn";
}

/*
	A pawn can only move forward one space
	Exceptions:
	- First turn it can move 2 forward
	- When killing, it can only move diagonally
*/

bool Pawn::move(string curPos, string newPos, bool isKilling)
{
	return false;
}

// Rook class

Rook::Rook(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "Rook";
}

bool Rook::move(string curPos, string newPos)
{
	return false;
}

// Knight class

Knight::Knight(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "Knight";
}

bool Knight::move(string curPos, string newPos)
{
	return false;
}

// Bishop class

Bishop::Bishop(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "Bishop";
}

bool Bishop::move(string curPos, string newPos)
{
	return false;
}

// Queen class

Queen::Queen(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "Queen";
}

bool Queen::move(string curPos, string newPos)
{
	return false;
}

// King class

King::King(bool isWhite)
{
	this->isWhite = isWhite;
	pieceType = "King";
}

bool King::move(string curPos, string newPos)
{
	return false;
}
