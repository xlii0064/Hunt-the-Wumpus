#ifndef ROOMS_H
#define ROOMS_H
#include <iostream>
#include <string>
using namespace std;

class Rooms
{
public:
	Rooms(string roomName, string linkedRoom1st, string linkedRoom2nd, string linkedRoom3rd,string generalDirections);
	Rooms();
	~Rooms();
	string getRoomName();
	string getLinkedRoom1stName();
	string getLinkedRoom2ndName();
	string getLinkedRoom3rdName();
	string getGeneralDirections();



private:
	string name;
	string linkedRoom1stName;
	string linkedRoom2ndName;
	string linkedRoom3rdName;
	string generalDirection;

};
#endif // !ROOMS_H
