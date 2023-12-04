
#include <iostream>

#include "map.h"

using namespace std;

/*
	Node(...) simple constructor
*/

Node::Node(string value, Node* next)
{
	this->value = value;
	this->next = next;
}

/*
	hash(...) returns int that functions as key for hash map. The function is declared as
	private in MapSC class because it is only needed locally
*/

int MapSC::hash(double a)
{
	return (int)(a * 100);
}

/*
	MapSC() initiializes the size 101 array to be empty;
*/

MapSC::MapSC()
{
	for (int i = 0; i < 101; i++)
	{
		arr[i] = new Node("", nullptr);
	}
}

/*
	add(...) adds a string to the hash map using the hash function
*/

void MapSC::add(string line)
{
	Player player(line);
	int temp = hash(player.getWLR());

	if (arr[temp]->value == "")
	{
		arr[temp] = new Node(line, nullptr);
	}

	else
	{
		Node* tempPtr = arr[temp];
		while (tempPtr->next != nullptr)
			tempPtr = tempPtr->next;
		tempPtr->next = new Node(line, nullptr);
	}
}

/*
	print(...) prints the linked list with the corresponding key
*/

void MapSC::print(double wlr)
{
	int temp = hash(wlr);
	if (arr[temp]->value == "")
		cout << "No players have this W/L Ratio" << endl;

	else
	{
		cout << "Players with " << wlr << " W/L Ratio: " << endl << endl;
		Node* tempPtr = arr[temp];
		while (tempPtr->next != nullptr)
		{
			Player player(tempPtr->value);
			cout << player << endl;
			tempPtr = tempPtr->next;
		}
		Player player(tempPtr->value);
		cout << player << endl;
	}
}
