#include <stdio.h>

int power(int x, int n) {
  if( n == 1) return x;

  if (n%2 == 0) return power(x,n/2)*power(x,n/2);
  else return power(x,1)*power(x,n-1);
}

int main(int argc, char *argv[])
{
  int N,M;
  while(1){
    printf("x is ");
    scanf("%d",&N);
    printf("n is ");
    scanf("%d",&M);
    printf("%d\n",power(N,M));
  }
  return 0;
}
