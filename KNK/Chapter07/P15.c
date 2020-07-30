#include <stdio.h>
  
typedef double fa;

/*
  short int : n is 7
  int : n is 16
  long int : n is 20

  float : n is 34
  double : n is 170
  
  float랑 long int랑 별로 차이 안 날거라고 생각했는데 생각보다 
  많이 차이남.
*/

int main()
{
  fa i,N,f;
  
  while(1) {
    f=1;
    printf("Enter a positive integer : ");
    scanf(" %lf",&N);
    for (i = N; i > 0; i--) {
      f*=i;
    }
    printf("Factorial of %lf : %lf\n",N,f);
  }
  return 0;

}

