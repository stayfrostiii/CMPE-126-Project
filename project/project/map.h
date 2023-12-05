
#ifndef Map_Class
#define Map_Class

#include "player.h"

/*
	Node class to create separate chaining in map
*/

class Node
{
	public:
		string value;
		Node* next;
		Node(string value, Node* next);
};

/*
	MapSC class creates a size 101 array to hold 0 to 100. The hash function
	multiplies the wlr of a player by 100 and places them onto their respective key.
	The collision technique used is separate chaining so that you can find everyone 
	with the same wlr
*/

class MapSC
{
	private:
		Node* arr[101];
		int hash(double);
	public:
		MapSC();
		void add(string);
		void print(double);
};

#endif