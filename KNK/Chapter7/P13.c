#include <stdio.h>

int main()
{
     char ch;
     double total=0, count=1, average=0;
     printf("Enter a sentence: ");
  
     while((ch = getchar()) != '\n') {
	  if(ch == ' ') count++;
	  else total++;
     }
     
     printf("Average : %.1lf\n",total/count);
     return 0;
}
