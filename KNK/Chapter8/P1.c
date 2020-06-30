#include <stdio.h>
#include <stdbool.h>
#define L 10
int main(void)
{
  int digit_seen[L] = {0};
  int digit;
  int repeat_exist = 0;
  long n;

  while(true) {

    printf("Enter a number : ");
    scanf("%ld",&n);

    if( n <= 0 ) break;
    else {
      for(int i=0;i<L;i++){
	digit_seen[i] = 0;
      }
      repeat_exist = 0;
    }
	
    while(n>0) {
      digit = n%10;
      digit_seen[digit]++;
      if( digit_seen[digit] > 1)
	repeat_exist = 1;
      n /= 10;
    } 

    if( repeat_exist == 1) {
      printf("Repeated digit : ");
      for(int i=0;i<L;i++){
	if(digit_seen[i] > 1){
	  printf("%d ",i);
	}
      }
      printf("\n");
    }
    else {
      printf("No Repeated digit\n");
    }
  } 
    return 0;
  }
