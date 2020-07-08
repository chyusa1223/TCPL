## Program Organization ##

### Local variables ###

    - 지역변수는 Automatic storage duration을 가진다. 함수안에 포함된 지역변수는 함수가 호출 될 때 생성되고, 함수가 종료될 때 해제된다. 이러한 변수에 대해 Automatic Storage duration을 가진다고 얘기한다. 함수가 리턴될 때 지역변수는 자신의 값을 보존하지 않는다. 다시 함수가 호출 되었을때 지역변수는 이전의 자신의 값을 유지하지 않는다.

    - 변수의 scope는 해당 변수가 참조될 수 있는 프로그램 상의 공간을 의미한다. 지역 변수는 block scope를 가지고 있으며, 해당 변수의 선언부에서 블록이 종료되는 시점까지 참조가 가능하다. 지역 변수는 속해있는 함수 밖에서는 참조가 불가능하므로, 다른 함수에서 같은 이름의 지역 변수를 선언하여도 문제가 없다.

    - 지역 변수의 앞에 static을 붙여 선언할 경우 해당 변수는 static storage duration을 가진다. static storage duration을 가지는 변수는 프로그램 시작부터 종료까지 항상 참조가 가능하다. 따라서 함수내에 static변수가 선언된 경우에는 block scope를 가지므로 외부의 함수에서는 참조가 불가능하다. 그러나 함수가 return되어도 값이 사라지지 않으며, 다시 함수가 실행되었을때 이전의 값을 그대로 보존하고 있다.

    - Parameter또한 함수내 지역변수와 동일하나, 함수 호출시 초기화가 진행된다는 점만 다르다.

### External Variables ###

    - 함수의 바깥에 선언된 변수를 전역변수( external variable )이라 칭한다. 전역변수는 Static storage duration과 File Scope를 가진다.

    - static storage duration이란 프로그램의 실행과 동시에 생성되며 프로그램의 종료시 까지 유지되는 방식을 의미한다.

    - file scope란 해당 변수의 선언부에서 파일의 끝까지 어느 곳에서나 참조가 가능하다. 따라서 전역변수는 해당 선언부 아래에 있는 모든 함수에서 참조 및 변경이 가능하다.

    - 전역변수는 유용하나 몇 가지 단점을 가지고 있다.

    1. 프로그램 유지보수 시 전역변수의 타입을 변경하게 되면, 해당 변경이 어떠한 부작용을 낳게 될 지 예측하기 힘들다.

    2. 수많은 함수가 전역변수를 참조 & 변경할 수 있기에 해당 전역변수에 잘못된 값이 들어갔을 경우 추적이 매우 힘들어 진다.

    3. 재사용성이 급격히 하락한다.

    - 그 밖에도 하나의 전역변수를 여러 함수에서 다른 목적으로 사용하는 경우에는 위와 같은 단점과 추가적으로 추후 해당 프로그램을 보게되는 개발자를 혼란스럽게 할 수 있다.

### Block ###

    - Compound Statement는 다음과 같은 형태또한 가능하다. { declarations statements }

    - 블럭 내에 선언된 변수는 함수 내에 선언된 지역변수와 동일한 특성을 가진다. 

    - 블럭 내에 변수가 선언된 경우, 이름 충돌과 선언부가 복잡해지는 현상을 막을 수 있다.

### Scope ###

    - 만약 이미 선언된 변수가 블록이나 함수 내에서 새로 선언될 경우 해당 변수는 블록이나 함수 내에서는 새로운 선언이 이전 선언을 잠시 덮어쓰게 된다. 

### Program Organization ###

    - preprocessor, typedef, 변수는 모두 선언되기 이전에는 사용이 불가하다.
    
    - 프로그램 구성
    - #include directives
    - #define directives
    - Type definitions
    - Declarations of external variables
    - Prototypes for functions other than main
    - Definition of main
    - Definition of other functions