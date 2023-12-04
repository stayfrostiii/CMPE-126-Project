
#ifndef Map_Class
#define Map_Class

#include "player.h"

class Node
{
	public:
		string value;
		Node* next;
		Node(string value, Node* next);
};

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