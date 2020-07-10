#include <stdio.h>

/* prototypes */
void pay_amount(int dollars, int*twenties, int*tens, int*fives, int*ones);

void pay_amount(int dollars, int*twenties, int*tens, int*fives, int*ones)
{
  *twenties = dollars / 20;
  dollars -= (*twenties * 20);
  printf("$20 bills: %d\n", *twenties);

  *tens = dollars / 10;
  dollars -= (*tens * 10);
  printf("$10 bills: %d\n", *tens);

  *fives = dollars / 5;
  dollars -= (*fives * 5);
  printf("$5 bills: %d\n", *fives);

  *ones = dollars / 1;
  dollars -= (*ones * 1);
  printf("$1 bills: %d\n", *ones);
}

int main(int argc, char *argv[])
{
  int dollars,tw,te,fi,on;

  int *twenties = &tw, *tens = &te, *fives = &fi, *ones = &on;

  printf("Enter a dollar amount: ");
  scanf("%d", &dollars);
  
  pay_amount(dollars, twenties, tens, fives, ones);

  return 0;
}
