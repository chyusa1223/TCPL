#include <stdio.h>

int main(int argc, char *argv[])
{
  
  int a[10][10], *p, i=0;
  printf(" Address : %p, sizeof(a[0]) : %ld\n",&p,sizeof(a[0])); 
  printf(" Address : %p, sizeof(a[0][0]) : %ld\n",&p,sizeof(a[0][0])); 
  for(p = a[i]; p<=a[i]+9; p++) {
    *p=0;
    printf(" Address : %p, sizeof(p) : %ld\n",p,sizeof(p)); 
  }
  return 0;
}
