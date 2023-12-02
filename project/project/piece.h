
#ifndef Piece_Class
#define Piece_Class

#include <iostream>

using namespace std;

class Piece
{
	protected:
		int isWhite;
		string pieceType;
	public:
		Piece();
		string getType();
		friend ostream& operator<<(ostream&, Piece&);
};

#endif