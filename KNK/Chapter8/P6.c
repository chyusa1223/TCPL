#include <stdio.h>

int strlen(const char* str)
{
  int i=0;
  for(;*(str+i)!='\0';i++);
  return i;
}

int main(int argc, char *argv[])
{
  char str[100];
  int i=0;
  while((str[i] = getchar()) != '\n'){
    i++;
  }
  str[i] = '\0';

  for(i=0;i<strlen(str);i++) {
    if(*(str+i) == 'A' || *(str+i) == 'a')
      printf("4");
    else if(*(str+i) == 'B'|| *(str+i) == 'a')
      printf("8");
    else if(*(str+i) == 'E'|| *(str+i) == 'e')
      printf("3");
    else if(*(str+i) == 'I'|| *(str+i) == 'i')
      printf("1");
    else if(*(str+i) == 'O'|| *(str+i) == 'o')
      printf("0");
    else if(*(str+i) == 'S'|| *(str+i) == 's')
      printf("5");
    else
      if( *(str+i) > 'a' && *(str+i) < 'z')
	printf("%c",*(str+i)+'A'-'a');
      else 
	printf("%c",*(str+i));
  }
  printf("!!!!!!!!!!");
  return 0;
}
