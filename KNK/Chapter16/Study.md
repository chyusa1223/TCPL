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

   - 이러한 오버헤드를 피하기 위해 대부분의 구조체의 포인터를 인자로서 넘기게 된다. 

   - C99의 Compound Literal또한 구조체의 전달에도 사용될 수 있다. 

   ex) print_part( (struct part) {528, "Disk drvie", 10}); 


## 16.3 Nested Arrays and Structures 

   - 구조체를 원소로 하는 배열이나 구조체 안에 다른 구조체를 포함하는 것 또한 가능하다.
   
   ex) struct student {
       struct person_name name;
       int id, age;
       char sex;
       } student1, student2;

## 16.4 Unions

   - Union은 구조체와 매우 유사하다. 하지만 컴파일러는 Union내의 가장 큰 멤버의 크기만큼만 공간을 할당한다. 

   - Union의 이러한 구조 때문에 멤버중 하나의 값을 대입하게 되면 나머지 값들은 전부 변하게 되고, 의미가 없어진다. 그 외의 다른 특징들은 구조체와 매우 유사하다. 

   - 다만, 초기화 진행시에 Union에서는 첫 멤버에게만 초기화할 값을 줄 수 있다. designated initializer또한 사용이 가능하다. 마찬가지로 한 멤버에게만 값을 명시할 수 있다. 
   
### Union을 사용하는 이유

    - Union을 공간을 절약하기 위해 아래와 같이 사용하기도 한다. 
    
    struct catalog_item {
       int stock_number;
       double price;
       int item_type;
       char title[TITLE_LEN+1];
       char author[AUTHOR_LEN+1];
       int num_pages;
       char design[DESIGN_LEN+1];
       int colors;
       int sizes;
     };
     
     struct catalog_item{
       int stock_number;
       double price;
       int item_type;
       union {
       	 struct {
	    char title[TITLE_LEN+1];
	    char author[AUTHOR_LEN+1];
	    int num_pages;
	 } book;
       	 struct {
       	    char design[DESIGN_LEN+1];
	 } mug;
       	 struct {
       	    char design[DESIGN_LEN+1];
	    int colors;
	    int sizes;
	 } item;

   - 한가지 재미있는 특징이 존재한다. 우선 일반적으로 Union의 한 멤버에 값을 저장하고 다른 멤버를 통해 값을 접근하는것은 정의되지 않은 행동이다. 

   - 그러나 Union내의 두 멤버가 구조체이고 첫번째 멤버가 같은 경우라면 ( 멤버의 순서가 같아야하고 구조체가 Compatible해야 한다) 이러한 경우에만, 다른 멤버를 통해서 접근하는 것이 가능하다. 

   - strcpy( c.item.mug.design, "Cats");
     printf("%s", c.item.shirt.design); == "Cats"
     
   - 이외에도 다른 데이터 타입을 가지는 자료구조를 만들 수 있다. 

   typedef union {
      int i;
      double d;
   } Number; 
   
   Number number_array[1000];
   
   - 그러나 Union의 사용에는 결정적인 문제점이 존재하는데, 이는 바로 마지막에 대입된 멤버가 어떤 것인지 알 수가 없다는 점이다. 

   - 따라서 이러한 경우를 위하여 아래와 같이 tag를 포함할 수 있다.
   
   typedef struct {
      int kind;
      union {
         int i;
	 double d;
      }u;
   }number; 

## 16.5 Enumerations

   - C에서는 몇가지 값만을 가질 수 있는 변수의 타입이 존재하며 이것이 enum이다. 

   ex) enum {CLUBS, DIAMONDS, HEARTS, SPADES } s1,s2
   
   - 구조제와 Union과는 다르게 enum의 경우에는 enum constant의 명칭은 다른 이름들과는 달라야 한다. 

   ex) enum suit {CLUBS, DIAMONDS, HEARTS, SPADES }; 
       enum suit s1,s2;

   ex) typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES } Suit;
       Suit s1,s2;

   - C에서는 enum 타입에 대해서 enumeration variable과 constant를 모두 integer로 취급한다. 
   
   - 개발자는 enum에 어떠한 값들이 대응될 지 지정할 수 있다.

   ex) enum suit {CLUBS=1, DIAMONDS=2, HEARTS, SPADES }; 
   
   - 만약 위처럼 값이 지정되지 않은 경우에는, 이전 Constant의 값에 1더한 값이 자동으로 지정된다. 
   

## Q&A

### 구조체의 크기가 멤버의 크기를 모두 더한 것 보다 큰 이유는?

   - 일부 컴퓨터에서는 특정 데이터 타입의 주소가 2,4,8등의 배수에만 지정이 가능하다. 따라서 이러한 사항을 만족하기 위해 compiler에는 구조체의 멤버사이에 빈 공간이 위치한다. 
   
### 구조체 내의 빈 공간이 구조체의 시작위치에도 올 수 있나요?

   - 이는 불가하다. C의 표준에 따르면 구조체의 빈 공간은 구조체 멤버 사이혹은 마지막 멤버 이후에만 존재할 수 있다.  

### C에서 구조체간의 == 비교연산이 불가한 이유는?

   - 왜냐하면 해당 연산이 C 언어의 철학에 어긋나기 때문이다. 첫 번째로는 구조체의 멤버를 1:1로 비교하는 연산자체가 너무나도 비효율적이기 때문이다. 구조체의 각 byte를 일대일로 비교하는것은 보다 효율적인 연산이 가능하나, 이는 위에서 설명한 빈 공간 때문에 불가하다. 빈 공간에는 임의의 데이터가 들어있으므로 각 멤버의 값은 같아도 다른 결과가 나올 수 있다. 이러한 문제는 컴파일러에서 구조체의 빈 공간에 0 또는 특정한 값을 대입합으로서 해결이 가능하나, 이는 구조체를 활용하는 프로그램에 성능저하를 가져 올 수 있다. 
   
### C에서 tag와 typedef 두 가지 방법을 지원하는 이유는?

   - C에서 원래는 typedef가 존재하지 않았고, typedef가 생긴 이후로는 tag방식을 제거하기에는 이미 너무 많은 시간이 흘렀다. 이를 제외하고도 tag방식은 구조체의 멤버가 같은 타입을 가리킬때 필요하다. 

### part라는 구조체의 선언을 다른 두 파일에 포함시켰을 때, 각각의 파일에 포함된 두 변수가 서로 같은 타입이 될 지?

   - 결론부터 말하자면 그렇지 않다. 그러나 C표준에서는 두 변수가 같은 타입이라고 얘기하고 있다. 이는 타입자체가 compatible한 것과 완전히 같은 것의 차이가 있다. C89에서는 다른 파일에 선언된 구조체의 경우 멤버가 같은 이름을 가지고 같은 순서로 배치되어 있을 경우 Compatible하다고 판단한다. 그러나 C99에서는 위의 조건을 모두 포함하고 같은 tag를 가지거나 둘 다 태그가 존재하지 않아야 compatible하다. 

   