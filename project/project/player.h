
#ifndef Player_Class
#define Player_Class

#include <iostream>

using namespace std;

class Player
{
	private:
		string name;
		int wins;
		int losses;
		double wlr;
	public:
		Player(string);
		Player(string, int, int, double);
		string getInfo();
		Player& operator++();
		Player& operator--();
};

#endif