
#include <iostream>
#include <fstream>
#include <map>

#include "player.h"
#include "game.h"

using namespace std;

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
			for (int i = 0; i < line.size(); i++)
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

void openLeaderboard()
{
	string line;
	map<double, string> names;
	ifstream ifile("names.txt");

	if (ifile.is_open())
	{
		while (getline(ifile, line))
		{
			Player temp(line);
			names[temp.getWLR()] = line;
		}
		ifile.close();
	} 

	map<double, string>::iterator it = names.end();

	int count = 1;

	while (it != names.begin())
	{
		--it;
		Player temp(it->second);
		cout << count << ") " << endl << temp;
		++count;
	}
}

int main()
{
	char es;
	
	int choice;
	cout << "(1) Start new chess game" << endl
		<< "(2) Look up player stats" << endl
		<< "(3) Open Leaderboard" << endl
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
			openLeaderboard();
			break;
	}

	return 0;
}