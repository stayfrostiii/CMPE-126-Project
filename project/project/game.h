
#ifndef Game_Class
#define Game_Class

#include <iostream>
#include <queue>
#include <stack>

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
	stack<Piece* [8][8]> prevTurns;

public:
	Game(Player&, Player&);
	void create();
	bool makeMove(string, string, Player&);
	void redo();
	void takeTurn(Player&);
	void run();
	void endGW(Player&);
	void print();
};

#endif