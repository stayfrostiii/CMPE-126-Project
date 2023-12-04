
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
		virtual bool move(string, string, Piece*[8][8]) = 0;
		string getType();
		friend ostream& operator<<(ostream&, Piece&);
};

#endif