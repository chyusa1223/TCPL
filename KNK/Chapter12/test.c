#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int main(int argc, char *argv[])
{
  
  int temperature[2][4] = { {24,26,27,28},
			    {28,22,21,32}};
  int x,y;
  int *p,*px = &x, *py = &y;

  bool search(const int a[], int n,int key,int*x)
  {
    for(int i=0;i<n;i++)
      if( *(a+i) == key) {
	*x= i;
	return true;
      }
    return false;
  }

  for(p=temperature[0];p<temperature[2];p+=4){
    if(search(p,4,32,px) == true) printf("X : %d -> TRUE!\n",*px);
  }

       /*
	 double ident[N][N];
	 double *id;
	 int index=0;
	  
	 for(id = &ident[0][0];id<=&ident[N-1][N-1];id++){
	 if(index == N || id == &ident[0][0] ) {
	 *id = 1;
	 index=0;
	 }
	 else {
	 *id = 0;
	 index++;
	 }
	 }

	 for(int i=0;i<N;i++){
	 for(int j=0;j<N;j++){
	 printf("%lf ",ident[i][j]);
	 }
	 printf("\n");
	 }
	 int a[10][10], *p, i=0;
	 printf(" Address : %p, sizeof(a[0]) : %ld\n",&p,sizeof(a[0])); 
	 printf(" Address : %p, sizeof(a[0][0]) : %ld\n",&p,sizeof(a[0][0])); 
	 for(p = a[i]; p<=a[i]+9; p++) {
	 *p=0;
	 printf(" Address : %p, sizeof(p) : %ld\n",p,sizeof(p)); 
	 }
       */
       return 0;
}
