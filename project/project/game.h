
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
		Piece* board[8][8];
		queue<Player> players;
		stack<Piece*[8][8]> prevTurns;

	public:
		Game(Player&, Player&);
		void create();
		void print();
		//void takeTurn();
};

#endif