#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define X (sizeof(str)/sizeof(str[0]))
#define Y (sizeof(str[0])/sizeof(str[0][0]))

int main(int argc, char *argv[])
{
  char s = 'A'; 
  char str[10][10] = {','};
  int di,i,j,x=0,y=0;
  
  for(i=0;i<X;i++){
    for(j=0;j<Y;j++){
      str[i][j] = ',';
    }
  }
    

  printf("x = %ld, y = %ld\n",X,Y);
  printf("sizeof(str[0]) = %ld, sizeof(str[0][0]) = %ld\n",sizeof(str[0]),sizeof(str[0][0]));
  srand((unsigned)time(NULL));

  while( s != 'Z'+1){
    di = rand()%4;

    if( di == 0) x = (x == 9 ? 9: x+1);
    else if( di == 1) x = (x-1<0 ? x=0: x-1);
    else if( di == 2) y = (y+1>10 ? y=10: y+1);
    else if( di == 3) y = (y-1<0 ? y=0: y-1);

    printf("x = %d, y = %d, s = %c, di = %d\n",x,y,s,di);
    str[x][y] = s;
    s++;
  }
    
  for(i=0;i<X;i++){
    for(j=0;j<Y;j++){
      printf("%c",str[i][j]);
    }
    printf("\n");
  }

  return 0;
}
