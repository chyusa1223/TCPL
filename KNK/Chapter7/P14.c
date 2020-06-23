#include <stdio.h>
#include <math.h>

int main()
{
  double x,y=1;
  printf("Enter a positive number: ");
  scanf("%lf",&x);

  do{
    y = (y + (x/y))/2;
    printf("%lf %lf\n",y,(y+(x/y))/2);
  }
  while( fabs((y+x/y)/2-y) >= 0.00001);
  printf("Square root: %lf",y);
  return 0;
}
