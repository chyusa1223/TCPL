# Chapter 16

## 16.1 Structure Variable

   - 구조체의 멤버는 배열과는 다르게 각기 다른 타입의 변수들이 원소로 포함될 수 있다. 

### 구조체 선언

	struct {
		int number;
		char name[NAME_LEN];
		int on_hand;
	} part1, part2;
	
   - 구조체의 각 멤버들은 메모리상에 선언되 순서 그대로 순차적으로 위치한다. 

   - 각 구조체는 각각마다 새로운 scope를 가지고 있기 때문에 구조체내에 선언된 멤버의 이름들은 프로그램내에 다른 이름과 중복되어도 충돌이 일어나지 않는다. 

### 구조체 초기화

	struct {
		int number;
		char name[NAME_LEN];
		int on_hand;
	} part1 = {526, "Disk drive", 10};

   - 구조체 초기화를 위해서는 구조체 내에 선언된 멤버와 동일한 순서로 기입되어 있어야 한다. 또한 구조체 초기화 시에 사용되는 표현들은 상수여야한다. 
   
   - 구조체 초기화 시에는 배열과 마찬가지로 멤버의 수보다 적게 초기화도 가능하며, 나머지 멤버들의 값은 0으로 초기화 된다. 
   
### Designated Initializers

   - 구조체에서도 designated initializer도 사용이 가능하다. 
   
   - {.number = 528, .name = "Disk drive", .on_hand = 10 }
   
   - designated initializer는 개발자가 오타등을 확인하기 용이하며, 구조체의 멤버와 같은 순서와 같은 순서로 배치될 필요가 없다는 장점이 있다. 
   
   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
   
### Operations on Structure

   - 구조체의 멤버들은 배열과 다르게 위치가 아닌 이름으로 접근이 가능하다. 
   
   - 예를 들어, part1.number와 같이 접근한다. 
   
   - 구조체의 멤버는 lvalue로서 대입연산자의 좌변에 위치할 수 있다. 구조체의 멤버에 접근할 때 사용하는 .은 실제로 C의 연산자이다. 해당 연산자의 우선순위는 ++, --와 같은 우선순위를 가진다. 
   
   - 구조체의 연산 중 유일하게 가능한 것은 대입이다. 구조체간 대입 시에는 구조체 내의 각 멤버가 대상 구조체의 복사되게 된다. 배열의 경우 이러한 대입이 불가하지만, 구조체 내의 배열이 선언된 경우에는 배열의 각 원소들또한 복사된다. 

   - 구조체 중에서도 대입이 가능한 경우는 두 구조체가 compatible할 때만이다. 두 구조체가 동시에 선언되었거나, 같은 structure tage, 같은 type name을 사용해서 선언된 경우에 compatible하다고 한다. 이를 제외하는 그 어떤 연산도 불가하다. !=, == 과 같은 연산자또한 사용이 불가하다.   
   
## 16.2 Structure Type

### 구조체 타입 선언이 필요한 이유

   - 구조체의 경우에 타입에 대한 선언이 없는 경우를 생각해 보자.
   
	struct {
		int number;
		char name[NAME_LEN];
		int on_hand;
	} part1;

	struct {
		int number;
		char name[NAME_LEN];
		int on_hand;
	} part2;

   - 이렇게 선언된 구조체의 경우에는 후에 프로그램을 수정할 경우에도 문제가 될 것이다. 그보다 더 큰 문제는 함수에 이를 인자로 넘겨줄려고 할 때 발생한다. 위에서 설명했듯이 동시에 선언된 구조체가 아니므로 같은 타입으로 여겨지지 않으므로 함수 호출이 불가하게 된다. 
   
   - 이러한 상황을 피하기 위해 구조체 변수를 선어하는 것이 아니라 타입자체를 선언할 필요가 있다.크게 두 가지 방식이 가능한다. 한 가지는 structure tag이고 다른 방법은 typedef이다.  
   
### 구조체 타입 선언

	struct part{
		int number;
		char name[NAME_LEN];
		int on_hand;
	};

   - 위에 선언된 방식이 structure tag를 활용한 방법이다. 이 경우에는 구조체 타입선언의 마지막에 만드시 semicolon이 위치해야한다.  
   
   - 위 처럼 타입을 선언한 후에는 아래와 같이 사용이 가능하다. 

   - struct part part1, part2 
 
   - part만으로는 타입명이 아니므로 struct 자체를 누락하는 것을 불가하다. 또한 structure tag의 경우에는 struct와 함께 쓰이지 않으면 인식되지 않으므로 충돌또한 일어나지 않는다. 

   - 또한 tag선언과 변수선언은 같이 사용될 수 있다. 

	struct part{
		int number;
		char name[NAME_LEN];
		int on_hand;
	} part1, part2;
	
   - 위에서 언급하였듯이, 같은 structure tag이용하여 선언한 구조체 변수는 compatible하다고 판단되므로 대입또한 가능하다. 
   
	typedef struct {
		int number;
		char name[NAME_LEN];
		int on_hand;
	} part;
	
   - 위의 structure tag와는 다르게 part라는 타입명이 마지막에 위침함을 주의할 것.  

   - part part1, part2와 같이 사용이 가능하다. 당연히 part1,2는 compatible하다. 
   
   - 구조체를 링크드리스트에 사용할 경우에는 structure tag를 사용하는 것이 의무적으로 필요하다. 
   
### structure as Arguments and Return Values

   - void print_part(struct part p) {
	   printf("Part number: %d\n', p.number);
	 }

   - 구조체를 함수에 인자로서 넘기거나, 함수의 결과 값으로 리턴될 경우에는 구조체의 전체 멤버에 대한 복사가 일어난다. 따라서 이는 프로그램내의 오버헤드가 된다. 

   - 이러한 오버헤드를 피하기 위해 대부분의 구조체의 포인터를 인자로서 넘기게 된다. 

   - 오버헤드를 제외하더라도, 구조체의 복사를 피하는 것은 이유가 있다. 예를 들어 <stdio.h>에서는 FILE 구조체가 존재하여 프로그램내에서 유일하게 사용된다. stdio.h에 모든 함수에서는 FILE 구조체포인터를 인자로 하고 결과값을 FILE에 대한 구조체 포인터를 리턴한다. 

## 16.1 Structure Variable

###
   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 

## 16.1 Structure Variable

###
   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
###

   - 만약에 designator가 없을 경우에는 이전에 designator가 명시된 멤버의 다음 멤버에 대입된다. 
