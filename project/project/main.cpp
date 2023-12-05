
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>

#include "player.h"
#include "game.h"
#include "map.h"

using namespace std;

/*
	findPlayer(...) returns the line of the given player name from the names.txt document.
*/

string findPlayer(string name)
{
	string results = "";
	string line;
	string temp;

	ifstream ifile("names.txt");
	if (ifile.is_open())
	{
		while (getline(ifile, line))
		{
			temp = "";
			for (size_t i = 0; i < line.size(); i++)
			{
				if (line.at(i) == ' ')
					i = line.size();
				else
					temp += line.at(i);
			}
			if (temp == name)
			{
				results = line;
			}
		}
		ifile.close();
	}

	return results;
}

/*
	startGame() function declares a game class and two player classes. If a user-inputted player name is 
	already in the names.txt document, then the information from the document is used. If not, then a new
	player with default information is created.
*/

void startGame()
{
	string p1name;
	string p2name;

	cout << "Enter player 1: ";
	getline(cin, p1name);
	cout << "Enter player 2: ";
	getline(cin, p2name);
	cout << endl;

	string temp1 = findPlayer(p1name);
	string temp2 = findPlayer(p2name);

	if (temp1 == "")
	{
		p1name += " 0 0";
	}
	else
		p1name = temp1;

	if (temp2 == "")
	{
		p2name += " 0 0";
	}
	else
		p2name = temp2;

	Player p1(p1name);
	Player p2(p2name);

	p1.setTeam(true);
	p2.setTeam(false);

	Game game(p1, p2);

	game.print();
	game.run();
}

/*
	printAllPlayers() prints information of all players in names.txt
*/

void printAllPlayers()
{
	cout << "Printing all players from least to most recently played: " << endl << endl;
	
	string line;
	ifstream ifile("names.txt");

	if (ifile.is_open())
	{
		while (getline(ifile, line))
		{
			Player player(line);
			cout << player << endl;
		}
		ifile.close();
	}
}

/*
	lookUpStat() prints the information of the user-inputted player name
*/

void lookUpStat()
{
	string name;

	cout << "Enter name: ";
	getline(cin, name);

	string results = findPlayer(name);

	if (results == "")
	{
		cout << "No record of player" << endl;
	}
	else
	{
		Player player(results);
		cout << player;
	}
}

/*
	wlrLookUp() prints players from names.txt based on their W/L Ratio
*/

void wlrLookUp()
{
	double wlr;
	cout << "Enter W/L Ratio to look up (up to 2 decimal places): ";
	cin >> wlr;
	cout << endl;

	MapSC map;

	string line;
	ifstream ifile("names.txt");

	if (ifile.is_open())
	{
		while (getline(ifile, line))
		{
			map.add(line);
		}
		ifile.close();
	}
	map.print(wlr);
}

int main()
{
	char es;
	
	int choice;
	cout << "(1) Start new chess game" << endl
		<< "(2) Look up player stats" << endl
		<< "(3) Print all players" << endl
		<< "(4) Look up players with certain W/L Ratio" << endl
		<< "Choice: ";
	cin >> choice;
	cout << endl;

	es = cin.get();

	switch (choice)
	{
		case 1:
			startGame();
			break;
		case 2:
			lookUpStat();
			break;
		case 3:
			printAllPlayers();
			break;
		case 4:
			wlrLookUp();
			break;
	}

	return 0;
}