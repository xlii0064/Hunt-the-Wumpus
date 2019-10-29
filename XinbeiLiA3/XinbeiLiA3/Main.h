#ifndef MAIN_H
#define MAIN_H
#include "Monsters.h"
#include "Rooms.h"
#include <string>
#include <vector>
using namespace std;




vector <Monster *> monstersList;
vector <Rooms *> caves;
vector <int> numbers;
int currentCave;
int lattern=21;
int arrow = 5;
int bait=0;
int coin = 0;
bool quit=false;

void createRooms();
void createMonsters();
void initialiazePlayer();
int go(string roomInstruction);
void meetBat(int bat);
int shoot(string roomNum);
bool check();
void shop();
void end();


#endif // !MAIN_H

