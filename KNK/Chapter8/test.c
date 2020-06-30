#include <stdio.h>

int main()
{
  char a[5][10] = { "one", "two", "three", "four", "five" };
  char **str = (char **)a;
  char *s0 = str[0];
  char *s1 = str[1];
  char *s2 = str[2];
  char *s3 = str[3];
  int i,j;

  printf("&a    = %p\n", &a);
  printf("&a[0] = %p\n", &a[0]);
  printf("a[0]  = %p\n", a[0]);
  printf("&a[1] = %p\n", &a[1]);
  printf("a[1]  = %p\n", a[1]);

  printf("str   = %p\n", str);
  printf("str1   = %p\n", str+1);
  printf("str2   = %p\n", str+2);
  printf("str3   = %p\n", str+3);
  printf("s0    = %p\n", s0);
  printf("s1    = %p\n", s1);
  printf("s2    = %p\n", s2);
  printf("s3    = %p\n", s3);
  printf("sizeof(char *)    = %lu\n", sizeof(char*));
  printf("sizeof(char *)    = %lu\n", sizeof(char));

  for(i=0;i<5;i++){
    for(j=0;j<10;j++){
      printf("%#08x,",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
