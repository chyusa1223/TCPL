## Excercises ##

### 1 ###

   1) 63
   2) 119
   3) 2748

### 2 ###

   a) 010E2 - float 
   b) 32.1E+5 - float
   c) 0790 - integer  -> illegal because of 9
   d) 100_000 - not legal
   e) 3.978e-2 - float

### 3 ###

    a) short unsigned int
    b) short float -> illegal short can put infront of integer
    c) long double
    d) unsigned long
    

### 4 ###

   a) i+=c;
   b) c= c*2-1;
   c) putchar(c)
   d) printf(c) -> illegal printf need format string

### 5 ###

   a) 'A'
   b) ob1000001 -> illegal 
   c) 0101
   d) 0x41

### 6 ###

   a) Days in a month -> signed char
   b) Days in a year -> short
   c) Minutes in a day -> short
   d) Seconds in a day -> int  -> i can't understand answer

### 7 ###

    Pass

### 8 ###

    Pass

### 9 ###

    int

### 10 ###

    unsigned int 

### 11 ###

    double 

### 12 ###

    d = i + f;

    1. 일단 i+f가 수행될 때, integer가 float로 변한다. ( Arithmetic Conversions )
    2. 이후 계산결과가 d에 대입될 때 double로 변환이 다시 일어난다. ( Conversion during assignment )

### 13 ###

    a) -3, int
    b) 7, long
    c) 6.5, float
    d) 3.75, double
    e) -1.0, double 
    f)  6, int
    
### 14 ###

    i think yes but if float variable is bigger than int_max it is impossible.

### 15 ###

    #include <stdio.h>

    int main()
    {
	typedef int8_t int8;
	typedef int16_t int8;
	typedef int32_t int8;

	printf("Size of int8: %zu byte (%zu bits).\n", sizeof(int8), sizoef(int8)*8);
	printf("Size of int8: %zu byte (%zu bits).\n", sizeof(int8), sizoef(int8)*8);
	printf("Size of int8: %zu byte (%zu bits).\n", sizeof(int8), sizoef(int8)*8);
	//%zu는 size_t 출력 시 사용.
	return 0;
    }
    
