#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Main.h"
#include <ctime> 
using namespace std;
void help() {
	string temp;
	fstream file;
	file.open("read me.txt");
	while (getline(file, temp)) {
		cout << temp<<endl;
	}
	system("pause");
	file.close();
}
void createRooms() {
	string room,roomName,room1stName,room2ndName,room3rdName,gengeralDirection;
	fstream file;
	file.open("rooms.txt");
	for (int num = 0;num < 20;num++) {
		file >> roomName;
		file>> room1stName;
		file >> room2ndName;
		file >> room3rdName;
		gengeralDirection = "You can see tunnels to " + room1stName + ", " + room2ndName + " and " + room3rdName;
		room = "cave" + num;
		Rooms* room = new Rooms(roomName,room1stName, room2ndName, room3rdName,gengeralDirection);
		caves.push_back(room); 
	}
	file.close();
	
}
void createMonsters() {
	srand(time(0));
	int wumpusLocation = rand() % 20;
	Monster* wumpus= new Monster("W", caves[wumpusLocation]->getRoomName());//
	monstersList.push_back(wumpus);
	numbers.erase(numbers.begin()+ wumpusLocation);
	int bat1Location = rand() % 19;
	Monster* bat1st =new Monster("B", caves[numbers[bat1Location]]->getRoomName());
	monstersList.push_back(bat1st);
	numbers.erase(numbers.begin() + bat1Location);
	int bat2Location = rand() % 18;
	Monster* bat2nd = new Monster("B", caves[numbers[bat2Location]]->getRoomName());
	monstersList.push_back(bat2nd);
	numbers.erase(numbers.begin() + bat2Location);
	int pit1Location = rand() % 17;
	Monster *pit1st =new Monster("P", caves[numbers[pit1Location]]->getRoomName());
	monstersList.push_back(pit1st);
	numbers.erase(numbers.begin() + pit1Location);
	int pit2Location = rand() % 16;
	Monster *pit2nd=new Monster("P", caves[numbers[pit2Location]]->getRoomName());
	monstersList.push_back(pit2nd); 
	numbers.erase(numbers.begin() + pit2Location);
	Monster *magicalBait=new Monster("M", caves[numbers[rand() % 15]]->getRoomName());
	monstersList.push_back(magicalBait);

}
void initialiazePlayer() {
	int startRoom = numbers[rand() % 15];
	srand(time(0));
	for (int num = 0;num < 20;num++) {
		if (caves[num]->getLinkedRoom1stName() == caves[startRoom]->getRoomName()) {
			currentCave = num;
			break;
		}
	}
	currentCave=go(caves[currentCave]->getLinkedRoom1stName());
}
int go(string roomInstruction) {
	string surroundings="";
	bool valid = false, next = false;
	//check if it's a valid cave name
	int thisRoom=0;
	while (thisRoom < caves.size()) {
		if (roomInstruction == caves[thisRoom]->getRoomName()) {
			valid = true;
			break;
		}
		thisRoom++;
	}
	if (!valid) { cout << "Invalid cave.";return currentCave; }
	//check if it's the linked cave
	if (roomInstruction == caves[currentCave]->getLinkedRoom1stName()) { next = true; }
	if (roomInstruction == caves[currentCave]->getLinkedRoom2ndName()) { next = true; }
	if (roomInstruction == caves[currentCave]->getLinkedRoom3rdName()) { next = true; }
	if (!next) { cout << "This cave is not next to the current cave.";return currentCave; }
	currentCave = thisRoom;
	for (int num = 0;num < 6;num++) {
		if (roomInstruction == monstersList[num]->getLocation()) {
			if (monstersList[num]->getType() == "W") { 
				if (bait == 0) {
					cout << "You met a wumpus and became a room service.\n";
					end();
				}
				else {
					bait -= 1;
					cout << "The wumpus was attracted by your magic bait and you ran away. Wumpus moved its position.";
					int move = rand() % 20;
					while (move == currentCave) { move = rand() % 20; }
					monstersList[0]->setLocation(caves[move]->getRoomName());
				}
				break;
			}
			if (monstersList[num]->getType() == "P") { 
				cout << "You fell into a pit and break all of your bones.\n";
				end(); 
			}
			if (monstersList[num]->getType() == "B") { meetBat(num); return currentCave; }
			if (monstersList[num]->getType() == "M") { 
				cout << "You are lucky and found a wild magical bait.\n";
				bait += 1;
				monstersList[num]->setLocation("None");
			}
		}
			if (monstersList[num]->getLocation() == caves[thisRoom]->getLinkedRoom1stName()) {
				if (monstersList[num]->getType() == "W") { surroundings += "You smell a wumpus\n"; }
				if (monstersList[num]->getType() == "B") { surroundings += "You hear a flapping\n"; }
				if (monstersList[num]->getType() == "P") { surroundings += "You feel a breeze\n"; }
			}
			if (monstersList[num]->getLocation() == caves[thisRoom]->getLinkedRoom2ndName()) {
				if (monstersList[num]->getType() == "W") { surroundings += "You smell a wumpus\n"; }
				if (monstersList[num]->getType() == "B") { surroundings += "You hear a flapping\n"; }
				if (monstersList[num]->getType() == "P") { surroundings += "You feel a breeze\n"; }
			}
			if (monstersList[num]->getLocation() == caves[thisRoom]->getLinkedRoom3rdName()) {
				if (monstersList[num]->getType() == "W") { surroundings += "You smell a wumpus\n"; }
				if (monstersList[num]->getType() == "B") { surroundings += "You hear a flapping\n"; }
				if (monstersList[num]->getType() == "P") { surroundings += "You feel a breeze\n"; }
			}
		
	}
	system("cls");
	cout << "You are in " + caves[thisRoom]->getRoomName() + " now\n";
	cout << caves[thisRoom]->getGeneralDirections()<<"\n";
	cout << surroundings<<endl;

	srand(time(0));
	//Get coins
	int chanceToWin = rand() % 20;
	int chanceToGetCoin = rand() % 20;
	if (chanceToWin == 0) { coin += 6;cout << "Congratulations, you are very very lucky and found 6 coins.\n"; }
	else {
		if (0 <= chanceToGetCoin && chanceToGetCoin <= 9) {
			coin += 1;
			cout << "You found 1 coin.\n";
		}
		if (10 <= chanceToGetCoin && chanceToGetCoin <= 14) {
			coin += 1;
			cout << "You did not find any coin.\n";
		}
		if (15 <= chanceToGetCoin && chanceToGetCoin <= 19) {
			coin += 2;
			cout << "You found 2 coins.\n";
		}
	}
	lattern -= 1;
	cout << "You now have " <<coin<<" coin(s) and "<<lattern<< " drop(s) of lattern oil and "<<arrow<<" arrow(s).\n";
	return currentCave;
}
void meetBat(int bat) {
	srand(time(0));
	int playerPlace,batPlace;
	cout << "You met a bat.";
	batPlace = rand() % 20;
	monstersList[bat]->setLocation(caves[rand() % 20]->getRoomName());
	lattern += 1;
	playerPlace = rand() % 20;
	while (playerPlace == batPlace && playerPlace==currentCave) {
		playerPlace = rand() % 20;
	}
	for (int num = 0;num < 20;num++) {
		if (caves[num]->getLinkedRoom1stName() == caves[playerPlace]->getRoomName()) {
			currentCave = num;
			break;
		}
	}
	currentCave=go(caves[currentCave]->getLinkedRoom1stName());

}
int shoot(string roomInstruction) {
	bool valid = false,next=false;
	int thisRoom=0;
	while (thisRoom < caves.size()) {
		if (roomInstruction == caves[thisRoom]->getRoomName()) {
			valid = true;
			break;
		}
		thisRoom++;
	}
	if (!valid) { cout << "Invalid cave.";return currentCave; }
	if (roomInstruction == caves[currentCave]->getLinkedRoom1stName()) {next = true;}
	if (roomInstruction == caves[currentCave]->getLinkedRoom2ndName()) { next = true;}
	if (roomInstruction == caves[currentCave]->getLinkedRoom3rdName()) { next = true; }
	if (!next) { cout << "This cave is not next to the current cave.";return currentCave; }
	
	arrow -= 1;
	if (monstersList[0]->getLocation() == roomInstruction) {
		cout << "You killed the wupus and win the game.";
		system("pause");
		quit = true;
	}
	else {
		srand(time(0));
		int change = rand() % 4;
		if (!(change == 0)) { monstersList[0]->setLocation(caves[rand() % 20]->getRoomName()); }
		cout << "You missed and now have " << arrow << " arrow(s).\n";
	}
}
void shop() {
	bool quitting = false, valid = false;
	string item;
	cout << "Welcome to the store! You now have " << coin << " coin(s)." << endl;
	cout << "We have the following items(Enter 'Q' to quit):\n";
	cout << "1. 3 extra narrows----------------6 coins\n";
	cout << "2. 2 extra drop of lattern oil----7 coins\n";
	cout << "3. 1 extra magical bait-----------20 coins\n";
	while (!quitting) {
		cout << "Enter the sequence number you want to purchase(number only!)";
		cin >> item;
		if (item == "1" && coin >= 6) {
			cout << "Purchase Succseefully.\n";
			coin -= 6;
			arrow += 3;
			valid = true;
		}
		if (item == "2" && coin >= 7) {
			cout << "Purchase Succseefully.\n";
			coin -= 7;
			lattern += 2;
			valid = true;
		}
		if (item == "3" && coin >= 20) {
			cout << "Purchase Succseefully.\n";
			coin -= 20;
			bait += 1;
			valid = true;
		}
		if (item == "Q") {
			valid = true;
			quitting = true;
			cout << "Waiting for your coming back. Thank you.\n";
		}
		if (!valid) {
			cout << "Invalid item or invalid remaining coins.\n";
		}
	}
}
void end() {
	cout << "No! You Died!Better Luck Next Time";
	system("pause");
	quit = true;
}
bool check() {
	if (lattern == 0) {
		cout << "You ran out of lattern oil.You cannot see anything.\n";
		end();
		return false;
	}
	if (arrow == 0) {
		cout << "You ran out of arrows.You cannot kill anything and you were eaten by the wumpus at last.\n";
		end();
		return false;
	}
	return true;
}

int main() {
	string instruction;
	for (int num = 0;num < 20;num++) { numbers.push_back(num); }
	help();
	createRooms();
	createMonsters();
	initialiazePlayer();
	while (!quit) {
		bool alive;
		alive=check();
		if (!alive) { break; }
		bool valid = false;
		cout << "What do you want to do?\n";
		getline(cin, instruction);
		if (instruction.substr(0, 2) == "go") {
			currentCave=go(instruction.substr(3));
			valid = true;
			
		}
		if (instruction.substr(0, 5) == "shoot") { 
			shoot(instruction.substr(6));
			valid = true; }
		if (instruction == "shop") { 
			shop();
			valid = true; }
		if (!valid) {
			cout << "Invalid\n";
		}
	}
	//Delete the pointers before the program ends
	for (int num = 0;num < 20;num++) {
		delete caves[num];
	}
	for (int num = 0;num < 6;num++) {
		delete monstersList[num];
	}
	caves.empty();
	monstersList.empty();
	return 0;
}