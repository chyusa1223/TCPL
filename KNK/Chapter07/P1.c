#include <stdio.h>

/*

  When Type is integer 

  395936   2146493440
  395937   2147285313
  395938  -2146890108
  395939  -2146098231

  When Type is short 

  180        32400
  181        32761
  182       -32412
  183       -32047
  
  3037000498                     9223372024852248004
  3037000499                     9223372030926249001
  3037000500                    -9223372036709301616
  3037000501                    -9223372030635300615

 
*/

int main()
{
  long int i,n,mul;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in tables : ");
  scanf("%ld",&n);

  for(i=n-10;i<=n;i++)
    {
	printf("%40ld%40ld\n", i, i*i);
    }
  return 0;
}
