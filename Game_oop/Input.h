#pragma once

bool check(char input[]);
void create_new_character(int i, int job, Character* (&character)[3]);
void sortCharacters(Character* (&destenation)[3], Character* (&source)[3]);
int start_game(int stage, int number_of_players, int difficulty, Character* (&character)[3]);
int battle(int number_of_players, int number_of_enemies, int difficulty, Character* (&character)[3], Character* (&enemies)[3]);
int menu();
int menu1();
int menu2();
int menu3();
int stage1_option();
int stage2_option();
int stage4_option();
int shop2_option();
