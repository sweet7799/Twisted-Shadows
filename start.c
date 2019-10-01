#include <stdio.h>
#include <stdlib.h>


int class()
{
Start:
  system("clear");
  char selection[20];
  char second;
  //comparisons
  char one[] = "1"; char cap_c[] = "C"; char c[] = "c"; char cler[] = "Cleric";
  char two[] = "2"; char cap_f[] = "F"; char f[] = "f"; char figh[] = "Fighter";
  char three[] = "3"; char cap_d[] = "D"; char d[] = "d"; char drui[] = "Druid";
  char four[] = "4"; char cap_m[] = "M"; char m[] = "m"; char mage[] = "Mage";
  printf("Select your class\n\n");
  printf("1. Cleric\n");
  printf("2. Fighter\n");
  printf("3. Druid\n");
  printf("4. Mage\n\n");

  scanf("%20s", selection);

//Cleric
  if(strcmp(selection, one) == 0 ||
  strcmp(selection, cap_c) == 0 ||
  strcmp(selection, c) == 0 ||
  strcmp(selection, cler) == 0)
  {
Cleric:
    system("clear");
    printf("\033[0;33mCleric\033[0m\n\n");
    printf("Health Points: 100\n\n");
    printf("Smash - Deal 10 Damage\n");
    printf("Heal - Regain 10 Health Points\n");
    printf("Convert - Take 5 Damage, Deal 20 Damage\n\n");

    printf("1:Continue   2:Back\n\n");
    scanf("%20s", selection);
    if(strcmp(selection, one) == 0)
    {
      return 1;
    }
    else if(strcmp(selection, two) == 0)
    {
      goto Start;
    }
    else
    {
      goto Cleric;
    }
  }
//Fighter
  else if(strcmp(selection, two) == 0 ||
  strcmp(selection, cap_f) == 0 ||
  strcmp(selection, f) == 0 ||
  strcmp(selection, figh) == 0)
  {
Fighter:
    system("clear");
    printf("\033[1;36mFighter\033[0m\n\n");
    printf("Health Points: 120\n\n");
    printf("Slash - Deal 8-13 Damage\n");
    printf("Charge - Deal 5-17 Damage\n");
    printf("Shield Bash - Prevent 5 Damage, Deal 5 Damage\n\n");

    printf("1:Continue   2:Back\n\n");
    scanf("%20s", selection);
    if(strcmp(selection, one) == 0)
    {
      return 2;
    }
    else if(strcmp(selection, two) == 0)
    {
      goto Start;
    }
    else
    {
      goto Fighter;
    }  }
//Ranger
  else if(strcmp(selection, three) == 0 ||
  strcmp(selection, cap_d) == 0 ||
  strcmp(selection, d) == 0 ||
  strcmp(selection, drui) == 0)
  {
Druid:
    system("clear");
    printf("\033[1;32mDruid\033[0m\n\n");
    printf("Health Points: 80\n\n");
    printf("Strike - Deal 12 Damage\n");
    printf("Poison Dart - Deal 5 Damage/turn for 3 Turns\n");
    printf("Salve - Heal 4 Health Points/turn for 4 Turns\n\n");

    printf("1:Continue   2:Back\n\n");
    scanf("%20s", selection);
    if(strcmp(selection, one) == 0)
    {
      return 3;
    }
    else if(strcmp(selection, two) == 0)
    {
      goto Start;
    }
    else
    {
      goto Druid;
    }
  }
//Mage
  else if(strcmp(selection, four) == 0 ||
  strcmp(selection, cap_m) == 0 ||
  strcmp(selection, m) == 0 ||
  strcmp(selection, mage) == 0)
  {
Mage:
    system("clear");
    printf("\033[1;34mMage\033[0m\n\n");
    printf("Health Points: 80\n\n");
    printf("Blast - Deal 10 Damage\n");
    printf("Shock - Deal 20%% of enemy's current Health Points\n");
    printf("Magic Shield - Negate 4 Damage/turn for 3 Turns\n\n");

    printf("1:Continue   2:Back\n\n");
    scanf("%20s", selection);
    if(strcmp(selection, one) == 0)
    {
      return 4;
    }
    else if(strcmp(selection, two) == 0)
    {
      goto Start;
    }
    else
    {
      goto Mage;
    }
  }
  else
  {
    goto Start;
  }

}

int set_health(int char_class)
{
  int char_health;
  if(char_class == 1)
  {
    char_health = 100;
  }
  else if(char_class == 2)
  {
    char_health = 120;
  }
  else
  {
    char_health = 80;
  }

  return char_health;
}
