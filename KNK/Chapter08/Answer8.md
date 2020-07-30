## Excercises ##

### E1 ###

    - 왜냐하면 만약 코드를 작성한 후 배열의 데이터타입을 변경하게 된다면 해당 sizeof문을 찾아서 모두 변경해주어야 하기 때문이다. 예를들어 sizeof(a)/sizeof(int)로 선언해서 배열의 크기를 구한 이후, 배열을 long int 타입으로 변경했다고 가정해보자. 이러한 경우 위 처럼 적인 코드에 대하여 모두 sizeof(a)/sizeof(long)으로 변경해 주어야 할 것이다.

### E2 ###

    - ex) A[0-'0'], A[3-'0']와 같이 사용할 수 있다. 

### E3 ###

    - #include <stdbool.h> // bool weekend[7] = {[0]=true,[6]=true}; -> C99

    - #include <stdbool.h> // bool weekend[7] = {true,[6]=true}; -> C99 ( 정답 참조 )

    - typedef int bool, bool weekend[7] = {1,0,0,0,0,0,1}; -> C89


