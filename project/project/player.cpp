
#include <iostream>
#include <string>

#include "player.h"

using namespace std;

Player::Player(string line)
{
	
	int part = 0;
	wins = 0;
	losses = 0;

	for (int i = 0; i < line.size(); i++)
	{
		switch (part)
		{
			case 0:
				if (line.at(i) == ' ')
					++part;
				else
					name += line.at(i);
				break;

			case 1:
				if (line.at(i) == ' ')
					++part;
				else
					wins = wins * 10 + line.at(i) - '0';
				break;

			case 2:
				if (line.at(i) == ' ')
					++part;
				else
					losses = losses * 10 + line.at(i) - '0';
				break;
		}
	}
	
	wlr = (double)wins / (double)(wins + losses);
}

string Player::getInfo()
{
	return name + " " + to_string(wins) + " " + to_string(losses) + " " + to_string(wlr);
}

void Player::setTeam(bool isWhite)
{
	this->isWhite = isWhite;
}

bool Player::getTeam()
{
	return isWhite;
}

string Player::getName()
{
	return name;
}

double Player::getWLR()
{
	return wlr;
}

ostream& operator<<(ostream& os, Player& player)
{
	os << "Name: " << player.name << endl
		<< "Wins: " << player.wins << endl
		<< "Losses: " << player.losses << endl
		<< "Win/Loss Ratio: " << player.wlr << endl;
	return os;
}

Player& Player::operator++()
{
	++wins;
	wlr = (double)wins / (double)(wins + losses);
	return *this;
}

Player& Player::operator--()
{
	++losses;
	wlr = (double)wins / (double)(wins + losses);
	return *this;
}
