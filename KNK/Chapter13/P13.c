#include <stdio.h>

#define MAX_VALUE 80

void encrypt( char *message, int shift);

int main(void) {

  char c, sentence[MAX_VALUE] = {0};

  int i, n, length;

  printf("Enter message to be encrypted: ");
  for (i = 0, length = 0; (c = getchar()) != '\n' && i < MAX_VALUE; i++) {
    length++;
    sentence[i] = c;
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &n);

  encrypt(sentence,n);
  printf("Encrypted message: %s",sentence);

  return 0;
}

void encrypt( char* msg, int n)
{
  for (; *msg; msg++) {
    if (*msg >= 'A' && *msg <= 'Z')
      *msg = ((*msg - 'A') + n) % 26 + 'A';
    else if (*msg >= 'a' && *msg <= 'z')
      *msg = ((*msg - 'a') + n) % 26 + 'a';
  }
}
  
