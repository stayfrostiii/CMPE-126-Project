
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
	bool isWhite;
public:
	Player(string);
	Player(string, int, int, double);
	string getInfo();
	void setTeam(bool);
	bool getTeam();
	string getName();
	Player& operator++();
	Player& operator--();
};

#endif