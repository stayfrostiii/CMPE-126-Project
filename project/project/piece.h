
#ifndef Piece_Class
#define Piece_Class

#include <iostream>

using namespace std;

class Piece
{
	protected:
		bool isWhite;
		string pieceType;
	public:
		/*
			The move function will be defined in each of the child classes, and each definition will differ 
			according to the corresponding piece. The string variables passed through will be the current position
		*/
		bool move();
};

#endif