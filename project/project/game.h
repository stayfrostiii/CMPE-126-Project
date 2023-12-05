
#ifndef Game_Class
#define Game_Class

#include <iostream>
#include <queue>
#include <stack>

#include "piece.h"
#include "player.h"
#include "chessPieces.h"

class Game
{
private:
	bool gameOver;

	// Board to play on
	Piece* board[8][8];

	// players will determine which player is next
	queue<Player> players;

	// prevTurns will keep track of previous turns
	stack<string> newPosition; // Stack to store previous board states
	stack<string> currentPosition;
	stack<Piece*> movingPiece; 
	stack<Piece*> stillPiece;
	
public:
	Game(Player&, Player&);
	void create();
	bool makeMove(string, string);
	void undo();
	void takeTurn();
	void run();
	void addRecord(Player&);
	void endGW(Player&, Player&);
	void print();
};

#endif