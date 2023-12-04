
#include <iostream>
#include <string>

#include "player.h"

using namespace std;

Player::Player(string name)
{
	this->name = name;
	wins = 0;
	losses = 0;
	wlr = 0;
}

Player::Player(string name, int wins, int losses, double wlr)
{
	this->name = name;
	this->wins = wins;
	this->losses = losses;
	this->wlr = wlr;
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
