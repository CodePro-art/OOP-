#include "Header.h"
#include "Input.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define players_alive (sorted_players[0] || sorted_players[1] || sorted_players[2])
#define enemies_alive (sorted_enemies[0] || sorted_enemies[1] || sorted_enemies[2])
# define bsic_attack_damage (attacker->ATK - deffender->DFF)

using namespace std;

int menu()
{
    int choice = 0;
    char pre_choice[250];

    do {
        cout << "Choose an option from the menu:" << endl;
        cout << "1. Start a new game" << endl;
        cout << "2. Load game" << endl;
        cout << "0. Exit" << endl;

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
            if (choice < 0 || choice > 2)
                cout << "Wrong input, try again." << endl;
        }
    } while (choice > 2 || choice < 0);
    return choice;
}
int menu1()
{
    int choice = 0;
    char pre_choice[250];

    do {
        cout << "Choose the number of players:" << endl;
        cout << "1. Solo play" << endl;
        cout << "2. Two players" << endl;
        cout << "3. Three players" << endl;
        cout << "0. Back" << endl;

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
            if (choice < 0 || choice > 3)
                cout << "Wrong input, try again." << endl;
        }
    } while (choice > 3 || choice < 0);
    return (choice);
}
int menu2()
{
    int choice = 0;
    char pre_choice[250];

    do {
        cout << "Please choose the character's job:" << endl;
        cout << "1. Warrior" << endl;
        cout << "2. Mage" << endl;
        cout << "3. Thief" << endl;

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
            if (choice < 1 || choice > 5)
                cout << "Wrong input, try again." << endl;
        }
    } while (choice > 3 || choice < 1);
    return (choice);
}
int menu3()
{
    int choice = 0;
    char pre_choice[250];

    do {
        cout << "Please choose difficulty:" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Normal" << endl;
        cout << "3. Hard" << endl;

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
            if (choice < 1 || choice > 5)
                cout << "Wrong input, try again." << endl;
        }
    } while (choice > 3 || choice < 1);
    return (choice);
}
void create_new_character(int i, int job, Character* (&character)[3])
{
    string name;
    if (i == 0)
    {
        cout << "Please enter a name for your first character." << endl;
        getline(cin, name);
        if (job == 1)
            character[i] = new Warrior(name);
        else if (job == 2)
            character[i] = new Mage(name);
        else if (job == 3)
            character[i] = new Thief(name);

        cout << endl << "Character created!" << endl;
        character[i]->Display();
        cout << endl;
    }
    else if (i == 1)
    {
        cout << "Please enter a name for your second character." << endl;
        getline(cin, name);
        if (job == 1)
            character[i] = new Warrior(name);
        else if (job == 2)
            character[i] = new Mage(name);
        else if (job == 3)
            character[i] = new Thief(name);

        cout << endl << "Character created!" << endl;
        character[i]->Display();
        cout << endl;
    }
    else if (i == 2)
    {
        cout << "Please enter a name for your third character." << endl;
        getline(cin, name);
        if (job == 1)
            character[i] = new Warrior(name);
        else if (job == 2)
            character[i] = new Mage(name);
        else if (job == 3)
            character[i] = new Thief(name);

        cout << endl << "Character created!" << endl;
        character[i]->Display();
        cout << endl;
    }
}
int start_game(int stage, int number_of_players, int difficulty, Character* (&character)[3])
{
    int continu = 1;
    do
    {
        if (stage == 1)
        {
            if (stage1(number_of_players, difficulty, character))
            {
                stage++;
                shop1(number_of_players, character);
                continu = save_game(stage, number_of_players, difficulty, character);
            }
            else
            {
                cout << "You lost the game, to restart, press \" start new game\" in the main menu or \"load game\"." << endl;
                return 0;
            }
        }
        else if (stage == 2)
        {
            if (stage2(number_of_players, difficulty, character))
            {
                stage++;
                shop2(number_of_players, character);
                continu = save_game(stage, number_of_players, difficulty, character);
            }
            else
            {
                cout << "You lost the game, to restart, press \" start new game\" in the main menu or \"load game\"." << endl;
                return 0;
            }
        }
        else if (stage == 3)
        {
            if (stage3(number_of_players, difficulty, character))
            {
                stage++;
                shop3(number_of_players, character);
                continu = save_game(stage, number_of_players, difficulty, character);
            }
            else
            {
                cout << "You lost the game, to restart, press \" start new game\" in the main menu or \"load game\"." << endl;
                return 0;
            }
        }
        else if (stage == 4)
        {
            if (stage4(number_of_players, difficulty, character))
            {
                stage++;
                shop4(number_of_players, character);
                continu = save_game(stage, number_of_players, difficulty, character);
            }
            else
            {
                cout << "You lost the game, to restart, press \" start new game\" in the main menu or \"load game\"." << endl;
                return 0;
            }
        }
        else if (stage == 5)
        {
            if (stage5(number_of_players, difficulty, character))
            {
                stage++;
                continu = save_game(stage, number_of_players, difficulty, character);
            }
            else
            {
                cout << "You lost the game, to restart, press \" start new game\" in the main menu or \"load game\"." << endl;
                return 0;
            }
        }
        else if (stage == 6)
        {
            cout << "Congratulations! You finished the game and won! to restart the game please choose \"start a new game\" in the main menu." << endl;
        }

    }while (continu);

    return stage;
}
void sortCharacters(Character* (&destenation)[3],Character* (&source)[3])
{
    if (source[0] && source[1] && source[2])
    {
        destenation[0] = source[0];
        destenation[1] = source[1];
        destenation[2] = source[2];

        int key, i, j;

        for (i = 1; i < 3; i++) // insertion sort
        {
            key = destenation[i]->INIT;
            j = i - 1;
            while (j >= 0 && destenation[j]->INIT < key)
            {
                destenation[j + 1]->INIT = destenation[j]->INIT;
                j = j - 1;
            }
            destenation[j + 1]->INIT = key;
        }
    }
    else if (source[0] && source[1])
    {
        if (source[0]->INIT > source[1]->INIT)
        {
            destenation[0] = source[0];
            destenation[1] = source[1];
        }
        else
        {
            destenation[1] = source[0];
            destenation[0] = source[1];
        }
        destenation[2] = NULL;
    }
    else if (source[0] && source[2])
    {
        if (source[0]->INIT > source[2]->INIT)
        {
            destenation[0] = source[0];
            destenation[1] = source[2];
        }
        else
        {
            destenation[1] = source[0];
            destenation[0] = source[2];
        }
        destenation[2] = NULL;
    }
    else if (source[1] && source[2])
    {
        if (source[2]->INIT > source[1]->INIT)
        {
            destenation[0] = source[2];
            destenation[1] = source[1];
        }
        else
        {
            destenation[1] = source[2];
            destenation[0] = source[1];
        }
        destenation[2] = NULL;
    }
    else if (source[0])
    {
        destenation[0] = source[0];
        destenation[1] = NULL;
        destenation[2] = NULL;

    }
    else if (source[1])
    {
        destenation[0] = source[1];
        destenation[1] = NULL;
        destenation[2] = NULL;
    }
    else
    {
        destenation[0] = source[2];
        destenation[1] = NULL;
        destenation[2] = NULL;
    }
}
int player_choose_target(Character* deffender, Character* (&list)[3])
{
    int choice = 0;
    char pre_choice[250];

    do {
        cout << "Please choose an enemy to attack:" << endl;
        if(list[0])
        cout << "1. " << list[0]->NAME << " with " << list[0]->hp << "/" << list[0]->HP << " and " << list[0]->DFF << " deffence." << endl;
        if (list[1])
        cout << "2. " << list[1]->NAME << " with " << list[1]->hp << "/" << list[1]->HP << " and " << list[1]->DFF << " deffence." << endl;
        if (list[2])
        cout << "3. " << list[2]->NAME << " with " << list[2]->hp << "/" << list[2]->HP << " and " << list[2]->DFF << " deffence." << endl;

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
            if ((choice < 1 || choice > 3) || !list[choice - 1])
                cout << "Wrong input, try again." << endl;
        }
    } while ((choice > 3 || choice < 1) || !list[choice-1]);
 
    deffender = list[choice-1];
    return (choice - 1);
}
int enemy_choose_target(Character* deffender, Character* (&list)[3])
{
    if (list[0] && list[1] && list[2])
    {
        if ((list[0]->hp < list[1]->hp) && (list[0]->hp < list[2]->hp))
        {
            deffender = list[0];
            return 0;
        }

        else if ((list[1]->hp < list[0]->hp) && (list[1]->hp < list[2]->hp))
        {
            deffender = list[1];
            return 1;
        }
        else
        {
            deffender = list[2];
            return 2;
        }
    }
    else if (list[0] && list[1] && !list[2])
    {
        if (list[0]->hp < list[1]->hp)
        {
            deffender = list[0];
            return 0;
        }
        else
            return 1;
    }
    else if (list[0] && !list[1] && list[2])
    {
        if (list[0]->hp < list[2]->hp)
        {
            deffender = list[0];
            return 0;
        }
        else
            return 2;
    }
    else if (!list[0] && list[1] && list[2])
    {
        if (list[1]->hp < list[2]->hp)
        {
            deffender = list[1];
            return 1;
        }
        else
            return 2;
    }
    else if (!list[0] && !list[1] && list[2])
    {
        deffender = list[2];
        return 2;
    }
    else if (!list[0] && list[1] && !list[2])
    {
        deffender = list[1];
        return 1;
    }
    else if (list[0] && !list[1] && !list[2])
    {
        deffender = list[0];
        return 0;
    }
    else
        return 0;
}

int battle(int number_of_players, int number_of_enemies, int difficulty, Character* (&character)[3], Character* (&enemies)[3])
{
    int i, j,target;
    bool all_enemies_already_attacked = false;
    bool all_players_already_attacked = false;
    Character* attacker = NULL;
    Character* deffender = NULL;
    Character* sorted_players[3] = {NULL,NULL,NULL};
    Character* sorted_enemies[3] = { NULL,NULL,NULL };
    sortCharacters(sorted_players,character);
    sortCharacters(sorted_enemies, enemies);

    while (players_alive && enemies_alive)
    {
        for (i = 0, j = 0, all_enemies_already_attacked = false, all_players_already_attacked = false; !(all_enemies_already_attacked && all_players_already_attacked);)
        {
            if (!players_alive || !enemies_alive)
            {
                break;
            }
            else if (!sorted_players[i])
            {
                if (i == 2)
                {
                    all_players_already_attacked = true;
                    i = 0;
                }   
                else
                    i++;
                continue;
            }
            else if (!sorted_enemies[j]) 
            {
                if (j == 2)
                {
                    all_enemies_already_attacked = true;
                    j = 0;
                }
                    
                else
                    j++;
                continue;
            }
            else if (!all_players_already_attacked)
            {
                if ((sorted_players[i]->INIT >= sorted_enemies[j]->INIT) || (all_enemies_already_attacked && !all_players_already_attacked))
                {
                    cout << "it's " << sorted_players[i]->NAME << "'s turn." << endl;
                    attacker = sorted_players[i];
                    target = player_choose_target(deffender, sorted_enemies);
                    deffender = sorted_enemies[target];
                    attacker->perform_attack(deffender);
                    if (deffender->hp <= 0)
                    {
                        cout << deffender->NAME << "is dead!" << endl;
                        sorted_enemies[target] = NULL;
                    }
                    if (i == 2)
                    {
                        all_players_already_attacked = true;
                        i = 0;
                    }
                    else
                        i++;
                }
            }
            else if (!all_enemies_already_attacked)
            {
                if ((sorted_players[i]->INIT < sorted_enemies[j]->INIT) || (!all_enemies_already_attacked && all_players_already_attacked))
                {
                    cout << "it's " << sorted_enemies[j]->NAME << "'s turn." << endl;
                    attacker = sorted_enemies[j];
                    target = enemy_choose_target(deffender, sorted_players);
                    deffender = sorted_players[target];
                    attacker->perform_attack(deffender);
                    if (deffender->hp <= 0)
                    {
                        deffender->hp = 0;
                        cout << deffender->NAME << " is dead!" << endl;
                        sorted_players[target] = NULL;
                    }
                    if (j == 2)
                    {
                        all_enemies_already_attacked = true;
                        j = 0;
                    }
                    else
                        j++;
                }
            }
        }
    }
    return (players_alive) ? 1 : 0;
}
int stage1_option()
{
    int choice = -1;
    char pre_choice[250];

    do {
        slow_print("You have only two options:", 30);
        slow_print("1. RUN!      or       2. FIGHT!", 100);

        cin.getline(pre_choice, sizeof(pre_choice));
        if (check(pre_choice) == false)
        {
            cout << "Wrong input, try again." << endl;
            choice = -1;
            continue;
        }
        else
        {
            choice = stoi(pre_choice, NULL);
            if (choice < 0 || choice > 3)
                cout << "Wrong input, try again." << endl;
        }
    } while (choice > 3 || choice < 0);
    return (choice);
}
int stage2_option()
{
    int choice = -1;
    char pre_choice[250];

    do {
        slow_print("You have two options:", 30);
        slow_print("1. Decline!      or       2. Accept!", 100);

        cin.getline(pre_choice, sizeof(pre_choice));
        if (check(pre_choice) == false)
        {
            cout << "Wrong input, try again." << endl;
            choice = -1;
            continue;
        }
        else
        {
            choice = stoi(pre_choice, NULL);
            if (choice < 0 || choice > 3)
                cout << "Wrong input, try again." << endl;
        }
    } while (choice > 3 || choice < 0);
    return (choice);
}
int stage4_option()
{
    int choice = 0;
    char pre_choice[250];

    do {
        slow_print("What do you do?", 30);
        slow_print("1. Kiss her hand", 100);
        slow_print("2. High five", 100);
        slow_print("3. Shake her hand", 100);
        slow_print("4. Decline politly", 100);

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
            if (choice < 1 || choice > 4)
                cout << "Not an option, try again." << endl;
        }
    } while (choice > 4 || choice < 1);
    return (choice);
}
int shop2_option()
{
    int choice = 0;
    char pre_choice[250];

    do {
        slow_print("What do you do?", 30);
        slow_print("1. follow him.      or       2. Decline politly.", 100);

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
    return choice;

}
bool check(char input[])
{
    char cha;
    int i;
    if (input[0] == '\0')
        return false;
    for (i = 0; input[i] != '\0'; i++)
    {
        cha = input[i];
        if (cha > '9' || cha < '0')
            return false;
    }
    return true;
}
