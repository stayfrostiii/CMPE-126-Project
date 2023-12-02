
#ifndef Game_Class
#define Game_Class

#include <iostream>
#include <queue>
#include <stack>

#include "player.h"
#include "board.h"

class Game
{
	private:
		Player& black;
		Player& white;
		Board& board;

		queue<Player> players;
		stack<Board> prevTurns;

	public:
};

#endif