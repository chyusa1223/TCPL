#include <stdio.h>
#define L 40

int main(int argc, char *argv[])
{
  int i,fib_numbers[L] = {0,1};
  
  for(i=2;i<L;i++) {
    fib_numbers[i] = fib_numbers[i-1]+fib_numbers[i-2];
  }
  
  for(i=0;i<L;i++) {
    printf("%d,",fib_numbers[i]);
  }

  return 0;
}
