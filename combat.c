#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "combat.h"


//      0          1        2        3      4      5      6      7      8        9
// [P. Health][P. Max][O. Health][O. Max][Class][Enemy][Bash][Poison][Salve][M. Shield]

void status(int stats[])
{
  //Prints out current health of player and opponent
printf("Giant Snail\n");
  printf("___¶¶¶____¶¶¶___________¶¶¶¶¶¶¶¶¶¶¶¶\n\
___¶¶¶____¶¶¶________¶¶¶¶¶¶¶____¶¶¶¶¶¶¶\n\
___¶¶¶____¶¶______¶¶¶¶__¶______¶¶____¶¶¶¶\n\
___¶¶¶____¶¶____¶¶¶____¶¶_____¶¶_______¶¶¶\n\
____¶_¶¶¶¶¶¶__¶¶¶¶_____¶¶_____¶_____¶¶¶__¶¶\n\
___¶¶__¶¶¶_¶_¶¶¶_¶_____¶¶¶¶¶¶¶¶¶¶¶¶_¶¶____¶¶\n\
_¶¶¶_o______¶¶¶__¶__¶¶¶¶¶_____¶__¶¶¶¶_____¶¶\n\
¶¶__________¶¶___¶¶¶¶¶_¶_____¶_____¶¶¶_____¶\n\
¶¶__¶_______¶¶___¶¶___¶_¶¶¶¶¶¶_______¶¶¶¶¶¶¶\n\
¶¶¶¶¶¶¶_____¶____¶¶_____¶¶¶___¶¶¶¶¶¶¶¶¶____¶\n\
__¶¶¶¶¶¶¶___¶¶___¶¶¶___¶¶_¶¶¶¶_¶¶____¶¶____¶\n\
________¶¶__¶¶___¶¶¶¶¶¶¶¶__¶¶¶_¶¶____¶_____¶\n\
_________¶___¶¶___¶___¶¶¶¶__¶¶¶_¶__¶¶¶¶¶__¶¶\n\
_________¶____¶¶¶_¶¶____¶¶¶¶¶__¶¶¶¶¶___¶¶¶¶\n\
______¶¶¶¶______¶¶¶¶¶_____¶¶¶¶¶¶¶_______¶¶\n\
_____¶¶¶____________¶¶¶¶¶¶______¶_____¶¶¶¶\n\
_____¶¶¶¶¶¶¶¶_________¶¶¶¶¶¶____¶¶¶¶¶¶¶__¶¶\n\
_________¶¶¶¶¶¶¶¶¶¶¶_____¶¶¶¶¶¶¶¶¶¶¶______¶\n\
_____________¶¶__¶¶¶¶___________________¶¶¶\n\
____________________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n\n");


  printf("Opponent's Health: %d/%d\n", stats[2], stats[3]);
  printf("Your Health: %d/%d\n\n", stats[0], stats[1]);
}

void cleric(int stats[])
{
  char input[20];
  char one[] = "1";
  char two[] = "2";
  char three[] = "3";

  printf("Select a move:\n");
  printf("1: Smash - Deal 10 Damage\n");
  printf("2: Heal - Regain 10 Health Points\n");
  printf("3: Convert - Take 5 Damage, Deal 20 Damage\n\n");

  scanf("%20s", input);

  if(strcmp(input, one) == 0)
  {
    stats[2] = stats[2] - 10;
    system("clear");
    printf("You used Smash.\n");
    printf("You dealt\033[1;31m 10\033[0m Damage.\n");
  }
  else if(strcmp(input, two) == 0)
	{
    stats[0] = stats[0] + 10;
    system("clear");
    printf("You used Heal.\n");
	  printf("You healed\033[0;32m 10\033[0m Health Points.\n");
  }
  else if(strcmp(input, three) == 0)
  {
    stats[0] = stats[0] - 5;
    stats[2] = stats[2] - 20;
    system("clear");
    printf("You used Convert.\n");
    printf("You dealt\033[1;31m 5\033[0m Damage to yourself.\n");
    printf("You dealt\033[1;31m 20\033[0m Damage to your opponent.\n");
  }
  else
  {
    cleric(stats);
  }
}

void fighter(int stats[])
{
  char input[20];
  char one[] = "1";
  char two[] = "2";
  char three[] = "3";
  int damage;
  stats[6] = 0; //Reset Shield Bash
  //time_t t;
	//srand((unsigned) time(&t));
  srand(time(0));

  printf("Select a move:\n");
  printf("1: Slash - Deal 8-13 Damage\n");
  printf("2: Charge - Deal 5 - 17 Damage\n");
  printf("3: Shield Bash - Prevent 5 Damage, Deal 5 Damage\n\n");

  scanf("%20s", input);

  if(strcmp(input, one) == 0)
	{
	  damage = (rand() % (13 - 8 + 1)) + 8;
    stats[2] = stats[2] - damage;
    system("clear");
    printf("You used Slash.");
	  printf("You dealt\033[1;31m %d\033[0m Damage.\n", damage);
	}
  else if(strcmp(input, two) == 0)
	{
	  damage = (rand() % (17 - 5 + 1)) + 5;
    stats[2] = stats[2] - damage;
    system("clear");
    printf("You used Charge.");
	  printf("You dealt\033[1;31m %d\033[0m Damage.\n", damage);
	}
  else if(strcmp(input, three) == 0)
  {
    stats[6] = 1;
    stats[2] = stats[2] - 5;
    system("clear");
    printf("You used Shield Bash.\n");
    printf("You dealt\033[1;31m 5\033[0m Damage.\n");
  }
  else
  {
    fighter(stats);
  }
}

void druid(int stats[])
{
  char input[20];
  char one[] = "1";
  char two[] = "2";
  char three[] = "3";

  printf("Select a move:\n");
  printf("1: Strike - Deal 12 Damage\n");
  printf("2: Poison Dart - Deal 5 Damage/turn for 3 Turns\n");
  printf("3: Salve - Heal 4 Health Points/turn for 4 Turns\n\n");

  scanf("%20s", input);

  if(strcmp(input, one) == 0)
  {
    stats[2] = stats[2] - 12;
    system("clear");
    printf("You used Strike.\n");
    printf("You dealt\033[1;31m 12\033[0m Damage.\n");
  }
  else if(strcmp(input, two) == 0)
	{
    system("clear");
    printf("You used Poison Dart.\n");
    stats[7] = stats[7] + 3;
  }
  else if(strcmp(input, three) == 0)
  {
    system("clear");
    printf("You used Salve.\n");
    stats[8] = stats[8] + 4;
  }
  else
  {
    druid(stats);
  }
  if(stats[7] > 0)
  {
    stats[7] = stats[7] - 1;
    stats[2] = stats[2] - 5;
    printf("Poison dealt\033[1;31m 5\033[0m Damage.\n");
  }
  if(stats[8] > 0)
  {
    stats[8] = stats[8] - 1;
    stats[0] = stats[0] + 4;
    printf("Salve healed\033[0;32m 4\033[0m Health Points.\n");
  }
}

void mage(int stats[])
{
  char input[20];
  char one[] = "1";
  char two[] = "2";
  char three[] = "3";
  int damage;

  printf("Select a move:\n");
  printf("1: Blast - Deal 10 Damage\n");
  printf("2: Shock - Deal 20%% of enemy's current Health Points\n");
  printf("3: Magic Shield - Negate 4 Damage/turn for 3 Turns\n\n");

  scanf("%20s", input);

  if(strcmp(input, one) == 0)
  {
    stats[2] = stats[2] - 10;
    system("clear");
    printf("You used Blast.\n");
    printf("You dealt\033[1;31m 10\033[0m Damage.\n");
  }
  else if(strcmp(input, two) == 0)
  {
    system("clear");
    damage = stats[2]/5;
    stats[2] = stats[2] - damage;
    printf("You used Shock\n");
    printf("You dealt\033[1;31m %d\033[0m Damage.\n", damage);
  }
  else if(strcmp(input, three) == 0)
  {
    system("clear");
    printf("You used Magic Shield.\n");
    stats[9] = stats[9] + 3;
  }
  else
  {
    mage(stats);
  }
}

void turn(int stats[])
{
  if(stats[4] == 1)
  {
    cleric(stats);
  }
  else if(stats[4] == 2)
  {
    fighter(stats);
  }
  else if(stats[4] == 3)
  {
    druid(stats);
  }
  else
  {
    mage(stats);
  }
}

void oturn(int stats[])
{
  int damage;
  int healing;
  time_t t;
  srand((unsigned) time(&t));
  int selection;

  selection = rand() % 6;
  if(stats[2] < 35)
  {
    if(selection < 4)
    {
      healing = (rand() % (10 - 3 + 1)) + 3;
      stats[2] = stats[2] + healing;
      printf("Your opponent healed\033[0;32m %d\033[0m health points\n\n", healing);
    }
    else if(selection == 4)
    {
      damage = (rand() % (12 - 8 + 1)) + 8;

      if(stats[6] > 0)
      {
        damage = damage - 5;
        stats[6] = 0;
      }
      if(stats[9] > 0)
      {
        damage = damage - 4;
        stats[9] = stats[9] - 1;
      }

      stats[0] = stats[0] - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n\n", damage);
    }
    else
    {
      damage = (rand() % (15 - 5 + 1)) + 5;

      if(stats[6] > 0)
      {
        damage = damage - 5;
        stats[6] = 0;
      }
      if(stats[9] > 0)
      {
        damage = damage - 4;
        stats[9] = stats[9] - 1;
      }

      stats[0] = stats[0] - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n\n", damage);
    }
  }
  else
  {
    if(selection < 2)
    {
      healing = (rand() % (10 - 3 + 1)) + 3;
      stats[2] = stats[2] + healing;
      printf("Your opponent healed\033[0;32m %d\033[0m health points\n\n", healing);
    }
    else if(selection < 4)
    {
      damage = (rand() % (12 - 8 + 1)) + 8;

      if(stats[6] > 0)
      {
        damage = damage - 5;
        stats[6] = 0;
      }
      if(stats[9] > 0)
      {
        damage = damage - 4;
        stats[9] = stats[9] - 1;
      }

      stats[0] = stats[0] - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n\n", damage);
    }
    else
    {
      damage = (rand() % (15 - 5 + 1)) + 5;

      if(stats[6] > 0)
      {
        damage = damage - 5;
        stats[6] = 0;
      }
      if(stats[9] > 0)
      {
        damage = damage - 4;
        stats[9] = stats[9] - 1;
      }

      stats[0] = stats[0] - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n\n", damage);
    }
  }

}

int combat(int stats[])
{
  system("clear");

  while(stats[2] > 0 && stats[0] > 0)
  {
    if(stats[2] > stats[3])
    {
      stats[2] = stats[3];
    }
    if(stats[0] > stats[1])
    {
      stats[0] = stats[1];
    }
    status(stats);
    turn(stats);
    oturn(stats);
  }

return stats[0];
}
