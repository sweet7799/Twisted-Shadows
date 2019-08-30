#include <stdio.h>
#include <stdlib.h>


void status(int o_health, int p_health)
{
  //Prints out current health of player and opponent and move choices
  printf("\nOpponent's Health: %d\n", o_health);
  printf("Your Health: %d\n\n", p_health);

  printf("Select a move:\n");
  printf("1.Slash (13-18 damage)\n");
  printf("2.Charge (8-23 damage)\n");
  printf("3.Heal (Restore 10-15)\n\n");
}

void turn(int *o_ptr, int *p_ptr)
{
	char input[20];
	int damage;
	int healing;
	char one[] = "1";
	char slash[] = "Slash";
	char two[] = "2";
	char charge[] = "Charge";
	char three[] = "3";
	char heal[] = "Heal";
	char quit[] = "exit";	
	time_t t;
	srand((unsigned) time(&t));
	scanf("%20s", input);

	if(strcmp(input, one) == 0)
	{
	  damage = (rand() % (18 - 13 + 1)) + 13;
	  *o_ptr = *o_ptr - damage;
          system("clear");
	  printf("You dealt\033[1;31m %d\033[0m damage\n", damage);
	}
	else if(strcmp(input, slash) == 0)
	{
	  damage = (rand() % (18 - 13 + 1)) + 13;
	  *o_ptr = *o_ptr - damage;
          system("clear");
	  printf("You dealt\033[1;31m %d\033[0m damage\n", damage);
	}
	else if(strcmp(input, two) == 0)
	{
	  damage = (rand() % (18 - 13 + 1)) + 13;
	  *o_ptr = *o_ptr - damage;
          system("clear");
	  printf("You dealt\033[1;31m %d\033[0m damage\n", damage);
	}
	else if(strcmp(input, charge) == 0)
	{
	  damage = (rand() % (23 - 8 + 1)) + 8;
	  *o_ptr = *o_ptr - damage;
          system("clear");
	  printf("You dealt\033[1;31m %d\033[0m damage\n", damage);
	}
	else if(strcmp(input, three) == 0)
	{
	  healing = (rand() % (15 - 10 + 1)) + 10;
	  *p_ptr = *p_ptr + healing;
          system("clear");
	  printf("You healed\033[0;32m %d\033[0m health points\n", healing);
	}
	else if(strcmp(input, heal) == 0)
	{
	  healing = (rand() % (15 - 10 + 1)) + 10;
	  *p_ptr = *p_ptr + healing;
          system("clear");
	  printf("You healed\033[0;32m %d\033[0m health points\n", healing);
	}
	else if(strcmp(input, quit) == 0)
	{
		exit(0);
	} 
	else
	{
	  printf("Invalid Input\n");
	  turn(o_ptr, p_ptr);
	}
}
void oturn(int *o_ptr, int *p_ptr)
{
  int damage;
  int healing;
  time_t t;
  srand((unsigned) time(&t));
  int selection;

  selection = rand() % 6;
  if(*o_ptr < 35)
  {
    if(selection < 4)
    {
      healing = (rand() % (15 - 10 + 1)) + 10;
      *o_ptr = *o_ptr + healing;
      printf("Your opponent healed\033[0;32m %d\033[0m health points\n", healing);
    }
    else if(selection == 4)
    {
      damage = (rand() % (18 - 13 + 1)) + 13;
      *p_ptr = *p_ptr - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n", damage);
    }
    else
    {
      damage = (rand() % (23 - 8 + 1)) + 8;
      *p_ptr = *p_ptr - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n", damage);
    }
  }
  else
  {
    if(selection < 2)
    {
      healing = (rand() % (15 - 10 + 1)) + 10;
      *o_ptr = *o_ptr + healing;
      printf("Your opponent healed\033[0;32m %d\033[0m health points\n", healing);
    }
    else if(selection < 4)
    {
      damage = (rand() % (18 - 13 + 1)) + 13;
      *p_ptr = *p_ptr - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n", damage);
    }
    else
    {
      damage = (rand() % (23 - 8 + 1)) + 8;
      *p_ptr = *p_ptr - damage;
      printf("Your opponent dealt\033[1;31m %d\033[0m damage\n", damage);
    }
  }

}

int main(void)
{
  system("clear");
  int opponent = 100;
  int player = 100;
  while(opponent > 0 && player > 0)
  {
    status(opponent, player);
    turn(&opponent, &player);
    oturn(&opponent, &player);
  }

  if(opponent < 0)
  {
    printf("\nVictory!\n");
  }
  else
  {
    printf("\nDefeat\n");
  }

  return 0;
}
