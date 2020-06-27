## Array ##

### One-Dimensional Arrays ###

    - C doesn't require that subscript bounds be checked. if a subscript goes out of range, the program's behavior is undefined
    - The Expression a[i]=b[i++] accesses the value of i and also modifies i else-where in the expression, which-as we saw in Section 4.4 causes undefined behavior

    - sizeof()가 함수가 아닌 연산자인 이유
      첫 째로 sizeof가 연산자가 아닌 이유는 C Standard에서 위와 같이 정의했기 때문이다. 하지만 표준을 그렇게 정의한대는 이유가 있을 것이다. 개인적인 생각으로는 sizeof()의 결과가 constant expression이기 때문일 것이다. C에서는 포인터에 대한 덧셈, 뺄셈이 가능하며 이는 포인터 변수에 대한 데이터 타입이 이미 정해져 있기 때문에 가능하다. void * 또한 마찬가지로 해당 주소의 데이터 타입이 정해져 있지 않은 것이지 void * 타입또한 일정한 데이터 타입이다. 따라서 이는 컴파일 타입에 변환 될 수 있다. C99에서 단 하나의 예외가 바로 VLA에 해당하며 이는 sizeof()의 피연산자가 될 수 없다. 다른 이유로는 위처럼 컴파일 타임에 변환이 가능한 작업을 굳이 런타임에 함수호출에 필요한 오버헤드를 감수해가면서 까지 할 필요가 없기 때문일 것이다.

### Variable Length Array( VLA ) ###

    - C99에서 도입되었으며 변수를 통해 배열의 길이를 설정할 수 있다.
    - Static storage duration을 가지지 않으며, 초기화가 불가능하다.

### Q&A ###

    - index가 0에서 시작하는 이유?
      Having subscript begin at 0 simplifies the compiler a lot. Also, it can make array subscripting marginally faster.
    - int a[] = {4,5,1,[0]=3,6}의 결과는?
      index 0,1,2에 차례대로 4,5,1이 대입되다가 index 0에 3이 대입되고 designator에 의해 대입된 이후에 오는 값에 대해서는 designator에 의해 대입된 다음 index를 가리키므로 1에 6이 대입된다. 결과적으로 {3,6,1}이 대입될 것이다. 

