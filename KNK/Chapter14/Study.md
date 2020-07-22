## The Preprocessor ##

### How the Preprocessor Works 

   - #include, #define과 같은 directive들은 preprocessor에 의해 처리된다. 이러한 전처리기는 컴파일 이전에 동작하여 프로그램을 수정하며, 다른 언어와는 다른 C언어의 특징 중 하나이다. 

   - 전처리기는 강력한 툴이지만, 모든 것이 그렇듯 적절히 사용하는 것이 중요하다. 
   
   - The behavior of the preprocessor is controlled by preprocessing directives. Commands that begin with a # character. 
   
   - #define은 macro를 설정하며, 전처리기는 이름과 값을 저장한다. 이후 해당 메크로가 코드 내에서 쓰이면, 매크로를 값으로 치환하여 준다. 
   
   - #include는 전처리기에게 특정파일을 열고 해당 내용을 파일에 일부로 포함시키게 한다. 예를 들어 #include <stdio.h>는 stdio.h라는 파일을 열고, 해당 내용을 프로그램에 가져온다. 
   
   - C program -> Preprocessor -> Modified C program -> Compiler -> Object code 
   
   - 전처리기는 #include와 같은 directive를 포함한 C 프로그램을 입력으로 받고, 처리과정에서 해당 directive를 알맞게 처리하고, 해당 directive들을 제거한다. 전처리기의 결과는 수정된 C 프로그램이다. 이러한 전처리기의 결과는 컴파일러로 전달된다. 
   
   - [Output of Preprocessor](ttps://gcc.gnu.org/onlinedocs/gcc-4.8.5/cpp/Preprocessor-Output.html)

   - 전처리기는 directive를 실행하는것 외에도 다른 작업을 수행한다. 주석을 ' '로 교체하거나 불필요한 공백을 제거하기도 한다. 
   
   - C언어 초기에 전처리기는 컴파일러와 별도로 구성된 프로그램이었지만, 최근에는 컴파일러의 일부로서 동작하는 경우가 많아졌다. 예를 들어 stdio.h를 포함할 경우 해당 헤더의 전체를 불필요하게 복사하는 경우도 있기 때문이다. 
   
   - 전처리기는 C언어에 대한 지식이 거의 없기 때문에 directive의 잘못된 사용은 에러를 불러일으킬 수 있으나, 코드상으로는 정상적으로 보일 경우가 많다. 이러한 경우에는 전처리기의 결과를 따로 살펴보는것이 보탬이 된다. 
   
### Preprocessing Directives

   - 전처리기는 크게 3가지로 분류할 수 있다. 첫 번째는 Macro definition, 두 번째는 File inclusion, 세 번째는 Conditional compilation이다. 
   
   - 이외에도 #error, #line, #pragma등 특수한 directive가 존재하나, 사용빈도는 낮은 편이다. 
   
   - Directive들에 적용되는 규칙들
   
   - 1. Directive는 항상 #으로 시작한다. #앞은 공백으로 시작할 수 있으며 항상 라인의 맨 앞에 위치할 필요는 없다. 
   
   - 2. Directive 안 token 사이에는 제한없이 공백문자들이 올 수 있다. 
   
   - 3. Directive는 항상 첫 번째 개행문자에 의해 종료된다. 예외적으로 \를 사용하여 연장할 수 있다. 
   
   ex) #define DISK_CAPACITY ( SIDES * \
		                       TRACKS_PER_SIDE * \
							   SECTORS_PER_TRACK * \
							   BYTES_PER_SECTOR)


   - 4. Directive는 프로그램 내의 어느 위치에나 선언할 수 있다. 
   
   - 5. Directive와 주석은 같은 줄 내에 위치할 수 있다. 
   
### Macro Definitions

   - Simple macro 혹은 object-like macro라고 불리는 매크로는 아래와 같은 형식을 가지고 있다. 

   - #define identifier replacement-list -> replacement-list is any sequence of preprocessing tokens, which are similar to the tokens discussed in Section 2.8
   
   - replacement-list는 identifiers, keywords, numeric constants, character constants, string literals, operators, punctuation등을 포함한다. 해당 매크로의 정의를 만났을때 전처리기는 교체 리스트를 만들어두고 identifier가 나타날 때마다 replacement-list로 바꾼다. 
   
   - Simple macros are primarily used for defining what Kernighan and Ritchie call "manifest constants." Using macros, we can give names to numeric, character, and string values.
   
   - simple macro를 잘 사용하면 프로그램 가독성을 높여주고, 수정이 쉽게 만든다. 추가적으로 오타나 불일치성을 줄여준다. 
   
   - syntax의 변화를 주는 것도 가능하다. 예를 들어 파스칼의 begin, end의 문법에 익숙한 사람이면 #define BEGIN { #define END }과 같이 정의해서 사용하는 것 또한 가능하다. 그 외에도 #define LOOP for(;;)와 같이 편리함을 위해 사용하는 것도 가능하다. 
   
   - type이름을 바꾸어 사용하는 것도 가능하다. 
   
   - 조건부 컴파일에서도 매크로는 중요한 역할을 수행한다. 예를 들어, #define DEBUG와 같이 선언된 줄은 debugging mode에서만 컴파일 될 것이라는 점을 알려준다. 그리고 위의 예시에서 작성하였듯이 replacement list를 비워놓는 것 또한 가능하다. 

### Parameterized Macros

   - Parameterized macro의 형식은 다음과 같다.

   - #define identifier( x1, x2, ... , xn) replacement-list

   - 해당 메크로명과 괄호 사이에 공백이 존재해서는 안 된다. 만약 공백이 있을 경우 전처리기는 simple macro처럼 이를 해석하게 된다.

   ex) #define MAX(x,y) ((x)>(y)?(x):(y))

   - 파라미터가 존재하는 매크로의 경우 위와 같은 형태의 마주치게 되면, 이를 replacement-list와 이를 치환한다.

   - parameterized macro의 경우에는 빈 파라미터와 함께 선언될 수 있다. 다음 예를 살펴보자.

   - #define getchar() getc(stdin)

   - 위 처럼 빈 파라미터를 가지는 매크로를 선언 할 수 있으나 활용도가 높지는 않다. 위 getchar()의 경우에는 실제 stdio.h에 구현되어 있는 getchar()와 동일한 형태이다.


   - Advantages and disadvantages of parameterized macro

   1. 프로그램의 속도가 약간 향상 될 수 있다. 함수를 호출할 때는 현재 실행하고 있던 코드에 관한 정보, 파라미터 복사등의 오버헤드가 존재한다. 그러나 매크로는 그러한 오버헤드가 존재하지 않는다. ( 참고 : C99에서는 위에서 언급한 오버헤드를 제거한 inline-function이 존재한다.)

   2. 매크로는 일반적으로 사용이 가능하다. 함수는 해당 파라미터들의 타입을 명시하여야 하나, 매크로는 그러한 제한이 존재하지 않는다.

   3. 컴파일 해야할 코드가 늘어날 수 있다. 특히 매크로가 중첩되어 있을 경우 더욱 코드가 길어질 수 있다.

   4. 함수의 경우 해당 파라미터가 올바른 타입인지 컴파일러에 의해 체크되어 다를 경우 에러메세지로 이를 알려주나, 전처리기는 이러한 동작이 불가능하다.

   5. 함수포인터는 가능하나, 포인터 매크로는 존재하지 않는다.

   6. 매크로에 따라 자신의 인수가 여러 번 실행 될 수 있다. ex) MAX( i++, j); -> ((i++)>(j)?(i++):(j))

   - 위와 같은 에러들은 상당히 찾기가 어려우며, 따라서 파라미터를 가지는 매크로를 사용할 때는 주의가 필요하다.

   - 그러나 파라미터를 가지는 매크로의 경우에는 함수와 같은 형태를 만들기에 용이하다.

### #, ## Operator

   - #,## operator는 모두 전처리기에 의해 인식된다.
   
   - # operator는 매크로의 인자를 문자열로 바꾸어주는 역할을 하며, 파라미터를 가지는 매크로의 replacement-list에만 위치할 수 있다.

   - ## operator는 두 토큰을 하나로 붙여주는 역할을 한다.

   ex) #define MK_ID(n) i##n -> MK_ID(1) => i1 

   - ## operator는 자주 사용되지는 않지만, 아래와 같은 경우에 유용하게 사용될 수 있다.

   ex) #define GENERIC_MAX(type) \
       type type##_max(type x, type y) \
       {
	  return x > y? x: y;
       }

   - 위와 같이 선언된 함수는 특정 타입만을 지원하는 함수와는 다르게 모든 타입에 대해서 사용될 수 있다.


 ### 일반적인 매크로의 성질

   - 매크로의 replacement-list에는 다른 메크로의 정의가 포함될 수 있다.

   ex) #define PI 3.14 #define TWO_PI (2*PI)

   - 위와 같이 선언된 경우, TWO_PI->2*PI->2*3.14 와 같이 모든 매크로 이름이 없어질 때 까지 replacement-list를 반복해서 살펴보고 치환한다.

   - 전처리기는 매크로 이름이 identifier, character constant, string literal에 포함된 경우에는 치환하지 않는다.

   - 매크로의 정의는 선언된 부분에서 파일의 끝까지 유효하다.

   - 매크로는 이전과 똑같은 정의가 아닌 이상 여러차례 반복하여 선언될 수 없다.

   - 매크로는 #undef를 이용해서 정의되었던 것을 해제할 수 있다. 만약 이전에 해당하는 정의가 없을 경우 무시된다.

### Parentheses in Macro Definitions

   1. 매크로의 replacement-list에 operator가 포함되어 있을 경우에는 반드시 괄호를 이용하여 이를 닫아준다.

   2. 만약 매크로가 파라미터를 가질 경우, 이후 파라미터가 나올때마다 괄호를 이용하여 닫아준다.

   3. 매크로를 사용하면서 괄호의 부족은 정말 찾기 어려운 에러를 생성할 수 있다.

### Creating Longer Macros

   ex) #define ECHO(s) (gets(s), puts(s))

   - 위처럼 ,를 활용해서 매크로를 확장할 수 있지만 모든 매크로에 적용할 수 있는 사항은 아니다.

   - 만약 statement를 작성해야할 경우에는 do loop 안에 이를 포함하는 방법이 존재한다.

   ex) #define ECHO(s) \
       	       do {    \
	         gets(s);\
		 puts(s);\
	       } while(0)

   - 위와 같이 선언된 매크로는 ECHO(s);와 같이 자연스럽게 사용이 가능하다. 

### Predefined Macros

   - C언어는 사전에 정의된 다양한 매크로 들을 가지고 있다.
   
   - __LINE__ => Line number of file being compiled

   - __FILE__ => Name of file being compiled

   - __DATE__ => Date of compilation ( in the form "Mmm dd yyyy")

   - __TIME__ => TIme of compilation ( in the form "hh:mm:ss")

   - __STDC__ => 1 if the compiler conforms to the C standard ( C89, C99)


   < C99 >

   - __STDC__HOSTED__ => 1 if this is a hosted implementation; 0 if it is freestanding
   
   - __STDC__VERSION__ => Version of C standard supported 

   - __STDC__IEC__559__ => 1 if IEC 60559 floating-point arithmetic is supported 

   - __STDC__IEC__559_COMPLEX =>  1 if IEC 60559 complex arithmetic is supported 

   - __STDC__ISO__10646 => yyyymmL if wchar_t values match the ISO 10646 standard of the specified year and month 

   - Empty Macro Arguments
   - C99에서는 매크로를 사용할 때 빈 파라미터를 넣는 것을 허용하고 있다. ##로 선언된 매크로에서 파라미터가 비어있을 경우에는 placemaker로 대체되면 이는 값이 있는 파라미터와 결합하면 사라진다. 

   - Macros with a Variable Number of Arguments
   - C99에서 매크로는 무제한의 파라미터를 가질 수 있다. 이러한 특성은 가변 가능한 숫자를 받는 함수에 인자를 전달할 때 유용하게 사용될 수 있다. ex) printf, scanf

   - ex) #define TEST( condition, ...)

   - 위 ...을 ellipsis라 칭한다. ellipsis는 항상 파라미터 선언의 마지막에 위치하여야 한다. 후에 ellipsis에 대응되는 파라미터를 사용하기 위해서는 __VA_ARGS__를 사용한다. 

   - ellipsis에 대응되는 파라미터 조차도 생략될 수 있다. 

   - __func__ Identifier

   - 위 __func__는 전처리기와는 관계가 없다. 모든 함수는 __func__에 접근할 권한을 가지고 있다. __func__는 함수 안에 static cosnt char __func__ = "function_name"와 같이 선언된 변수처럼 동작한다. 특정 함수가 어디서 실행되었거나, 종료하였는지, 호출한 함수가 어디인지 추적할 때 유용하다. 


### Conditional Compilation

   - #if, #endif

   ex) #if DEBUG
       printf("Value of i: %d\n", i);
       printf("Value of j: %d\n", j);
       #endif 

   - 위와 같이 작성되어있는 경우에 전처리기가 처리하는 과정에서 #if는 DEBUG의 값을 확인한다. 만약 값이 0이 아니라면 #if, #endif구문 만을 없애서 printf구문은 그대로 남겨두게 된다. 만약 DEBUG의 값이 0이라면 #if부터 #endif까지의 모든 내용을 제거한다.  

   - 만약, 아예 선언되지 않은 매크로라면, 전처리기는 이를 0으로 취급한다. 

   - #defined
   - 선언되어 있을경우 1을 리턴하고, 아닌 경우 0을 리턴한다.

   - #ifdef == defined(identitifier) , #ifndef == #if !defined(identitifier)

   - #if expr1
     line1

     #elif expr2
     line2

     #else
     line3
     #endif

   - #elif, #else는 위와 같이 사용하며, #ifdef, #ifndef또한 동일하게 사용이 가능하다.
   
   - 조건부 컴파일의 장점

   1. 다른 운영체제 혹은 기계에 적용될 때 이식성 확보에 용이하다.  

   2. 다른 컴파일러에 의해 컴파일되는 프로그램을 작성할 때도 유용하게 사용할 수 있다. 

   3. 선언되어 있지 않은 매크로를 선언 할 수 있다.

   4. 주석을 포함하는 코드를 일시적으로 사용하지 않을 수 있다. 

### Miscellaneous Directives

   - #error message

   - 위와 같이 적혀있을 경우 message를 포함한 에러메세지를 출력한다. #error은 조건부 컴파일과 함께 쓰여서 정상적인 실행 중에 발생해서는 안 되는 상황인 경우를 나타내는데 사용된다. 

   - #line n, #line n "file"

   - #line은 프로그램의 라인의 숫자가 매겨지는 방식을 바꿔준다. 2번째 형태와 같이 파일이 명시된 경우에는 "file"의 n번째 줄에서 부터 시작된 것으로 인식한다.

   - #line의 효과는 __LINE__, __FILE__을 바꾼다는 점이다. 사실 #line은 일반적으로 프로그래머에게는 잘 사용되지 않으나, c code를 결과값으로 하는 프로그램에서 주로 사용된다. 예를 들어 yacc와 같은 프로그램에서 사용된다. 사용자가 프로그램의 코드를 입력값으로 하여 yacc를 실행하면, yacc는 c program을 생성한다. 그 결과가 y.tab.c라고 하면 이 결과를 프로그래머가 컴파일 하게 된다. 결과로서, #line이 컴파일러로 하여금 코드가 원래 프로그래머가 작성한 파일에서 온것 처럼 만들어준다. 따라서 결과적으로, 디버깅이 용이해지며, 에러가 발생한 라인또한 프로그래머가 작성한 파일과 연관되어서 보여지게 된다. 

   - 참조 
   - [yacc & lex](http://blog.naver.com/neraijel/110038010784)

   - #Pragma

   - pragma directive는 컴파일러에게 특정한 해동을 시킬 수 있는 방법을 제시한다.

   - #pragma token 

   - 위와 같이 사용하며 단순한 역할과 형태부터 복잡하고 정교한 것 까지 다양하게 사용할 수 있다. 그러나 C89에는 #pragma로 공통적으로 정의된 표준은 존재하지 않으며, 이는 컴파일러마다 지원하는 것이 다르다. 만약 인식할 수 없는 명령의 경우에는 무시한다. 

   - 참고 : C99에서는 FP_CONTRACT, CX_LIMITED_RANGE, FENV_ACCESS의 표준에 의한 pragma를 지원한다.

   - 참고 : the _Pragma Operator 

   - C99에서는 _Pragma 연산자가 추가되었다. 이는 #pragma directive에 사용된다. _pragma( string-literal)의 형태를 마주치게 되면, 전처리기는 문자열 상수를 분해( destringizes)하고 쌍따옴표를 제거한다. 예를 보자.

   ex) #pragma omp parallel for
       #define OMP_PARALLEL_FOR #pragma omp parallel for // ERROR!!
       #define OMP_PARALLEL_FOR _pragma("omp parallel for")

   - 전처리기 지시자는 다른 지시자를 생성할 수 없기에 위의 두 번째 줄을 에러가 발생한다. 그러나 _pragma는 operator이므로 위와 같은 사용이 가능하게 된다.


### Q&A

   - 어떤것을 매크로로 정의해야 하는가?
   - 모든 숫자로 된 상수, 문자열 상수인데 2번 이상 사용되며 추후에 바뀔 가능성이 있는 것.

   - #이 ",\이 포함된 경우 어떻게 stringize하는가?
   - ex) #define STRINGIZE(x) #x // STRINGIZE("foo") -> "\"foo\"\"

   - #define CONCAT(x,y) x##y // CONCAT(a,CONCAT(b,c)) 정상적으로 동작하지 않는다.
   - #,##이 사용된 경우에 매크로는 확장되지 않는다. 즉 CONCAT(a,CONCAT(b,c))는 aCONCAT(b,c)로만 확장된다. 이를 위해서는 다소 번거롭더라도 #define CONCAT2(x,y) CONCAT(x,y)와 같은 정의가 필요하다. CONCAT2(a,CONCAT2(b,c)에는 ##이 포함되어 있지 않으므로 abc로 정상적으로 확장된다. 위와 같은 동작은 #에서도 동일하다.

   - 만약 전처리가 이미 선언된 매크로를 다시 스캔하는 경우에 확인하면 이는 무한 루프로 이어지는가?
   - 아주 오래된 전처리기의 경우에는 그러한 가능성이 존재한다. 그러나 최근에 사용가능한 전처리기에서는 대부분이 그러한 방식으로 동작하지 않는다. C표준에 따르면 원래 선언된 매크로가 다시 재스캔중에 나오는 이는 더이상 확장되지 않는다. 

   - 위와 같은 점을 이용할 수도 있다. 아래의 예를 살펴보자.
   ex) #undef sqrt
       #define sqrt(x) ((x)>=0?sqrt(x):0)

   - 위와 같이 선언되 매크로의 경우 모든 sqrt함수를 위와 같은 형태로 바꾸나 한 번 치환된 이후에는 위의 원칙에 의해 다시 치환되지 않는다. 표준 라이브러리는 함수명과 매크로가 같은 이름을 갖는 것을 허용하고 있다. 따라서 sqrt의 정의를 해제한 이유는 만약 라이브러리에 이미 sqrt가 정의되어 있는 경우를 상정한 방어적인 프로그래밍이다.

   - freestanding implementation과 hosted implementation의 의미는?
   - hosted implementation의 경우에는 OS위에서 돌아가는 일반적인 대부분의 프로그램에 해당된다. freestanding program의 경우에는 운영체제가 없거나, 있더라도 매우 최소한의 역할 만을 하는 운영체제 위에서 실행되는 프로그램에 해당한다. 예를 들어 운영체제의 커널, 임베디드 시스템을 작성하는데 사용된다. 당연히 전통적인 의미의 input/output이 필요하지 않으므로 stdio.h가 포함될 필요가 없다. 

   - preprocessor가 상수표현을 계산할 수 있는 이유는?
   - 전처리기는 우리가 생각하는 것 보다 복잡하과 정교하게 구성되어 있으며, C언어에 대해서도 알고 있다. 물론 컴파일러와 같은 방식으로 동작하지는 않는다. 실제적으로, 전처리기의 상수 표현은 상수, 상수를 표현한 매크로, defined operator의 활용이다.

   - #ifdef, #ifndef가 있는 이유 (defined 가 있음에도)
   - #ifdef, #ifndef는 1970년대 부터 C언어에 포함되어 있었다. 이후 1980년대에 defined operator가 추가되었다. 그러면, defined는 왜 추가된 것일까? ex) #if defined(FOO) && defined(BAR) && !defined(BAZ)와 같이 여러개의 매크로를 동시에 확인할 수 있고 유연성이 향상된다.

   - #if 0 // lines // #endif 사이 line에 완성되지 못한 코드가 있으나 에러가 발생한다. 그 이유는?
   - 이는 line이 완전히 무시되지 않기 때문이다. 주석은 전처리기의 지시자가 실행되기 전에 처리되며 소스코드는 전처기에 의해 토큰으로 나뉜다. 위 과정에서 종료되지 않은 주석 및 코드는 에러메세지를 발생하게 할 수 있다. 마찬가지로 마무리되지 않은 따옴표또한 마찬가지이다. 이러한 코드는 undefined behavior를 발생시킬 수 있다. 
