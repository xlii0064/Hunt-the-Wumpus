#ifndef MONSTERS_H
#define MONSTERS_H
#include <iostream>
#include <string>
using namespace std;

class Monster
{
public:
		Monster(string type, string location);
		Monster();
		~Monster();
		string getType();
		string getLocation();
		void setLocation(string locate);
	


private:
	string type;
	string location;



};
#endif // !MONSTERS_H

