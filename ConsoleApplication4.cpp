// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <fstream>

class Point
{
	int x;
	int y;
	std::string name;
public:
	void savePoint()
	{
		std::ifstream wow;
		wow.open("math.txt", std::ios::binary);

		if (!wow.is_open())
		{
			std::cout << "error opening file";
			return;
		}
		else {
			std::ofstream now;
			now.open("math.txt", std::ios::binary);
			now.write((char*) &x, sizeof(x));
			now.write((char*) &y, sizeof(y));
			now.write(name.data(), sizeof(char) * name.size());
		}
		wow.close();

	}
	void readPoint()
	{
		std::ofstream wow;
		wow.open("math.txt", std::ios::binary | std::ios::ate);
		if(!wow.is_open())
		{
			std::cout << "error opening file";
			return;
		}
		else
		{
			std::ifstream now;
			now.open("math.txt", std::ios::binary | std::ios::ate);
			now.read(std::ios::beg, 7);

		}

	}

};
class Serializer
{
private:
	std::queue<Point> q;
	std::stack<Point> s;
	std::list<Point> l;
public:

	void save()
	{
		std::ifstream potoche("poli.txt", std::ios::binary);
		if (!potoche.is_open())
		{
			std::cout << "error";
			return;
		}
		else
		{

		}
		potoche.close();

	}
	void read()
	{

	}

};


int main()
{

	return 0;
}

