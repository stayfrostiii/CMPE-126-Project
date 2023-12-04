
#include <iostream>
#include <string>

#include "chessPieces.h"

using namespace std;

Null::Null()
{
	this->isWhite = true;
	this->pieceType = "--";
}

//bool Piece::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
//{
//	return false;
//}

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
	return (pos.at(1) - '0') * 10 + (pos.at(0) - 64) - 11;
}

bool Null::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	return false;
}


// Pawn class

Pawn::Pawn(bool isWhite)
{
	this->isWhite = isWhite;
	if (isWhite)
		pieceType = "WP";
	else
		pieceType = "BP";
}

/*
	A pawn can only move forward one space
	Exceptions:
	- First turn it can move 2 forward
	- When killing, it can only move diagonally
*/

// PAWN IS FINISHED

bool Pawn::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	int c = convert(curPos);
	int n = convert(newPos);

	// Check to see if new spot is obs

	if (n / 10 > 7 || n / 10 < 0 || n % 10 > 7 || n % 10 < 0)
		return false;

	// Check to make sure new spot is not teammate

	if (isWhite && board[n / 10][n % 10]->getType().at(0) == 'W')
		return false;
	else if (!isWhite && board[n / 10][n % 10]->getType().at(0) == 'B')
		return false;

	if (isWhite)
	{
		if ( (c - n == 11 || c - n == 9) && board[n / 10][n % 10]->getType().at(0) == 'B')
		{
			return true;
		}
		else if (c / 10 == 6 && n / 10 == 4)
		{
			return board[5][c % 10]->getType() == "--";
		}
		else if (c - n == 10)
			return true;
	}
	else
	{
		if ((c - n == -11 || c - n == -9) && board[n / 10][n % 10]->getType().at(0) == 'W')
		{
			return true;
		}
		else if (c / 10 == 1 && n / 10 == 3)
		{
			return board[2][c % 10]->getType() == "--";
		}
		else if (c - n == -10)
			return true;
	}

	return false;






	/*

	if (isWhite)
	{
		// If pawn is going to kill
		if (isKilling)
		{
			// Using chart, checks to see if next pos is diagonal one space forward
			return (n - c == -9 || n - c == -11) && board[n / 10][n % 10]->getType().at(0) == 'B';
		}
		else if (c / 10 == 6 && n / 10 == 4)
		{
			return board[5][c % 10]->getType() == "--" && board[4][c % 10]->getType() == "--";
		}
		else if (c / 10 != 0 && c / 10 > n / 10)
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
			return (n - c == 9 || n - c == 11) && board[n / 10][n % 10]->getType().at(0) == 'W';
		}
		else if (c / 10 == 1 && n / 10 == 3)
		{
			return board[2][c % 10]->getType() == "--" && board[3][c % 10]->getType() == "--";
		}
		else if (c / 10 != 7)
		{
			return board[c / 10 + 1][c % 10]->getType() == "--";
		}
	}

	return false; */
}

// Rook class

Rook::Rook(bool isWhite)
{
	this->isWhite = isWhite;
	if (isWhite)
		pieceType = "WR";
	else
		pieceType = "BR";
}

/*
	A rook can only move in horizontal or vertical directions
*/

// ROOK IS FINISHED

bool Rook::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	int c = convert(curPos);
	int n = convert(newPos);

	// Make sure out of bounds is set

	cout << c << " " << n << endl;

	// Check to see if new spot is obs

	if (n / 10 > 7 || n / 10 < 0 || n % 10 > 7 || n % 10 < 0)
		return false;

	// Check to make sure new spot is not teammate

	if (isWhite && board[n / 10][n % 10]->getType().at(0) == 'W')
		return false;
	else if (!isWhite && board[n / 10][n % 10]->getType().at(0) == 'B')
		return false;

	if (c / 10 == n / 10)
	{
		if (c % 10 - n % 10 > 0)
		{
			for (int i = c % 10 - 1; i > n % 10; i--)
			{
				if (board[c / 10][i]->getType() != "--")
					return false;
			}
		}
		else if (c % 10 - n % 10 < 0)
		{
			for (int i = c % 10 + 1; i < n % 10; i++)
			{
				if (board[c / 10][i]->getType() != "--")
					return false;
			}
		}
		return true;
	}

	else if (c % 10 == n % 10)
	{
		if (c / 10 - n / 10 > 0)
		{
			for (int i = c / 10 - 1; i > n / 10; i--)
			{
				if (board[i][c % 10]->getType() != "--")
					return false;
			}
		}
		else if (c / 10 - n / 10 < 0)
		{
			for (int i = c / 10 + 1; i < n / 10; i++)
			{
				if (board[i][c % 10]->getType() != "--")
					return false;
			}
		}
		return true;
	}
	return false;
}

// Knight class

Knight::Knight(bool isWhite)
{
	this->isWhite = isWhite;
	if (isWhite)
		pieceType = "WH";
	else
		pieceType = "BH";
}

/*
	A knight has a strange movement mechanic
	1) Must move two spaces horizontal or vertical
	2) move perpendicular one space from direction you chose
*/

// KNIGHT IS FINISHED

bool Knight::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	int c = convert(curPos);
	int n = convert(newPos);

	// Check to see if new spot is obs

	if (n / 10 > 7 || n / 10 < 0 || n % 10 > 7 || n % 10 < 0)
		return false;

	// Check to make sure new spot is not teammate

	if (isWhite && board[n / 10][n % 10]->getType().at(0) == 'W')
		return false;
	else if (!isWhite && board[n / 10][n % 10]->getType().at(0) == 'B')
		return false;

	if (c / 10 == n / 10 + 1 || c / 10 == n / 10 - 1)
	{
		if ((c % 10) == (n % 10) + 2 || (c % 10) == (n % 10) - 2)
			return true;
	}
	else if (c % 10 == n % 10 + 1 || c % 10 == n % 10 - 1)
	{
		if ((c / 10) == (n / 10) + 2 || (c / 10) == (n / 10) - 2)
			return true;
	}

	return false;
}

// Bishop class

Bishop::Bishop(bool isWhite)
{
	this->isWhite = isWhite;
	if (isWhite)
		pieceType = "WB";
	else
		pieceType = "BB";
}

/*
	A bishop can move in diagonal directions
*/

// BISHOP IS FINISHED

bool Bishop::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	int c = convert(curPos);
	int n = convert(newPos);

	// Check to see if new spot is obs

	if (n / 10 > 7 || n / 10 < 0 || n % 10 > 7 || n % 10 < 0)
		return false;

	// Check to make sure new spot is not teammate

	if (isWhite && board[n / 10][n % 10]->getType().at(0) == 'W')
		return false;
	else if (!isWhite && board[n / 10][n % 10]->getType().at(0) == 'B')
		return false;

	if ((c - n) % 9 == 0)
	{
		if (n > c) //if we are going diagonal down to the left
		{
			for (int i = c + 9; i < n; i = i + 9)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
		else if (n < c) //if we are going diagonal up to the right
		{
			for (int i = c - 9; i > n; i = i - 9)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
	}

	else if ((c - n) % 11 == 0)
	{
		if (n > c) //if we are going diagonal down to the right
		{
			for (int i = c + 11; i < n; i = i + 11)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
		else if (n < c) //if we are going diagonal up to the left
		{
			for (int i = c - 11; i > n; i = i - 11)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
	}
	return false;
}

// Queen class

Queen::Queen(bool isWhite)
{
	this->isWhite = isWhite;
	if (isWhite)
		pieceType = "WQ";
	else
		pieceType = "BQ";
}

/*
	A queen can move in diagonal, horizontal, and vertical
*/

// QUEEN IS FINISHED

bool Queen::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	int c = convert(curPos);
	int n = convert(newPos);

	// Check to see if new spot is obs

	if (n / 10 > 7 || n / 10 < 0 || n % 10 > 7 || n % 10 < 0)
		return false;

	// Check to make sure new spot is not teammate

	if (isWhite && board[n / 10][n % 10]->getType().at(0) == 'W')
		return false;
	else if (!isWhite && board[n / 10][n % 10]->getType().at(0) == 'B')
		return false;

	if ((c - n) % 9 == 0)
	{
		if (n > c) //if we are going diagonal down to the left
		{
			for (int i = c + 9; i < n; i = i + 9)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
		else if (n < c) //if we are going diagonal up to the right
		{
			for (int i = c - 9; i > n; i = i - 9)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
	}

	else if ((c - n) % 11 == 0)
	{
		if (n > c) //if we are going diagonal down to the right
		{
			for (int i = c + 11; i < n; i = i + 11)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
		else if (n < c) //if we are going diagonal up to the left
		{
			for (int i = c - 11; i > n; i = i - 11)
			{
				if (board[i / 10][i % 10]->getType() != "--")
					return false;
			}
			return true;
		}
	}

	else if (c / 10 == n / 10)
	{
		if (c > n)
		{
			for (int i = c % 10 - 1; i > n % 10; i--)
			{
				if (board[c / 10][i]->getType() != "--")
					return false;
			}
			return true;
		}
		else if (c < n)
		{
			for (int i = c % 10 + 1; i < n % 10; i++)
			{
				if (board[c / 10][i]->getType() != "--")
					return false;
			}
			return true;
		}
	}

	else if (c % 10 == n % 10)
	{
		if (n > c)
		{
			for (int i = c / 10 - 1; i > n / 10; i--)
			{
				if (board[i][c % 10]->getType() != "--")
					return false;
			}
			return true;
		}
		else if (c < n)
		{
			for (int i = c / 10 + 1; i < n / 10; i++)
			{
				if (board[i][c % 10]->getType() != "--")
					return false;
			}
			return true;
		}
	}
	return false;
}

// King class

King::King(bool isWhite)
{
	this->isWhite = isWhite;
	if (isWhite)
		pieceType = "WK";
	else
		pieceType = "BK";
}

/*
	A king can move in any direction one space
*/

bool King::move(string curPos, string newPos, bool isKilling, Piece* board[8][8])
{
	int c = convert(curPos);
	int n = convert(newPos);

	// Check to see if new spot is obs

	if (n / 10 > 7 || n / 10 < 0 || n % 10 > 7 || n % 10 < 0)
		return false;

	// Check to make sure new spot is not teammate

	if (isWhite && board[n / 10][n % 10]->getType().at(0) == 'W')
		return false;
	else if (!isWhite && board[n / 10][n % 10]->getType().at(0) == 'B')
		return false;

	if (((c-n) == 9) || ((c-n) == -9)) //going diagonal in one direction one space
	{
		if (board[n / 10][n % 10]->getType() != "--")
			return false;
		else
			return true;
	}

	else if (((c-n) == 11) || ((c-n) == -11)) //going diagonal in the other directoin
	{
		if (board[n / 10][n % 10]->getType() != "--")
			return false;
		else
			return true;
	}

	else if ((c / 10 == n / 10) && ((c - n == 10) || (c - n == -10))) //moving vertically
	{
		if (board[n / 10][n % 10]->getType() != "--")
			return false;
		else
			return true;
	}

	else if ((c % 10 == n % 10) && ((c - n == 1) || (c - n == -1))) // moving horizontally
	{
		if (board[n / 10][n % 10]->getType() != "--")
			return false;
		else
			return true;
	}
	return false;
}