
#ifndef Chess_Pieces_Class
#define Chess_Pieces_Class

/*
	This header file will be used to declare each of the chess pieces in their own classes. This allows
	each piece to have their own move function as well as being able to be added to any array of type Piece
*/

#include "piece.h"
#include <iostream>

using namespace std;

class Pawn : public Piece
{
	public:
		Pawn(bool);
		bool move(string, string, bool isKilling);
};

class Rook : public Piece
{
	public:
		Rook(bool);
		bool move(string, string);
};

class Knight : public Piece
{
	public:
		Knight(bool);
		bool move(string, string);
};

class Bishop : public Piece
{
	public:
		Bishop(bool);
		bool move(string, string);
};

class Queen : public Piece
{
	public:
		Queen(bool);
		bool move(string, string);
};

class King : public Piece
{
	public:
		King(bool);
		bool move(string, string);
};

#endif