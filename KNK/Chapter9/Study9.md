## Function ##

### Defining and Calling fuction ###

   - Functions may not return arrays, but there are no other restrictions on the return type
    
   - If the return type is omitted in C89, the functions is presumed to return a value type of int. but it is illegal in C99

   - Variable declared in the body of a function belong exclusively to tha function.

   - In C89, variable declarations must come first, before all statements in the body of a function. In C99, variable declarations and statements can be mixed.

   - To make it clear tha we're deliberately discarding the return value of a function, C allows us to put (void) before the call;

### Defining and Calling fuction ###

   - 만약 선언되지 않은 함수를 컴파일러가 마주하게 된다고 생각해보자. 일단 C언어에서는 마주친 함수의 리턴 타입이 무엇인지, 파라미터의 개수와 타입을 모른다. 따라서 return type이 int라고 가정한다. 그리고 우리는 이를 implicit declarations이라 칭한다. 이후 컴파일러는 우리가 올바른 인수를 넘겼는지 알 수 없기 때문에 default argument promotion을 실시한다. 그러나 이후 실제 함수 정의를 마주쳤을 때는 컴파일러가 제멋대로 설정한 함수와는 다르기 때문에 에러메시지가 나온다.

   - 따라서 위와 같은 문제를 해결하기 위해서 C언어에서는 function declaration을 제공한다.

   - C99에서도 이는 마찬가지로 선언, 정의가 없는 함수를 마주치면 에러가 발생한다.

   - return-type function-name (parameters);

   - 위와 같은 형식을 Function prototype이라고 부르기도 한다. 이는 K&R style C에서의 빈 괄호로 선언된 형식과 구분하기 위해서이다.

### Arguments ###

   - Parameters appear in function definitions, Arguments are expressions that appear in function calls.
   - In C, arguments are passed by value. When function is called, each argument is evaluated and its value assigned to the cooresponding parameter.
    

### Arguments Conversion ###

   - C allows function calls in which the types of the arguments don't match the type of the parameters.
   - The compiler has encounterd a prototype prior to the call. The Value of each arguments is implicitly converted to the type of the corresponding parameter as if by assignment.

   - The compiler has not encountered a prototype prior to the call. The compiler performs the default argument promotions. 1) float -> double, 2) integral promotion


   - 아래 코드에서 Before cast에는 1이 출력되나 아래 After cast에는 9가 정상적으로 출력된다. 


```
#include <stdio.h>

int main(int argc, char *argv[])
{
  
  double x = 3.0;
  printf("Before cast : %d\n",square(x));
  printf("After cast : %d\n",square((int)x));
  
  return 0;
}

int square(int n)
{
  printf("func : %d\n",n);
  return n*n;
}
``` 
  - Before에서는 x가 type int라고 가정하고, double의 값을 읽어오므로 제대로 된 값을 읽히 못하였다.
  - 그러나 Square에서는 Double타입을 Int로 정상적으로 cast후에 읽어서 9라는 값이 나올 수 있었다.

### VLA ###

   - C99에서는 Variable-Length-Array를 제공한다. VLA allows the length of an array specified using a non-constant expression.

   - Using a Variable-length array parameter, we can explicitly state tha a's length is n

   - int Sum_ARrray(int n, int a[n]

   - The value of the first parameter (n) specifies the length of the second parameter (a). Note tha the order of the parameters has been switched. Order is important when variable-length array parameter is used.

   - C99 allows the user of the ketword static in the declaration of array parameter.

   ex) int sum_array(int a[static 3], int n)

   - Using static in this way has no effect on the behavior of the program. The presence of static is merely a "hint" tha may allow a C compiler to generate faster instructions for accessing the array. ( If the compiler knows that an array will from memory when the function is called, before the elements are actually needed by statements within the function.

### Compound Literals ###

   - In C99, we can avoid this annoyance by using a compound literal: an unnamed array that's created "on the fly" by simply specifying which elements it contains.

   ex) total = sum_array((int[]){3,0,1,2,4},5);

   - review => l-value represents an object stored in computer memory, not a constant or the result of a computation. Variables are lvalues.


### return ###

   - If the type of the expression in a return statement doesn't match the function's return type, the expression will be implicitly converted to the return type.

   - If a non-void function reaches the end of its body - tha is, it fails to execute a return statement - the behavior of the program is undefined if it attempts to use the value returned by the function. Some compilers will issue a warning such as "control reaches end of non-void function" if they detect the possibillity of a non-void function "falling off" the end of its body.

### Program Termination ###

   - The value returned by main is a status code tha - in some operating system - can be tested when the program terminates. main should return 0 if the program terminates normally.

### The Exit Function ###

   - Executing a return statement in main is one way to terminate a program. Another is calling the exit function, which belongs to <stdlib.h>. The argument passed to exit has the same meaning as main's return value;

### Q&A ###

   - Some programming languages allow precedures and functions to be nested within each other. Does C allow function definitions to be nested?

   > No. C does not premit the definition of one function to appear in the body of another. Among other thigs.

   - In the function call f(a,b), how does the compiller know whether the comma is punctuaion or whether it's an operator?

   > It turns out tha the arguments in a function call can't be arbitrary expressions. Instead, they must be "assignment expressions" which can't contain commas used as operators unless they're enclosed in parentheses. In other words. in the call F(a,b) the comma is punctuation; in the call F((a,b)) it's an oeprator.


   - Why can the first dimension in an array parameter be left unspecified, but not the other dimensions?
   > 첫번째로, C에서 배열이 함수로 전달될 때 함수는 배열의 첫번째 원소의 pointer를 전달한다.
     일차원 배열을 전달하는 경우를 생각해보자. a[i]를 계산하기 위해서는 주어진 시작 주소에서 배열의 원소의 사이즈만큼을 더해주면 a[i]의 주소로 접근이 가능하다. 따라서 우리가 길이 정보를 알 필요는 없다.
     이번에는 이차원 배열을 생각해보자. a[i][j]를 계산하기 위해 우리는 시작주소에서 a의 열의 크기 * i를 곱한 만큼 더해준 후, a배열의 원소 크기의 * j를 한 값을 더해서 a[i][j]에 접근하게 될 것이다. 따라서 a[i][j]를 계산하기위해서는 i의 값을 알고 있어야만 하고 이것이 함수로 이차원 혹은 그 이상의 배열을 전달할시 제일 마지막을 제외한 나머지 숫자들을 기입해주어야 하는 이유이다.