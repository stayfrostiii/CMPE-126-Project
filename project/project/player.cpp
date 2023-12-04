
#include <iostream>
#include <string>

#include "player.h"

using namespace std;

/*
	Player(...) breaks down input string into individual information. The string is broken down into (in order):
		1) name
		2) wins
		3) losses
	W/L Ratio is determined using a simple equation
*/

Player::Player(string line)
{
	
	int part = 0;
	wins = 0;
	losses = 0;
	isWhite = true;

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
	
	wlr = (double)wins / ((double)wins + (double)losses);
}

/*
	getInto() getter function to return all information in a specific order and format in one string
*/

string Player::getInfo()
{
	return name + " " + to_string(wins) + " " + to_string(losses) + " " + to_string(wlr);
}

/*
	setTeam() setter function sets isWhite
*/

void Player::setTeam(bool isWhite)
{
	this->isWhite = isWhite;
}

/*
	getTeam() getter function returns isWhite
*/

bool Player::getTeam()
{
	return isWhite;
}

/*
	getName() getter function returns name
*/

string Player::getName()
{
	return name;
}

/*
	getWLR() getter function returns wlr
*/

double Player::getWLR()
{
	return wlr;
}

/*
	operator<<(...) allows for ease of printing the information of player
*/

ostream& operator<<(ostream& os, Player& player)
{
	os << "Name: " << player.name << endl
		<< "Wins: " << player.wins << endl
		<< "Losses: " << player.losses << endl
		<< "Win/Loss Ratio: " << player.wlr << endl;
	return os;
}

/*
	operator++() allows for easy pre-incrementation of player
		1) Increments wins
		2) Changes wlr with respect to wins/losses
*/

Player& Player::operator++()
{
	++wins;
	wlr = (double)wins / (double)(wins + losses);
	return *this;
}

/*
	operator--() allows for easy pre-decrementation of player
		1) Increments losses
		2) Changes wlr with respect to wins/losses
*/

Player& Player::operator--()
{
	++losses;
	wlr = (double)wins / (double)(wins + losses);
	return *this;
}
