
#include <stdio.h>
#include <ctype.h>

#define LEN 100

int main(int argc, char *argv[])
{
  char message[LEN];
  char c,*p = message, *q= message;

  while((*p++ = toupper(getchar())) != '\n' & p<message+LEN);

  for(p--;q<p;q++,p--){
    if(*p!=*q) {
      printf("Not a palindrome\n");
      return 0;
    }
  }

  printf("Palindrome\n");  
  return 0;
}
