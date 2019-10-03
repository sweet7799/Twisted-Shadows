#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#include "start.h"

int main(void)
{
  int snail_health = 100;
  int char_health;
  int char_class;
  char name[20];
  int status[10] = { };
  //      0          1        2        3      4      5      6      7      8        9
  // [P. Health][P. Max][O. Health][O. Max][Class][Enemy][Bash][Poison][Salve][M. Shield]

//Start of Game

  system("clear");

  printf("Welcome to \033[1;31mTwisted Shadows\033[0m\n\n");
  printf("Press ENTER to continue\n");
  getchar();
  system("clear");
  printf("What is your character's name?\n");
  scanf("%20s", name);
  //char_class = class();
  status[4] = class();
  //char_health = set_health(char_class);
  status[0] = set_health(status[4]);
  status[1] = set_health(status[4]);

  //Set up Snail
  status[2] = 100;
  status[3] = 100;
  //char_health = combat(char_health, snail_health, char_class);
  status[0] = combat(status);
  system("clear");
  if(status[0] <= 0)
  {
    printf("Defeat\n");
    getchar();
  }
  else
  {
    printf("%s won with %d Health Points\n", name, status[0]);
    //printf("You won with %d Health Points\n", status[0]);
    getchar();
  }

  return 0;
}
