#include <stdio.h>

int main()
{

  int hour,min;
  printf("Enter a 24hour time: ");
  scanf("%d:%d",&hour,&min);

  if(hour == 12 && min!=0) hour -=12;
  else if( hour >=12) hour-=12;
  
  printf("%d %d",hour,min);
  return 0;
}
