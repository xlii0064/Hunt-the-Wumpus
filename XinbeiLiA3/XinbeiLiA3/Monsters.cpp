#include <iostream>
#include <string>
#include "Monsters.h"
using namespace std;

Monster::Monster(string MonsterName,string MonsterLo) {
	type = MonsterName;
	location = MonsterLo;

}
Monster::Monster() {}
Monster::~Monster() {}

//Accessor
string Monster::getType() { return type; }
string Monster::getLocation() {
	return location;
}

//Mutator
void Monster::setLocation(string lo) {
	location = lo;
}