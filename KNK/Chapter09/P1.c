#include <stdio.h>
#define LEN 10

void print(int a[],int n){
  int i=0;
  for(i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}

void selection_sort(int A[],int n)
{
  if( n == 0) return;
  int tmp, N = n-1,i=0,largest = 0, largest_index;

  for(i=0;i<=N;i++) {
    if( largest < A[i]) {
      largest_index = i;
      largest = A[i];
    }
  }
  printf("%d %d\n",A[largest_index],A[N]);
  tmp = A[largest_index];
  A[largest_index] = A[N];
  A[N] = tmp;

  selection_sort(A,N);
}

int main(int argc, char *argv[])
{
  int a[LEN] = {1,3,5,7,9,6,2,4,8,10}; 
  print(a,LEN);
  selection_sort(a,LEN);
  print(a,LEN);
  return 0;
}



