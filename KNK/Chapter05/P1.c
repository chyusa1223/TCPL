#include <stdio.h>

int main()
{
  int num;
  printf("Enter a number: ");
  scanf("%d",&num);

  if( num <10) printf(" 1 digits");
  else if( num <100) printf(" 2 digits");
  if( num <1000) printf(" 3 digits");

  return 0;
}
