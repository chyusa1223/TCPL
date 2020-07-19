#include <stdio.h>
#include <string.h>

#define MAX_VALUE 31
#define MAX_LENGTH 21 

int main(void) {

  int i = 0, j;
  char c, terminating_char, words[MAX_VALUE][MAX_LENGTH] = {0};

  printf("Enter a sentence: ");
  while( scanf("%s",words[i])){
    if(getchar() == '\n') break;
    i++;
  }
  terminating_char = words[i][strlen(words[i])-1]; 
  words[i][strlen(words[i])-1] = '\0'; 

  for(;i>=0;i--) printf("%s ",words[i]);
  printf("\b%c",terminating_char);
  return 0;
}
