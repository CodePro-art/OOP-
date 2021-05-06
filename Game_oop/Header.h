#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Character
{
public:
	string NAME;			// The name of the character
	int hp;					// The current hit points
	int HP;					// Maximun hit points of the character
	int mp;					// The current mana points
	int MP;					// Maximum mana points of the character
	int exp;				// The current experience of the character
	int EXP;				// Maximum experience to level up for the current level
	int GOLD;				// Current gold amount 
	int INIT;				// Initiative of the character to determine turn order
	int ATK;				// Attack of the character
	int DFF;				// Defense of the character
	int LVL;				// Level of the character
	int Torso;				// Item for the torso
	int Hands;				// Item for the hands
	int Head;				// Item for the head
	int Legs;				// Item for the legs

public:
	virtual void Display();
	virtual void Heal(int x);
	virtual void GainEXP(int x);
	virtual void LoseHP(int x);
	virtual void perform_attack(Character* deffender);
	virtual void LevelUP();
	virtual void shop();
	Character(string name);
	Character();
	~Character();
};

class Warrior : public Character
{
public:
	void LevelUP();
	void perform_attack(Character* deffender);
	void shop();
	Warrior(string name);
	Warrior();
	~Warrior();
};
class Mage : public Character
{
public:
	void LevelUP();
	void perform_attack(Character* deffender);
	void shop();
	Mage(string name);
	Mage();
	~Mage();
};
class Thief : public Character
{
public:
	void LevelUP();
	void perform_attack(Character* deffender);
	void shop();
	Thief(string name);
	Thief();
	~Thief();
};

class GameLoader
{
public:
	int number_of_players;
	int difficulty;
	int stage;
	string jobs[3];
	Character* characters[3];
	GameLoader(string fileName); // used in loading game from file
	GameLoader(int number_of_players, int difficulty, int stage, Character* chars[]); // used before writing to a file
	void writeGameToFile(string fileName) const;
	~GameLoader(){}
};

class Villiger : public Character
{
public:
	void perform_attack(Character* deffender);
	Villiger(string name, int number_of_players, int difficulty);
	Villiger();
	~Villiger();
};
class Hooded_woman : public Character
{
public:
	void perform_attack(Character* deffender);
	Hooded_woman(string name, int number_of_players, int difficulty);
	Hooded_woman();
	~Hooded_woman();
};
class Zombie : public Character
{
public:
	void perform_attack(Character* deffender);
	Zombie(string name, int number_of_players, int difficulty);
	Zombie();
	~Zombie();
};
class Bear : public Character
{
public:
	void perform_attack(Character* deffender);
	Bear(string name, int number_of_players, int difficulty);
	Bear();
	~Bear();
};
class Dead_man : public Character
{
public:
	void perform_attack(Character* deffender);
	Dead_man(string name, int number_of_players, int difficulty);
	Dead_man();
	~Dead_man();
};
class Skeleton : public Character
{
public:
	void perform_attack(Character* deffender);
	Skeleton(string name, int number_of_players, int difficulty);
	Skeleton();
	~Skeleton();
};

void slow_print(const std::string& str,int delay_time);
int save_game(int stage, int number_of_players, int difficulty, Character* (&character)[3]);

int stage1(int number_of_players, int difficulty, Character* (&character)[3]);
int stage2(int number_of_players, int difficulty, Character* (&character)[3]);
int stage3(int number_of_players, int difficulty, Character* (&character)[3]);
int stage4(int number_of_players, int difficulty, Character* (&character)[3]);
int stage5(int number_of_players, int difficulty, Character* (&character)[3]);
void shop1(int number_of_players, Character* (&character)[3]);
void shop2(int number_of_players, Character* (&character)[3]);
void shop3(int number_of_players, Character* (&character)[3]);
void shop4(int number_of_players, Character* (&character)[3]);