#include <iostream>
#include <string>
#include "Rooms.h"
using namespace std;

//Constructor
Rooms::Rooms(string roomName, string linkedRoom1st, string linkedRoom2nd, string linkedRoom3rd,string generalDirections) {
	name = roomName;
	linkedRoom1stName = linkedRoom1st;
	linkedRoom2ndName = linkedRoom2nd;
	linkedRoom3rdName = linkedRoom3rd;
	generalDirection = generalDirections;
}

Rooms::Rooms() {}
Rooms::~Rooms() {}

//Accessor
string Rooms::getRoomName() { return name; }
string Rooms::getLinkedRoom1stName() { return linkedRoom1stName; }
string Rooms::getLinkedRoom2ndName() { return linkedRoom2ndName; }
string Rooms::getLinkedRoom3rdName() { return linkedRoom3rdName; }
string Rooms::getGeneralDirections() { return generalDirection; }
//Mutator

