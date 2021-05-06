#include "Header.h"
#include "Input.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 

using namespace std;

int main(void) 
{
    int i = 0;
    int job = 0;
    int choice = 0;
    int number_of_players = 0;
    int stage = 1;
    int difficulty = 0;
    GameLoader* loader = NULL;
    Character* characters[3] = {NULL,NULL,NULL};

    do 
    {
        choice = menu();

        /*start new game*/
        if(choice == 1)
        {
            difficulty = menu3();
            number_of_players = menu1();

            for (i = 0; i < number_of_players ; i++)
            {
                job = menu2();
                create_new_character(i, job, characters);
            }
            if (start_game(stage, number_of_players, difficulty, characters))
                choice = 0;
        }
        
        /*load saved game*/
        else if(choice == 2)
        {
            loader = new GameLoader("saved_game");
            stage = loader->stage;
            difficulty = loader->difficulty;
            number_of_players = loader->number_of_players;

            characters[0] = loader->characters[0];
            characters[1] = loader->characters[1];
            characters[2] = loader->characters[2];
            cout << "Welcome back, lets see if you are ready to face your next encounter!" << endl;
            if (start_game(stage, number_of_players, difficulty, characters))
                choice = 0;
        }
    } while (choice);

	return 0;
}