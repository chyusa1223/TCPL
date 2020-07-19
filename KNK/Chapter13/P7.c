
#include <stdio.h>

int main(void) {

  int n;
  char * num_str[] = { "ten", "eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen",
		       "seventeen", "eighteen", "nineteen"};
  char * num_10[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

  char * num_1[] = {"\n","-one\n","-two\n","-three\n","-four\n", "-five\n", "-six\n", "-seven\n" 
		    "-eight\n","-nine\n"};

  printf("Enter a two-digit number: ");
  scanf("%d", &n);

  if (n / 10 == 1) {
    printf("You entered the number %s\n",num_str[n%10]);
  }
  else if( n/10 <= 9 && n/10 > 1 ) {
    printf("You entered the number %s",num_10[n/10-2]);
    printf("%s",num_1[n%10]);
  }
  else printf("Your number is out of range 10-99\n");
  return 0;
}
