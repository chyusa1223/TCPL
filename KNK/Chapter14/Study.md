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
