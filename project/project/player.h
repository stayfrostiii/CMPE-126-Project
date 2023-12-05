
#ifndef Player_Class
#define Player_Class

#include <iostream>

using namespace std;

/*
	Player class allows for the storing of information
*/

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
	string getInfo();
	void setTeam(bool);
	bool getTeam();
	string getName();
	double getWLR();
	friend ostream& operator<<(ostream&, Player&);
	void print();
	Player& operator++();
	Player& operator--();
};

#endif