#include <stdio.h>

int main(int argc, char *argv[])
{
  int w=0, index=0;
  char str[100][100], ch, end = -1; 
  while((ch = getchar()) != '\n'){
    if( ch == ' '){
      str[w][index] = '\0';
      index=0;
      w++;
    }
    else if( ch == '?' || ch == '.' || ch == '!') {
      end = ch;
    }
    else { 
      str[w][index] = ch;
      index++;
    }
  }
    
  for(;w>=0;w--){
    printf("%s ",str[w]);
  }
  if( end != -1) printf("%c",end);
  return 0;
}

