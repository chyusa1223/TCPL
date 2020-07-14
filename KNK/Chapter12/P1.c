#include <stdio.h>

int main(int argc, char *argv[])
{
  char str[100],ch,*p;
  int idx=0;
  
  while( (ch = getchar()) != '\n'){
    str[idx++] = ch;
  }

  for(p=&str[--idx];p>str;p--){
    printf("%c",*p);
  }
  
  return 0;
}
