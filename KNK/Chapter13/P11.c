#include <stdio.h>
#include <string.h>

#define LENGTH 1000

int main(void) {

  /* Comment Test*/
  char str[LENGTH];
  int words = 0, length = 0;
  printf("Enter a sentence: ");

  while( scanf("%s",str)){
    words++;
    length += strlen(str);
    printf("%s\n",str);
    if( getchar() == ' '){
      printf("2");
    }
    if( getchar() == '\n'){
      printf("3");
    }
  }

  printf("Average word length: %.1f\n", length/(double)words);
  return 0;
}

