#include <stdio.h>

#define MAX_VALUE 100

  int main(void) {

    int i = 0, j;
    char c, terminating_char, words[MAX_VALUE] = {0};
    char *p = words, *q, *tmp;

    printf("Enter a sentence: ");
    for (;(*p = getchar()) != '\n' && p-words < MAX_VALUE; p++) {
      if (*p == '.' || *p == '!' || *p == '?') {
	terminating_char = *p--;
	break;
      }
    }

    printf("Reversal of sentence: ");
    while(p >= words) {
      while( *--p != ' ' && p != words);
      q = p == words ? words : p+1;
      while( *q != ' '&& *q != '\0') putchar(*q++);
      if( p>= words)
	putchar(' ');
    }
    printf("%c",terminating_char);
    return 0;
  }

