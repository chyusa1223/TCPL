#include <stdio.h>
#include <math.h>

#define DISP(func,argu) printf("func(%g) = %g\n", argu, func(argu))
#define GENERIC_MAX(type)			\
        type type##_max(type x, type y)		\
	{					\
	  return x>y?x : y;			\
	}					\

#deinfe STRINGIZE(x) #x
#define EX(x) STRINGIZE(x)
#define LINE_FILE ("Line" EX(__LINE__) "of file" EX(__FILE__)) 

int main()
{
  //double a = 3.0;
  //DISP(sqrt,a);
  //printf("sqrt(%lf) = %lf\n",a,sqrt(a));
  const char *str = LINE_FILE;
  printf("%s",str);
  return 0;
}
