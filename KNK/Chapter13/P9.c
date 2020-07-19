#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);

int main(void) {

  char str[1000];
  int vowels = 0;
    
  printf("Enter a sentence: ");

  scanf("%s",str);
  printf("Your sentence contains %d vowels.\n", compute_vowel_count(str));
  return 0;
}

int compute_vowel_count(const char * sentence)
{
  int cnt = 0;
  char c;
  while( *sentence) {
    c = toupper(*sentence);
    if( c == 'A' || c == 'E' ||
	c == 'I' || c == 'O' || c == 'U'){
      cnt++;
    }
    sentence++;
  }
  return cnt;
}
