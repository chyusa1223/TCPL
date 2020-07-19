#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void reverse(char *msg);

int main(void) {
    
  char message[MAX_LEN];
  char c, *p = message;

  printf("Enter a message: ");

  while ((c = getchar()) != '\n' && p < message + MAX_LEN)
    *p++ = c;

  reverse(message);
  printf("Reversal is: %s",message);

  return 0;
}    

void reverse( char *msg)
{
  int i=0, n = strlen(msg)-1;
  printf("%d",n);
  char ch;
  for(;i<=n/2;i++){
    ch = msg[i];
    msg[i] = msg[n-i];
    msg[n-i] = ch;
  }
}
