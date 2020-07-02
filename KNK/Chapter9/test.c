#include <stdio.h>

int main(int argc, char *argv[])
{
  
  double x = 3.0;
  printf("Before cast : %d\n",square(x));
  printf("After cast : %d\n",square((int)x));
  
  return 0;
}

int square(int n)
{
  printf("func : %d\n",n);
  return n*n;
}
