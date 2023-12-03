
#ifndef Chess_Pieces_Class
#define Chess_Pieces_Class

/*
	This header file will be used to declare each of the chess pieces in their own classes. This allows
	each piece to have their own move function as well as being able to be added to any array of type Piece
*/

#include "piece.h"
#include <iostream>
#include <string>

using namespace std;

class Null : public Piece
{
	public:
		Null();
		bool move(string, string, bool, Piece* [8][8]);
};

class Pawn : public Piece
{
	public:
		Pawn(bool);
		bool move(string, string, bool, Piece* [8][8]);
};

class Rook : public Piece
{
	public:
		Rook(bool);
		bool move(string, string, bool, Piece*[8][8]);
};

class Knight : public Piece
{
	public:
		Knight(bool);
		bool move(string, string, bool, Piece* [8][8]);
};

class Bishop : public Piece
{
	public:
		Bishop(bool);
		bool move(string, string, bool, Piece* [8][8]);
};

class Queen : public Piece
{
	public:
		Queen(bool);
		bool move(string, string, bool, Piece* [8][8]);
};

class King : public Piece
{
	public:
		King(bool);
		bool move(string, string, bool, Piece* [8][8]);
};

#endif