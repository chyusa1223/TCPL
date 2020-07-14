#include <stdio.h>
#include <ctype.h>

#define LEN 100

int main(int argc, char *argv[])
{
  char message[LEN];
  char c,*p = message, *q= message;

  while((c = toupper(getchar())) != '\n' & p<message+LEN){
    if(isalpha(c)) *p++ = c;
  }
  p--;
  for(;q<p;q++,p--){
    if(*p!=*q) {
      printf("Not a palindrome\n");
      return 0;
    }
  }

  printf("Palindrome\n");  
  return 0;
}
