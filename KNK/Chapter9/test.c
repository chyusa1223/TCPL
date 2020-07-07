#include <stdio.h>

double median( double x, double y, double z)
{
  return x>y?(x<z?x:(z>y?z:y)):(y<z?y:(z>x?z:x));
}

void pb(int n)
{
  if(n!=0) {
    pb(n/2);
    putchar('0'+n%2);
  }
}

int main(int argc, char *argv[])
{

  int N;
  while(1) {
    scanf(" %d",&N); 
    if( N == 0) return 0;
    pb(N);
    printf("\n");
  }
}
