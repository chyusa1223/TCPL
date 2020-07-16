#include <stdio.h>
#include <string.h>

void compare(char *s,char *smallest, char* largest);

int main()
{
  char str[21] = "tem";
  char smallest[21] = "";
  char largest[21] = "";
  while( strlen(str) != 4){
    printf("Enter word: ");
    scanf("%s",str);
    compare(str,smallest,largest);
  }
  printf("Smallest word: %s.\n",smallest);
  printf("Largest word: %s.\n",largest);
  return 0;
}

void compare(char *s, char* smallest, char* largest)
{
  if( strlen(smallest) == 0 || strcmp(s,smallest) < 0) strcpy(smallest,s);
  if( strlen(largest) == 0 || strcmp(s,largest) > 0) strcpy(largest,s);
}
