## Chapter 15 Exercises

### 1

    a) 규모가 큰 프로그램의 경우 가독성이 좋아지며, 컴파일 시간을 줄일 수 있음.
    b) 여러 소스 파일을 관리해야 되는 불편함.


### 2

    a,c,d

### 3

    컴파일러 별로 구현이 상이하나, 대부분의 경우 <>의 경우에는 시스템파일로 인식하고 /usr/include와 같은 디렉토리를 먼저 탐색하나, ""와 같은 경우에는 해당 디렉토리를 먼저 탐색한다. 따라서 해당 파일이 검색되지 않을 수 있다.

### 4

  a) Output if DEBUG is defined: 
	Value of i: 1
	Value of j: 2
	Value of k: 3
	Value of i+j: 3
	Value of 2*i+j-k: 1

  b) Output if DEBUG is not defined:

  c) 매크로가 정의 되어있지 않으므로 당연히 동작이 달라지게된다.

  d) 당연히 매크로가 정의되어 있어야 printf로 치환되므로 필요하다.

### 5

    CC=gcc
    CFLAGS=-Wall -Wextra -Wpedantic -std=c99

    demo: main.o f1.o f2.o
	    $(CC) -o demo main.o f1.o f2.o $(CFLAGS)

    main.o: main.c f1.h
	    $(CC) -c main.c $(CFLAGS)

    f1.o: f1.c f1.h f2.h
	    $(CC) -c f1.c $(CFLAGS)

    f2.o: f2.c f1.h f2.h
	    $(CC) -c f2.c $(CFLAGS)

### 6

   a) 모든 파일이 컴파일 되어야 한다.
   b) f1.c만 다시 컴파일 되어야한다.
   c) f1.h를 가지고 있는 3개 소스파일 전체가 다 다시 컴파일 되어야 한다.
   d) f2.h를 가지고 있는 f1.c, f2.c만 다시 컴파일 되면 된다. 
   


 

