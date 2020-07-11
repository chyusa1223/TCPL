## Pointers ##

### Pointer Variables ###

    - 컴퓨터 내에서 주소값은 정수값으로 관리되지만, 포인터 변수는 해당 참조 지점이 어떻게 해석되고 변환될지에 관한 추가적인 정보가 필요하기에 별도의 포인터형의 변수에 주소값을 저장한다. 

    - Declare Pointer ex) int *p;

    - 위의 포인터 변수는 int형의 object를 가리키고 있다. object는 특정 변수에 속하지 않으며 메모리 상의 특정한 공간을 점유하고 있다. 

### The Address and Indirection Operators ###

    - Indirection Operators ex) *p = 12;

    - 포인터 변수 p가 가리키는 곳의 값을 참조 혹은 변경하기 위해서는 *(Indirection Operators)를 사용한다.

    - int i; int *p = &i; 일때 *p는 i의 alias이며, *p의 값을 바꾸는 것은 당연하게 i의 값또한 같이 변경된다. 

    - Never apply the indirection operator to an uninitialized pointer variable. If a pointer variable p hasn't been initialized, attempting to use the value of p in any way causes undefined behavior. 

### Pointer as Arguments ###

    - C에서 함수에 인자를 전달할 때 값을 복사해서 전달하기 때문에 인자로 전달된 변수의 값을 직접 수정하는 것은 불가능하다. 그러나 포인터를 전달하게 되면 해당 주소에 접근하여 값을 수정하므로 가능하게 된다. 

    - 만약 포인터로 전달되어야할 파라미터에 주소값이 아닌 일반 변수의 값을 전달하게 될 경우 예상치 못한 결과가 발생할 수 있다.
    
    - ex) void f(const int *p)
    - 위처럼 함수의 프로토타입이 작성된 경우 p가 가리키는 int형의 변수를 함수 내에서는 변경할 수 없음을 의미한다.
    
    - ex) void f(int * const p)
    - 위처럼 함수의 프로토타입이 작성된 경우 p 포인터 변수자체를 함수 내에서는 변경할 수 없음을 의미한다.

### Pointer as Reutn Value ###

    - 함수의 인자뿐만 아니라 함수의 return 값으로도 포인터 변수를 return할 수 있다. 하지만 함수 내 지역변수의 포인터를 return하지 않도록 주의할 것. 

### Q&A ###

    - Is a pointer always the same as an address?

    - Usually, but not always. Consider a computer whose main memory is divided into words rather than bytes. A word might contain 36bits, 60bits, or some other numver of bits. Let's assume 36-bit words.

    - When memory is divided into words, each word has an address. An integer usually occupies one word, so a pointer to an integer can just be an address. However, a word can store more than one character. For example, a 36-bit word might store six 6-bit characters or fout 9-bit characters.