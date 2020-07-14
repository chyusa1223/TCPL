// Quck sort 

#include <stdio.h>

#define L 9
void quicksort(int *a, int *left, int *right);

int main(int argc, char *argv[])
{
  int a[L] = {-1,-1,2,7,4,6,9,-1,-1};
  
  quicksort(a,&a[2],&a[L-3]);
  for(int i=2;i<L-2;i++) printf("%d ",*(a+i));
  return 0;
}


void quicksort(int *a, int *left, int *right)
{

  int temp,*pivot = left + (right-left)/2; 
  int *tmp=&temp , *i=left, *j=right;
  printf("pivot : %d, i : %d, j: %d\n",*pivot,*i,*j);

  while(i<=j){
    while( *i < *pivot) {
      printf("i: %d\n",*i);
      i++;
    }
    while( *j > *pivot){ 
      printf("j: %d\n",*i);
      j--;
    }

    printf("i: %d, j: %d\n",*i,*j);
    printf("true : %d\n",i<=j);

    if( i<=j){
      *tmp = *i;
      *i = *j;
      *j = *tmp;
      i++;
      j--;
      printf("*i : %d, *j : %d\n",*i,*j);
    }
  }
  if( left < j) quicksort(a,left,j);
  if( i<right) quicksort(a,i,right);
}
