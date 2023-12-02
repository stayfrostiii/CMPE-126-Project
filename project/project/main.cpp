
#include <iostream>
#include "player.h"
#include "game.h"

using namespace std;

int main()
{
	Player p1("daniel senpai");
	Player p2("jeremiah chan");
	
	Game game(p1, p2);

	game.print();

	return 0;
}