#include <stdio.h>

int main(int argc, char *argv[])
{
  char str[100], ch, *p=str;
  
  while( (*p++ = getchar()) != '\n');
  
  for(p--;p>=str;p--) printf("%c",*p);
  
  return 0;
}
