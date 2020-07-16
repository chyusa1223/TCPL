#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i = argc-1;
  while(i) printf("%s ",argv[i--]);
  return 0;
}
