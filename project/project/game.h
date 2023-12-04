
#ifndef Game_Class
#define Game_Class

#include <iostream>
#include <queue>
#include <stack>

#include "player.h"
#include "chessPieces.h"

/*
	Game class functions as the board that will be played on. All actions that are made 
	duringg the game will be through here as well
*/

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
	bool makeMove(string, string);
	void redo();
	void takeTurn();
	void run();
	void addRecord(Player&);
	void endGW(Player&, Player&);
	void print();
};

#endif