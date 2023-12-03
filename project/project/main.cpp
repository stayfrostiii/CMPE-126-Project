
#include <iostream>
#include "player.h"
#include "game.h"
#include "chessPieces.h"

using namespace std;

int main()
{
	Player p1("daniel senpai");
	Player p2("jeremiah chan");
	
	Game game(p1, p2);

	game.print();
	cout << game.makeMove() << endl;
	game.print();

	return 0;
}