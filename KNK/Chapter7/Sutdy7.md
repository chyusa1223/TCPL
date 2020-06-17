 ###

  - Short, long 등의 자료형은 int와 별도의 자료형이 아니라, short int 혹은 long int의 축약형에 불과했다.
  - int자료형은 Byte 수를 지정하지 않고 있으며 최소한의 범위만을 지정하고 있다. <limits.h>에서 확인가능. -> C89 표준
  - 위와 추가적으로 int가 다루는 범위가 short int보다 적을 수 없다 -> C89 표준
  - int -> long int -> unsigned long int : Decimal integer Constant의 경우
  - int -> unsigned int -> long int -> unsigned long int : Octal or Hex integer Constant의 경우
  - overflow  : Signed integer undefined // unsigned integer result is mod ( 2 pow n )


### float ###

  - IEEE Standard 754
  - floating constant는 기본적으로 double precision으로 저장된다.
  - 위에서 double로 변환된 경우에 필요할 때 float로 변환된다.


### Character ###

  - C는 character를 small integer로 취급한다.
  - C표준에 따르면 char형은 기본적으로 Unsigned, signed로 정해지지 않는다.
  - getchar,putchar는 scanf,printf에 비해 구현이 단순하고, macro로 구현되어 있어서 추가적으로 속도에 이점이 있다. 

##Type Conversion##

  - 계산식에서 피연산자 간의 타입이 일치하지 않을 경우
  - 대입 시 타입이 불일치 할 경우
  - func call시 대응되는 파라미터의 타입과 일치하지 않을 경우
  - ruturn type이 일치하지 않을 경우
  - signed, unsigned가 같이 쓰인 경우, signed Value는 UnSigned로 변환된다. 이러한 경우 -10<10이 같은 경우
    INT_MAX - 10 < 10으로 변환된다.

### sizeof ###

  - unary 연산자와 동일한 우선순위를 가진다.

### ETC ###

  - Floatin Constant가 double로 저장되는 이유는?
     * 애시당초에 K&R C 설계 시점에서 Float는 아주 큰 배열이나, double을 사용하기에 공간이 부족한 기계에서나 사용할 이유가
       있다고 생각했기 때문에 -> TCPL

  - printf에서 %f가 double과 float모두를 표현할 수 있는 이유는?
     * default argument promotion 때문 함수파트 참조.

  - I don't understand how the new-line character can be the ASCII line-feed character. When a user enters input
    and presses the Enter key, doesn't the program read this as a carriage-return character or a carriage return
    plus a line feed?

     * Unix환경에서는 개행을 위해 \n이 단독으로 사용되었고, C 표준에서는 파일로 부터 글을 읽어올때 줄의 끝을 나타내는 글자를
       single Line feed로 해석하여 주도록 되어있다.

  - macro로 Bool 타입 선언과 typedef 차이점?
     * macro로 int * 을 만들고 pointer to int p,q,r같이 변수를 선언하면 p만이 포인터형으로 선언되지만,
       typedef로 선언한 경우 이러한 일이 생기지 않는다.
     * 또한 macro는 전처리기로 소스코드 전체에 영향을 주지만, typedef의 경우 함수내에 선언된다면 함수 내에서만 적용된다.

