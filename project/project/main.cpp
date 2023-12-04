
#include <iostream>
#include "player.h"
#include "game.h"

using namespace std;

int main()
{
	Player p1("daniel senpai");
	Player p2("jeremiah chan");

	p1.setTeam(true);
	p2.setTeam(false);

	Game game(p1, p2);

	game.print();
	game.run();

	return 0;
}