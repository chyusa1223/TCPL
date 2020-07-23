## Chpater14 Exercises

### 1

    a) #define Cube(x) ((x)*(x)*(x))

    b) #define R4(x) ((x)%4)

    c) #define A(x,y) (((x)*(y)<100)? 1:0)

    - 전부 숫자인 대상에 대해서만 위 매크로는 성립한다. 
    
### 2

    Ans : #define NELEMS(a) (sizeof(a)/sizeof(a[0]))

### 3

    a) 4
    b) 4
    c) (2*(x))

### 4

    a) 1/AVG(x,y)
    b) 5/AREA(2,5)

### 5

    a) D
    b) 3

### 6

    a) #define DISP(func,argu) printf("func(%g) = %g\n", argu, func(argu));
    b) #define DISP(func,x,y) printf("func(%g) = %g, func(%g) = %g\n", x, func(x), y, func(y));

### 7

    a) long long_max(long x, long y) { return x>y?x:y;}
    b) 공백이 있기 때문에 
    c) typedef사용
    
### 8

    - 못 풀었음.
    #deinfe STRINGIZE(x) #x
    #define EX(x) STRINGIZE(x)
    #define LINE_FILE ("Line" EX(__LINE__) "of file" EX(__FILE__)) 

### 9

    b) MEDIAN(x,y,z) ((x)+(y)+(z)/3)

### 10

    function pointer
    ans : recursive func

### 11

    #define ERROR(x,...) fprintf(stderr,s, __VA_ARGS__);
    
### 12

    a,e

### 13

    #include <stdio.h>
    void f(void);
    int main(void)
    {
	f();
	return 0;
    }
    void f(void)
    {
	printf("N is undefined\n");
    }
    
### 14
     
int main(void)
{
  int a[= 10], i, j, k, m;

  i=j;



  i = 10*j+1;
  i = (x,y) x-y(j,k);
  i = ((((j)*(j)))*(((j)*(j))));
  i = (((j)*(j))*(j));
  i = jk;
  puts("i" "j");


  i = SQR(j);

  i = (j);
  return 0;
}

### 15

#if ENGLISH
printf("Insert DIsk 1");
#elif FRENCH
printf("Inserez Le Disque 1");
#elif SPANISH
printf("Inserte El Disco 1");

### 16

#pragma ident "foo"
    
