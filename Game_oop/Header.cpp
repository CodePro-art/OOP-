#include "Header.h"
#include "Input.h"
#include <fstream>
#include <sstream>
#include <string>

#define basic_attack_damage (this->ATK - deffender->DFF)

using namespace std;

void slow_print(const std::string& str, int delay_time) {
	for (size_t i = 0; i != str.size(); ++i) {
		std::cout << str[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
	}
	cout << endl;
}
int save_game(int stage, int number_of_players,int difficulty, Character* (&character)[3])
{
	int choice = 1;
	char pre_choice[250];
	GameLoader* save = NULL;
	save = new GameLoader(number_of_players, difficulty, stage, character);
	do {
		cout << "The game is automaticly saved after each senario (now)." << endl;
		cout << "To continue to the next senario please press 1." << endl;
		cout << "To stop now and continue later from this point please press 0." << endl;

		cin.getline(pre_choice, sizeof(pre_choice));
		if (check(pre_choice) == false)
		{
			cout << "Wrong input, try again." << endl;
			choice = 0;
			continue;
		}
		else
		{
			choice = stoi(pre_choice, NULL);
			if (choice < 0 || choice > 1)
				cout << "Wrong input, try again." << endl;
		}
	} while (choice > 1 || choice < 0);


	save->writeGameToFile("saved_game");

	return (choice);
}

int stage1(int number_of_players, int difficulty, Character* (&character)[3])
{
	int i,choice = 0;
	int number_of_enemies = 3;
	Character* enemies[3] = { new Zombie("zombie 1", number_of_players, difficulty), new Zombie("zombie 2", number_of_players, difficulty), new Zombie("zombie 3", number_of_players, difficulty) };
	
	slow_print("You wander in the streets of Mydgard at night, it seems like you are all alone.",30);
	slow_print("You see someone enters a narrow alley, you decide to follow him.",30);
	slow_print("The man appears to be dying, you ask for his name and offer some help.",30);
	slow_print("The man wisper something, hand you a piece of paper and suddenly dies . . .",30);
	slow_print(" . . .",250);
	slow_print("You hear some noises behind you and turn around to see 3 zombies and a hooded man",40);

	choice = stage1_option();
	
	if (choice == 1)
	{
		slow_print("\"You are so cute.. you actualy thought you could escape\" said the hooded man.",30);
		slow_print("He appeared right in front of you and left you no other chance but to fight", 30);
		slow_print("With no other options you draw your weapon!", 30);
	}
	else
		slow_print("You charge at your opponent and the battle begins.", 30);
	
	if (battle(number_of_players, number_of_enemies, difficulty, character, enemies)) // battle won
	{
		slow_print("You WON!!. You gained 15 exp.", 100);
		for (i = 0; i < 3; i++)
			if (character[i])
				character[i]->GainEXP(15);
		slow_print("Once you defeated all the zombies you noticed that the hooded person vanished", 30);
		slow_print("You wonder to yourself what just happened.", 30);
		slow_print("You look at the paper that the dying man gave you and read it:", 30);
		slow_print("\"It has happend to me, you are next!\"", 30);
		
		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 1;
	}
	else
	{
		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 0;
	}
}
int stage2(int number_of_players, int difficulty, Character* (&character)[3]) {

	int i,choice = 0;
	int number_of_enemies = 3;
	Character* enemies[3] = { new Villiger("Villiger 1", number_of_players, difficulty), new Villiger("Villiger 2", number_of_players, difficulty), new Villiger("Villiger 3", number_of_players, difficulty) };
	Character* enemies1[3] = { new Bear("Bear 1", number_of_players, difficulty), new Bear("Bear 2", number_of_players, difficulty), new Bear("Bear 3", number_of_players, difficulty) };

	slow_print("You bearly had some sleep and you feal the tireness build up.", 30);
	slow_print("\"AAhhhh!!\" you hear a woman scream from behind you.", 30);
	slow_print("Hear children start to eat her arm as she passes out.", 30);
	slow_print("Before they are fully satified you knock them out, they are unconcious.", 30);
	slow_print("The people around saw what happened and rewarded you with a quest and offer you to find a cure for those children.", 30);
	slow_print("They claim to have money and goods for you in return for your services.", 30);

	choice = stage2_option();
	if (choice == 1)
	{
		slow_print("They don't like to hear \"No\" as an answer, now tou have to fight them.", 30);

		if (battle(number_of_players, number_of_enemies, difficulty, character, enemies1)) // battle won
		{

			slow_print("You emarged victorious! congratulations, now you should probably take the money for saving the mother and leave.", 30);
			slow_print("You loot one of the defeated villigers. Gain 30 GOLD.", 30);

			slow_print("You find yourself a place to sleep, now that you defeated the villigers everybody is afraid of you.", 30);

			slow_print("You gained 20 exp.", 100);
			for (i = 0; i < 3; i++)
				if (character[i])
					character[i]->GainEXP(20);
			
			slow_print("You heal to MAX hp!", 100);
			for (i = 0; i < 3; i++)
				if (character[i])
					character[i]->Heal(20);
			
			slow_print("You gain 30 GOLD!", 100);
			for (i = 0; i < 3; i++)
				if (character[i])
					character[i]->GOLD += 30;
			

			delete enemies[0];
			delete enemies[1];
			delete enemies[2];
			delete enemies1[0];
			delete enemies1[1];
			delete enemies1[2];
			return 1;
		}
		else
		{
			delete enemies[0];
			delete enemies[1];
			delete enemies[2];
			delete enemies1[0];
			delete enemies1[1];
			delete enemies1[2];
			return 0;
		}
	}
	else
	{
		slow_print("You leave the villigers to search for the rare Lotus flower that has medical properties to save the children.", 30);
		slow_print("This flower can be found in the nearby forest, but it is gaurded by beasts that don't like sharing.", 30);
		slow_print("You easily find the forest, near its entrance you find a sign: \" Beware! roaming bears! VERY DANGEROUS!!\".", 30);
		slow_print("You decide to go in to find the flower. Suddenly you see a tiny bear cub sniffing a flower that looks just like the rare Lotus.", 30);
		slow_print("Maybe it's your lucky day, you get close to the cub, and at that moment one giant male bear appears! lets see if you can get out alive this time!", 30);

		if (battle(number_of_players, number_of_enemies, difficulty, character, enemies)) // battle won
		{
			slow_print("You emarged victorious! it wasn't easy as you thought, you probably should head back to the village with the flower.", 30);
			slow_print("The villigers were so happy the offer you some rest in the best inn around and a huge meal for free.", 100);
		    
			for (i = 0; i < 3; i++)
				if (character[i])
					character[i]->GainEXP(20);
			slow_print("You gained 20 exp.", 100);

			for (i = 0; i < 3; i++)
				if (character[i])
					character[i]->Heal(20);
			slow_print("You heal to MAX hp!", 100);

			delete enemies[0];
			delete enemies[1];
			delete enemies[2];
			delete enemies1[0];
			delete enemies1[1];
			delete enemies1[2];
			return 1;
		}
		else
		{
			delete enemies[0];
			delete enemies[1];
			delete enemies[2];
			delete enemies1[0];
			delete enemies1[1];
			delete enemies1[2];
			return 0;
		}
	}
}
int stage3(int number_of_players, int difficulty, Character* (&character)[3])
{
	int i;
	int number_of_enemies = 1;
	Character* enemies[3] = { new Dead_man("dead man", number_of_players, difficulty) ,NULL,NULL};
	slow_print("After a long sleep you wake up to find yourelf in a basement (oh yeah and you are shackeled).", 30);
	slow_print("You manage to free yourself from the shackels. But how the fuck did you get here?!", 30);
	slow_print("You hear steps coming down the stairs and a key unlock the door...", 30);
	slow_print("The dead man from the ally seems to be alive and in perfect health. He ask you to identify yourself.", 30);
	slow_print(" . . .", 250);
	slow_print("You linger with your answer.. The man does not hesitate to kill you, he jumps at you with his sword!! ", 40);
	slow_print("The fight beggins!", 30);

	if (battle(number_of_players, number_of_enemies, difficulty, character, enemies)) // battle won
	{
		slow_print("You gained 25 exp.", 100);
		for (i = 0; i < 3; i++)
			if (character[i])
				character[i]->GainEXP(25);
		slow_print("You defeated the dead man.", 30);
		slow_print("You open the door and go upstairs.", 30);

		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 1;
	}
	else
	{
		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 0;
	}
}
int stage4(int number_of_players, int difficulty, Character* (&character)[3]) {

	int i,choice;
	int number_of_enemies = 3;
	Character* enemies[3] = { new Hooded_woman("Minerva", number_of_players, difficulty), NULL,NULL };

	slow_print("You think about the \"dead man\", how was he so strong?! ", 30);
	slow_print("It probably has something to do with the hooded man.", 30);
	slow_print("You walk to the nearby pub to have a drink and relax a little.", 30);
	slow_print("\"Beer please\" you say to the bartender.", 30);
	slow_print("\"Right away\" sais the bartendr.", 30);
	slow_print("\"Make it two\" you hear a woman voice from behind you, as she sits right next to you.", 30);
	slow_print("She is very beautiful and attractive. You wonder if she is royalty.", 30);
	slow_print("She gives you her hand as though to kiss it.", 40);

	choice = stage4_option();

	if (choice == 1)
	{
		slow_print("You feel dizzy...", 40);
		slow_print("What is happannig?...", 40);
		slow_print("You fall to the floor, your heart stops beating.", 40);
		slow_print("You are dead.", 40);
		delete[] &enemies;
		return 0;
		
	}
	else if (choice == 2)
	{
		slow_print("She seems disapointed, and sit right next to you.", 40);
		slow_print("Your hand starts to bleed and rot.", 40);
		slow_print("You are probably uder a curse of that woman.", 40);
		slow_print("You swiftly draw your weapon to fight", 40);
	}
	else if (choice == 3)
	{
		slow_print("She seems disapointed, and sit right next to you.", 40);
		slow_print("Your hand starts to bleed and rot.", 40);
		slow_print("You are probably uder a curse of that woman.", 40);
		slow_print("You swiftly draw your weapon to fight", 40);
	}
	else if (choice == 4)
	{
		slow_print("She seems disapointed and goes away.", 40);
		slow_print("As ahe turns her back to you, you notice her hoodie and figure out that she must be the \"hooded man\" from before.", 40);
		slow_print("you decide to leave your beer behind and fight her!", 40);
	}

	if (battle(number_of_players, number_of_enemies, difficulty, character, enemies)) // battle won
	{
		slow_print("You defeated the hodded woman! now you know how powerful a necomancer can be!", 30);
		slow_print("You gained 30 exp.", 100);
		for (i = 0; i < 3; i++)
			if (character[i])
				character[i]->GainEXP(30);
		
		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 1;
	}
	else
	{
		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 0;
	}
}
int stage5(int number_of_players, int difficulty, Character* (&character)[3]) 
{
	int i;
	int number_of_enemies = 3;
	Character* enemies[3] = { new Skeleton("skeleton 1", number_of_players, difficulty), new Skeleton("skeleton 1", number_of_players, difficulty),new Skeleton("skeleton 1", number_of_players, difficulty) };

	slow_print("As you leave the bar, the corps of the hooded woman rise up, she seems skeleton-like and wrinkeled.", 30);
	slow_print("She starts laughing. Then, she wisper a few words and a glowing green light submerges from the ground and with it an army of skeletons you must face!", 30);
	slow_print("The poor bartender hides behind his counter and begs for your help.", 30);
	slow_print("\"The REAL battle begins now\" The woman laughs!", 30);

	if (battle(number_of_players, number_of_enemies, difficulty, character, enemies)) // battle won
	{
		slow_print("You emerged victorius!", 30);
		slow_print("You gained 35 exp.", 100);
		for (i = 0; i < 3; i++)
			if (character[i])
				character[i]->GainEXP(35);

		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 1;
	}
	else
	{
		delete enemies[0];
		delete enemies[1];
		delete enemies[2];
		return 0;
	}
}
void shop1(int number_of_players, Character* (&character)[3])
{
	int i;
	slow_print("You somehow survived the night, dawn is here, the sun rises.", 30);
	slow_print("Hey YOU! yeah you! I have the best equipment you will ever buy!", 30);
	slow_print("You are lucky!! I only have a few left. Please, look around.", 30);
	cout << endl << endl;
	slow_print("NOTE: The items you bye cannot be replaced! only to be upgraded!", 30);

	for (i = 0; i < number_of_players; i++)
		character[i]->shop();
	slow_print("Thanks for stopping by, please come again!", 30);
}
void shop2(int number_of_players, Character* (&character)[3]) {

	int i,choice = 0;
	slow_print("You are exusted from the fight, you deseve some rest, you pass out and sleep", 30);
	slow_print(". . . ", 30);
	slow_print("After waking up you noticr that the cure you obtained is missing.", 30);
	slow_print("But you still have your items and money...", 30);
	slow_print("You decide to go back to the villigers and try to help the children anyway.", 30);
	slow_print("Upon your arrival you see the villigers cry and you understand that the children died.", 30);
	slow_print("The villigers seem to know what happaned to you but they tell you not.", 30);
	slow_print("One of them wisper in your ear to go with him.", 30);

	choice = shop2_option();

	if (choice == 1)
	{
		slow_print("You follow the shaggy guy to an ally.", 30);
		slow_print("Then he opens a door to a secret shop:", 30);
		for (i = 0; i < number_of_players; i++)
			character[i]->shop();
		slow_print("Thanks for stopping by, please come again!", 30);
	}
	else if (choice == 2)
	{
		slow_print("\"Your loss\" he sais.", 30);
		slow_print("The guy seems disapointed and disappears into an ally.", 30);
	}
}
void shop3(int number_of_players, Character* (&character)[3])
{
	int i;
	slow_print("Just as you leave the basement and the house you where in, you find a small shop.", 30);
	slow_print("\" Welcome! it's nice to see new faces around here. Can I help you?\" said a young man with a wide smile.", 30);
	slow_print("\"Please look around, looking is free of charge.\" ", 30);
	for (i = 0; i < number_of_players; i++)
		character[i]->shop();
	slow_print("Thanks for stopping by, please come again!", 30);
}
void shop4(int number_of_players, Character* (&character)[3])
{
	int i;
	slow_print("Exusted from the fight, the bartender offer you a drink.", 30);
	slow_print("You take the offer and drink to your heart's content. ", 30);
	slow_print("You suddenly feel a surge of power waking through your body.", 30);
	slow_print("You now know that the bartendet added a healing potion to your favorite drink! What a bro!.", 30);

	for (i = 0; i < number_of_players; i++)
		character[i]->Heal(20);
	slow_print("You are healed! (20 HP)", 30);
}

GameLoader::GameLoader(int number_of_players, int difficulty, int stage, Character* chars[])
{
	this -> number_of_players = number_of_players;
	this-> difficulty = difficulty;
	this-> stage = stage;

	for (int i = 0; i < number_of_players; i++)
	{
		characters[i] = new Character;
		characters[i] = chars[i];
		if (typeid(*chars[i]).name() == "class Thief")
			jobs[i] = "Thief";
		else if (typeid(*chars[i]).name() == "class Mage")
			jobs[i] = "Mage";
		else
			jobs[i] = "Warrior";
	}
}
GameLoader::GameLoader(string fileName) // Load data from file
{
	string name;
	this-> difficulty = 0;
	this-> stage = 0;
	this-> number_of_players = 0;
	this-> characters[0] = NULL;
	this-> characters[1] = NULL;
	this-> characters[2] = NULL;
	/*
		redaing from a file format:
		number of players
		difiiculty level
		game's stage
		for each charcter:
		### (to seperate between charcters)
		job
		all data members row by row...
	*/
	ifstream INFile(fileName);
	string line;
	while (!INFile.eof())
	{
		getline(INFile, line);
		stringstream(line) >> number_of_players;
		getline(INFile, line);
		stringstream(line) >> difficulty;
		getline(INFile, line);
		stringstream(line) >> stage;

		for (int i = 0; i < number_of_players; i++)
		{
			getline(INFile, line); // read ###
			getline(INFile, line);
			stringstream(line) >> jobs[i];
			getline(INFile, line);
			stringstream(line) >> name;
			if (jobs[i] == "Thief")
				characters[i] = new Thief(name);
			else if(jobs[i] == "Warrior")
				characters[i] = new Warrior(name);
			else
				characters[i] = new Mage(name);
			getline(INFile, line);
			stringstream(line) >> characters[i]->hp;
			getline(INFile, line);
			stringstream(line) >> characters[i]->HP;
			getline(INFile, line);
			stringstream(line) >> characters[i]->mp;
			getline(INFile, line);
			stringstream(line) >> characters[i]->MP;
			getline(INFile, line);
			stringstream(line) >> characters[i]->exp;
			getline(INFile, line);
			stringstream(line) >> characters[i]->EXP;
			getline(INFile, line);
			stringstream(line) >> characters[i]->GOLD;
			getline(INFile, line);
			stringstream(line) >> characters[i]->INIT;
			getline(INFile, line);
			stringstream(line) >> characters[i]->ATK;
			getline(INFile, line);
			stringstream(line) >> characters[i]->DFF;
			getline(INFile, line);
			stringstream(line) >> characters[i]->LVL;
			getline(INFile, line);
			stringstream(line) >> characters[i]->Torso;
			getline(INFile, line);
			stringstream(line) >> characters[i]->Hands;
			getline(INFile, line);
			stringstream(line) >> characters[i]->Head;
			getline(INFile, line);
			stringstream(line) >> characters[i]->Legs;
		}
		break;
	}
	INFile.close(); // close the file
}
void GameLoader::writeGameToFile(string fileName) const
{
	/*
	writing to a file format:
	number of players
	difiiculty level
	game's stage
	for each charcter:
	### (to seperate between charcters)
	job
	all data members row by row...
	*/
	ofstream outFile(fileName, ios::out); // open output file
	if (outFile.fail()) exit(1);
	outFile << number_of_players << endl;
	outFile << difficulty << endl;
	outFile << stage << endl;
	for (int i = 0; i < number_of_players; i++)
	{
		outFile << "###" << endl;
		outFile << jobs[i] << endl;
		outFile << characters[i]->NAME << endl;
		outFile << characters[i]->hp << endl;
		outFile << characters[i]->HP << endl;
		outFile << characters[i]->mp << endl;
		outFile << characters[i]->MP << endl;
		outFile << characters[i]->exp << endl;
		outFile << characters[i]->EXP << endl;
		outFile << characters[i]->GOLD << endl;
		outFile << characters[i]->INIT << endl;
		outFile << characters[i]->ATK << endl;
		outFile << characters[i]->DFF << endl;
		outFile << characters[i]->LVL << endl;
		outFile << characters[i]->Torso << endl;
		outFile << characters[i]->Hands << endl;
		outFile << characters[i]->Head << endl;
		outFile << characters[i]->Legs << endl;
	}
	outFile.close(); // close output file
}

Character::Character(string name)
{
	NAME = name;
	hp = 0;
	HP = 0;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 0;
	ATK = 0;
	DFF = 0;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Character::Character()
{
	NAME = "";
	hp = 0;
	HP = 0;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 0;
	ATK = 0;
	DFF = 0;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Character::~Character()
{}

void Character::Display()
{
	cout << endl;
	cout << "Character Information:" << endl;
	cout << "Name: " << NAME << endl;
	cout << "Hit points: " << hp << endl;
	cout << "Mana points: " << mp << endl;
	cout << "Expirience: " << exp << endl;
	cout << "Gold: " << GOLD << endl;
	cout << "Initiative: " << INIT << endl;
	cout << "Attack: " << ATK << endl;
	cout << "Deffense: " << DFF << endl;
	cout << "Level: " << LVL << endl;
}
void Character::Heal(int x)
{
	if (x + hp < HP)
		hp += x;
	else
		hp = HP;
}
void Character::GainEXP(int x)
{
	exp += x;
	if (exp >= EXP)
		LevelUP();
}
void Character::LoseHP(int x)
{
	if (hp < x)
		hp = 0;
	else
		hp -= x;
}
void Character::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
}
void Character::LevelUP()
{
	LVL++;
	EXP = 2* (EXP + LVL);
}
void Character::shop()
{
}

void Warrior::LevelUP()
{
	cout << endl;
	cout << endl;
	LVL++;
	cout << NAME << " Leveled UP!" << endl;
	cout << "From level: " << LVL - 1 << " to level: " << LVL << endl;
	EXP = 2 * (EXP + LVL);
	cout << "Max hit point increased from: " << HP << " to: " << HP + 2 << endl;
	cout << "You are fully healed!" << endl;
	HP += 3;;
	hp = HP;
	cout << "Your attack increased from: " << ATK << " to: " << ATK + 3 << endl;
	ATK += 3;
	cout << "Your deffence increased from: " << DFF << " to: " << DFF + (LVL) % 3 + 1<< endl;
	DFF += (LVL) % 3 + 1;
	cout << endl;
	cout << endl;
}
void Warrior::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic warrior attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
}
void Warrior::shop()
{
	int choice = 0;
	char pre_choice[250];
	do {
		cout << this->NAME << ", Please choose an option from the shop (10 gold each):" << endl;
		cout << "0. Thanks, I rather not buy!" << endl;
		cout << "1. Torso: upgrade Armor (warrior only) + 1 DFF." << endl;
		cout << "2. Hands: upgrade Sword (warrior only) + 1 ATK." << endl;
		cout << "3. Head: upgrade Helmet (warrior only) + 1 DFF." << endl;
		cout << "4. Torso: upgrade Robe (Mage only) + 1 HP." << endl;
		cout << "5. Hands: upgrade Staff (Mage only) + 1 MP." << endl;
		cout << "6. Head: upgrade cape (Mage only) + 1 DFF" << endl;
		cout << "7. Torso: upgrade Agile shirt (Thief only) + 1 HP." << endl;
		cout << "8. Hands: upgrade Daggers (Thief only) + 1 ATK." << endl;
		cout << "9. Head: upgrade concealing hat (Thief only) + 1 DFF." << endl;
		cout << "10. Legs: upgrade Shoes (available to all) + 1 INIT." << endl;

		cin.getline(pre_choice, sizeof(pre_choice));
		if (check(pre_choice) == false)
		{
			cout << "Wrong input, try again." << endl;
			choice = 0;
			continue;
		}
		else
		{
			choice = stoi(pre_choice, NULL);
			if (choice < 0 || choice > 10)
				cout << "Wrong input, try again." << endl;
			else if (choice != 0 && choice != 10 && choice != 1 && choice != 2 && choice != 3)
				cout << "Warrior cannot buy this item. Please try (0-3 or 10)." << endl;
		}
	} while (choice != 0 && choice != 10 && choice != 1 && choice != 2 && choice != 3);

	if (this->GOLD < 10)
	{
		cout << "Sorry, you dont have enough gold to buy an item."<< endl;
	}
	else if (choice == 0)
	{
		cout << "OK! have a nice day sir :)" << endl;
	}
	else if (choice == 1)
	{
		cout << "You bought an upgrade to your armor!" << endl;
		cout << "You gained +1 to your deffence." << endl;
		this->DFF++;
		this->Torso++;
		this->GOLD -= 10;
	}
	else if (choice == 2)
	{
		cout << "You bought an upgrade to your sword!" << endl;
		cout << "You gained +1 to your attack." << endl;
		this->ATK++;
		this->Hands++;
		this->GOLD -= 10;
	}
	else if (choice == 3)
	{
		cout << "You bought an upgrade to your helmet!" << endl;
		cout << "You gained +1 to your deffence." << endl;
		this->DFF++;
		this->Head++;
		this->GOLD -= 10;
	}
	else if (choice == 10)
	{
		cout << "You bought an upgrade to your boots!" << endl;
		cout << "You gained +1 to your initiative." << endl;
		this->INIT++;
		this->Legs++;
		this->GOLD -= 10;
	}
}
Warrior::Warrior(string name) : Character(name)
{
	NAME = name;
	hp = 15;
	HP = 15;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 10;
	INIT = 10;
	ATK = 6;
	DFF = 4;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Warrior::Warrior()
{
}
Warrior::~Warrior()
{
}

void Mage::LevelUP()
{
	cout << endl;
	cout << endl;
	LVL++;
	cout << NAME << " Leveled UP!" << endl;
	cout << "From level: " << LVL - 1 << " to level: " << LVL << endl;
	EXP = 2 * (EXP + LVL);
	cout << "Max hit points increased from: " << HP << " to: " << HP + 2 << endl;
	cout << "You are fully healed!" << endl;
	HP +=2;
	hp = HP;
	cout << "Max mana points increased from: " << MP << " to: " << MP + 3 << endl;
	cout << "Your mana is fully restored!" << endl;
	MP +=3;
	mp = MP;
	cout << "Your attack increased from: " << ATK << " to: " << ATK + 1<< endl;
	ATK += 1;
	if (LVL%2)
		cout << "Your deffence increased from: " << DFF << " to: " << DFF + (LVL) % 2 << endl;
	DFF += (LVL) % 2;
	cout << endl;
	cout << endl;
}
void Mage::perform_attack(Character* deffender)
{
	int choice = 0;
	char pre_choice[250];

	if (this->mp > 3)
	{
		do {
			cout << "Do you want to perform magic attack? COST: 3 mp. you currently have" << this->mp << " out of " << this->MP << " mana points." << endl;
			cout << "1. Perform basic attack." << endl;
			cout << "2. Perform magic attack." << endl;
			cin.getline(pre_choice, sizeof(pre_choice));
			if (check(pre_choice) == false)
			{
				cout << "Wrong input, try again." << endl;
				choice = 0;
				continue;
			}
			else
			{
				choice = stoi(pre_choice, NULL);
				if (choice < 1 || choice > 2)
					cout << "Wrong input, try again." << endl;
			}
		} while (choice > 2 || choice < 1);

		if (choice == 2)
		{
			cout << this->NAME << " used magic attack on " << deffender->NAME << "." << endl;
			cout << deffender->NAME << "lost 4 hp (armor ignored)." << endl;
			deffender->LoseHP(4);
			this->mp -= 3;
		}
		else
		{
			cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
			if (basic_attack_damage > 0)
			{
				cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
				deffender->hp -= basic_attack_damage;
			}
			else
				cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
		}
	}
	else
	{
		cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
		if (basic_attack_damage > 0)
		{
			cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
			deffender->hp -= basic_attack_damage;
		}
		else
			cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
	}
}
void Mage::shop()
{
	int choice = 0;
	char pre_choice[250];
	do {
		cout << this->NAME << ", Please choose an option from the shop (10 gold each):" << endl;
		cout << "0. Thanks, I rather not buy!" << endl;
		cout << "1. Torso: upgrade Armor (warrior only) + 1 DFF." << endl;
		cout << "2. Hands: upgrade Sword (warrior only) + 1 ATK." << endl;
		cout << "3. Head: upgrade Helmet (warrior only) + 1 DFF." << endl;
		cout << "4. Torso: upgrade Robe (Mage only) + 1 HP." << endl;
		cout << "5. Hands: upgrade Staff (Mage only) + 1 MP." << endl;
		cout << "6. Head: upgrade cape (Mage only) + 1 DFF" << endl;
		cout << "7. Torso: upgrade Agile shirt (Thief only) + 1 HP." << endl;
		cout << "8. Hands: upgrade Daggers (Thief only) + 1 ATK." << endl;
		cout << "9. Head: upgrade concealing hat (Thief only) + 1 DFF." << endl;
		cout << "10. Legs: upgrade Shoes (available to all) + 1 INIT." << endl;

		cin.getline(pre_choice, sizeof(pre_choice));
		if (check(pre_choice) == false)
		{
			cout << "Wrong input, try again." << endl;
			choice = 0;
			continue;
		}
		else
		{
			choice = stoi(pre_choice, NULL);
			if (choice < 0 || choice > 10)
				cout << "Wrong input, try again." << endl;
			else if (choice != 0 && choice != 10 && choice != 4 && choice != 5 && choice != 6)
				cout << "Mage cannot buy this item. Please try (4-6 or 10 or 0)." << endl;
		}
	} while (choice != 0 && choice != 10 && choice != 4 && choice != 5 && choice != 6);

	if (this->GOLD < 10)
	{
		cout << "Sorry, you dont have enough gold to buy an item." << endl;
	}
	else if (choice == 0)
	{
		cout << "OK! have a nice day sir :)" << endl;
	}
	else if (choice == 4)
	{
		cout << "You bought an upgrade to your Robe!" << endl;
		cout << "You gained +1 to your hit points." << endl;
		this->HP++;
		this->hp++;
		this->Torso++;
		this->GOLD -= 10;
	}
	else if (choice == 5)
	{
		cout << "You bought an upgrade to your staff!" << endl;
		cout << "You gained +1 to your mana points." << endl;
		this->MP++;
		this->mp++;
		this->Hands++;
		this->GOLD -= 10;
	}
	else if (choice == 6)
	{
		cout << "You bought an upgrade to your cape!" << endl;
		cout << "You gained +1 to your deffence." << endl;
		this->DFF++;
		this->Head++;
		this->GOLD -= 10;
	}
	else if (choice == 10)
	{
		cout << "You bought an upgrade to your boots!" << endl;
		cout << "You gained +1 to your initiative." << endl;
		this->INIT++;
		this->Legs++;
		this->GOLD -= 10;
	}
}
Mage::Mage(string name) : Character(name)
{
	NAME = name;
	hp = 10;
	HP = 10;
	mp = 10;
	MP = 10;
	exp = 0;
	EXP = 10;
	GOLD = 10;
	INIT = 8;
	ATK = 3;
	DFF = 3;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Mage::Mage()
{
}
Mage::~Mage()
{
}

void Thief::LevelUP()
{
	cout << endl;
	cout << endl;
	LVL++;
	cout << NAME <<" Leveled UP!" << endl;
	cout << "From level: " << LVL - 1 << " to level: " << LVL <<endl;
	EXP = 2 * (EXP + LVL);
	cout << "Max hit points increased from: " << HP << " to: " << HP+3 << endl;
	cout << "You are fully healed!" << endl;
	HP += 3;;
	hp = HP;
	cout << "Your attack increased from: " << ATK << " to: " << ATK + 2 << endl;
	ATK += 2;
	if (LVL % 3)
		cout << "Your deffence increased from: " << DFF << " to: " << DFF + (LVL)%3 << endl;
	DFF += (LVL) % 3;
	cout << "You also gained 3 GOLD:) because you are a thief." << endl;
	GOLD += 3;
	cout << endl;
	cout << endl;
}
void Thief::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;

	this -> GOLD += 2;
	cout << this->NAME << " performed steal action! gained 2 GOLD!" << endl;
}
void Thief::shop()
{
	int choice = 0;
	char pre_choice[250];
	do {
		cout << this->NAME << ", Please choose an option from the shop (10 gold each):" << endl;
		cout << "0. Thanks, I rather not buy!" << endl;
		cout << "1. Torso: upgrade Armor (warrior only) + 1 DFF." << endl;
		cout << "2. Hands: upgrade Sword (warrior only) + 1 ATK." << endl;
		cout << "3. Head: upgrade Helmet (warrior only) + 1 DFF." << endl;
		cout << "4. Torso: upgrade Robe (Mage only) + 1 HP." << endl;
		cout << "5. Hands: upgrade Staff (Mage only) + 1 MP." << endl;
		cout << "6. Head: upgrade cape (Mage only) + 1 DFF" << endl;
		cout << "7. Torso: upgrade Agile shirt (Thief only) + 1 HP." << endl;
		cout << "8. Hands: upgrade Daggers (Thief only) + 1 ATK." << endl;
		cout << "9. Head: upgrade concealing hat (Thief only) + 1 DFF." << endl;
		cout << "10. Legs: upgrade Shoes (available to all) + 1 INIT." << endl;

		cin.getline(pre_choice, sizeof(pre_choice));
		if (check(pre_choice) == false)
		{
			cout << "Wrong input, try again." << endl;
			choice = 0;
			continue;
		}
		else
		{
			choice = stoi(pre_choice, NULL);
			if (choice < 0 || choice > 10)
				cout << "Wrong input, try again." << endl;
			else if (choice != 0 && choice != 10 && choice != 7 && choice != 8 && choice != 9)
				cout << "Thief cannot buy this item. Please try (7-10 or 0)." << endl;
		}
	} while (choice!= 0 && choice != 10 && choice != 7 && choice != 8 && choice != 9);

	if (this->GOLD < 10)
	{
		cout << "Sorry, you dont have enough gold to buy an item." << endl;
	}
	else if (choice == 0)
	{
		cout << "OK! have a nice day sir :)" << endl;
	}
	else if (choice == 4)
	{
		cout << "You bought an upgrade to your shirt!" << endl;
		cout << "You gained +1 to your hit points." << endl;
		this->HP++;
		this->hp++;
		this->Torso++;
		this->GOLD -= 10;
	}
	else if (choice == 5)
	{
		cout << "You bought an upgrade to your daggers!" << endl;
		cout << "You gained +1 to your attack." << endl;
		this->ATK++;
		this->Hands++;
		this->GOLD -= 10;
	}
	else if (choice == 6)
	{
		cout << "You bought an upgrade to your hat!" << endl;
		cout << "You gained +1 to your deffence." << endl;
		this->DFF++;
		this->Head++;
		this->GOLD -= 10;
	}
	else if (choice == 10)
	{
		cout << "You bought an upgrade to your boots!" << endl;
		cout << "You gained +1 to your initiative." << endl;
		this->INIT++;
		this->Legs++;
		this->GOLD -= 10;
	}

}
Thief::Thief(string name) : Character(name)
{
	NAME = name;
	hp = 12;
	HP = 12;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 5;
	INIT = 13;
	ATK = 5;
	DFF = 3;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;

}
Thief::Thief()
{
}
Thief::~Thief()
{
}

void Villiger::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
}
Villiger::Villiger(string name, int number_of_players, int difficulty) : Character(name)
{
	NAME = name;
	hp = 4 + number_of_players + difficulty;
	HP = 4 + number_of_players + difficulty;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 3;
	ATK = 1 + number_of_players;
	DFF = 0 + difficulty;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Villiger::Villiger()
{
}
Villiger::~Villiger()
{
}

void Hooded_woman::perform_attack(Character* deffender)
{
	if (this->mp > 3)
	{
		cout << this->NAME << " used magic attack on " << deffender->NAME << "." << endl;
		cout << deffender->NAME << "lost 4 hp (armor ignored)." << endl;
		deffender->LoseHP(4);
		this->mp -= 3;

	}
	else
	{
		cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
		if (basic_attack_damage > 0)
		{
			cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
			deffender->hp -= basic_attack_damage;
		}
		else
			cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
	}
}
Hooded_woman::Hooded_woman(string name, int number_of_players, int difficulty) : Character(name)
{
	NAME = name;
	hp = 20 + number_of_players * 2 + difficulty;
	HP = 20 + number_of_players * 2 + difficulty;
	mp = 10 + difficulty * 2;
	MP = 10 + difficulty * 2;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 11;
	ATK = 3 + number_of_players;
	DFF = 3 + difficulty;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Hooded_woman::Hooded_woman()
{
}
Hooded_woman::~Hooded_woman()
{
}

void Zombie::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
}
Zombie::Zombie(string name, int number_of_players, int difficulty) : Character(name)
{
	NAME = name;
	hp = 5 + number_of_players + difficulty;
	HP = 5 + number_of_players + difficulty;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 7;
	ATK = 2 + number_of_players;
	DFF = 1 + difficulty;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Zombie::Zombie()
{
}
Zombie::~Zombie()
{
}

void Dead_man::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
}
Dead_man::Dead_man(string name, int number_of_players, int difficulty) : Character(name)
{
	NAME = name;
	hp = 7 + number_of_players + difficulty;
	HP = 7 + number_of_players + difficulty;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 9;
	ATK = 5 + number_of_players;
	DFF = 2 + difficulty;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Dead_man::Dead_man()
{
}
Dead_man::~Dead_man()
{
}

void Skeleton::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
}
Skeleton::Skeleton(string name, int number_of_players, int difficulty) : Character(name)
{
	NAME = name;
	hp = 3 + number_of_players + difficulty;
	HP = 3 + number_of_players + difficulty;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 9;
	ATK = 6 + number_of_players + difficulty;
	DFF = 2;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Skeleton::Skeleton()
{
}
Skeleton::~Skeleton()
{
}

void Bear::perform_attack(Character* deffender)
{
	cout << this->NAME << " Used basic attack on " << deffender->NAME << "." << endl;
	if (basic_attack_damage > 0)
	{
		cout << deffender->NAME << " lost " << basic_attack_damage << " hp." << endl;
		deffender->hp -= basic_attack_damage;
	}
	else
		cout << deffender->NAME << " deffended successfuly and did not lose hp." << endl;
}
Bear::Bear(string name, int number_of_players, int difficulty) : Character(name)
{
	NAME = name;
	hp = 6 + number_of_players + difficulty;
	HP = 6 + number_of_players + difficulty;
	mp = 0;
	MP = 0;
	exp = 0;
	EXP = 10;
	GOLD = 0;
	INIT = 8;
	ATK = 6 + number_of_players;
	DFF = 0 + difficulty;
	LVL = 0;
	Torso = 0;
	Hands = 0;
	Head = 0;
	Legs = 0;
}
Bear::Bear()
{
}
Bear::~Bear()
{
}
