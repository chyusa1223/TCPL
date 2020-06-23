#include <stdio.h>

int main()
{
     char ch;
     int total=0, count=0;
     double average=0;
     printf("Enter a sentence: ");
     getchar();
  
     while((ch = getchar()) != '.') {
	  if(ch == ' ') count++;
	  total++;
     }
     
     average = (total-count+1)/(double)(count+1);
     printf("total : %d\n",count);
     printf("count : %d\n",total);
     printf("Average : %.1lf\n",average);
     return 0;
}
