#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DICE 6

int roll_dice(void);
bool play_game(void);

int main(int argc, char *argv[])
{
  srand((unsigned) time(NULL));
  play_game();
  return 0;
}

int roll_dice(void){

  int i,j;

  i = rand()%DICE +1;
  j = rand()%DICE +1;

  return i+j;
}

bool play_game(void){

  int sum=0, point ;

  for(int i=0;;i++){

    sum = roll_dice();
    printf("You rolled : %d\n",sum);

    if(i == 0) {
      printf("Your point is %d\n",sum);
      point = sum;

      if( sum == 7 || sum == 11){
	printf("Your Win!\n");
	return true;
      }

      if( sum == 2 || sum == 3 || sum == 12){
	printf("You lose!\n");
	return false;
      }
    }
    else {

      if( sum == point){
	printf("Your Win!\n");
	return true;
      }

    }

  }

}
