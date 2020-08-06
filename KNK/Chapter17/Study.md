# Chapter 17 Advanced Uses of Pointers

## 17.1 Dynamic Storage Allocation

   - C의 자료구조는 대부분 컴파일 시점에 결정된다. 고정된 크기의 자료구조는 여러 불편한 점이 존재한다. 만약 자료구조의 크기를 바꿀려고 하면, 프로그램을 수정하여 재컴파일 해야하기 때문이다. 따라서 이러한 점을 해결하기 위해 C에서는 dynamic storage allocation을 지원한다.

   - 동적할당 자체는 모든 자료형에 가능하지만 대부분 string. array, structure를 할당하는데 사용한다. 

### Memory Allocation Functions

   - 동적 할당을 하기 위해 우리는 3가지의 함수를 사용할 수 있다.

   - malloc : 메모리 블럭을 할당하나, 초기화 하지 않는다.

   - calloc : 메모리 블럭을 할당하고 초기화 한다.

   - realloc : 이미 할당된 메모리 블럭을 확장하거나 축소시킨다. 

   - 위 함수 중에서는 malloc이 가장 많이 사용된다. 위 함수들은 메모리 블럭을 할당할 뿐 어떠한 자료구조를 저장할지 모르기때문에 함수의 결과로서 void *형을 리턴한다. 


### Null Pointers

   - 만약 메모리 할당을 요청했으나 실패한 경우에는 null pointer를 리턴한다.  

   - null pointer는 어떤 것도 가리키지 않는 포인터를 의미한다. 다른 모든 유의미한 포인터 값들과 비교하기 위해 사용된다.

   - 따라서, 우리는 메모리 블록을 할당한 뒤 해당 포인터가 null인지 확인해야한다. 

   - null pointer는 NULL로 표현되며, <locale.h>, <stddef.h>, <stdio.h>, <stdlib.h>, <string.h> and <time.h>에 존재한다. 

   - C pointer는 숫자와 같이 참,거짓을 판단한다. 모든 null이 아닌 포인터는 참이다. 


## 17.2 Dynamically Allocated Strings


### Using malloc to Allocate Memory for a String

   - void *malloc(size_t size);

   - malloc 함수의 prototype은 위와같다. malloc을 호출하게 되면 size byte만큼을 할당하고 해당 포인터를 리턴한다. size_t의 타입이 unsigned int임에 유의할 것. 아주 큰 메모리 블록을 할당하지 않는 이상 일반적인 int과 동일하게 생각해도 무방하다.  

   - 만약 n길이의 string을 위한 공간을 할당하고 싶다면 아래와 같이 사용하면 된다. 

   - char* p = malloc(n+1);

   - malloc의 결과는 void*로 리턴되지만 자동적으로 char*형으로 변환될 것이다. 우리는 반대로 어떤 포인터형이든 void * 에 대입하는 것도 가능하다. 

   - 프로그래머에 따라서는 malloc의 리턴값에 명시적으로 cast하는 것을 선호하기도 한다. 


### Using Dynamic Storage Allocation in String Functions

   - 동적할당을 사용하면 새로운 string의 포인터를 리턴하는 함수를 만들 수 있다. 해당 string은 함수 호출이전에는 존재하지 않았다.

    char *concat( const char *s1, const char *s2)
    {
	char *result;

	result = malloc(strlen(s1) +strlen(s2) +1);
	if(result == NULL){
		  printf("Error: malloc failed in concat\n");
		  exit(EXIT_FAILURE);
	}
	strcpy( result, s1);
	strcat( result, s2);
	return result;
     }

     - 위와 같이 작성된 함수를 사용할 때는 주의가 필요하다. 만약 함수가 리턴한 string이 더 이상 필요하지 않은 경우에는 free함수를 호출하여 해당 메모리를 해제해 주어야 한다. 그렇지 않을 경우 메모리 부족이 발생할 것이다.


## 17.3 Dynamically Allocated Arrays 


### Using malloc to Allocate Storage for an Array

    - string과는 다르게 배열의 경우 각 원소의 크기를 계산하기 위해 sizeof 연산자를 사용한다. 

    - int * a = malloc( n* sizeof(int));

    - 이렇듯, 배열에 얼마만큼의 공간이 필요한지 계산하기 위해서는 항상 sizeof를 이용해야 한다. 만약 잘못된 값을 입력하여 할당할 경우에는 crash를 일으키거나 잘못 동작할 수 있다.

    - 동적할당을 통해 리턴받은 포인터는 배열의 이름처럼 사용하는 것이 가능하다. 


### The calloc Function

    - malloc함수가 많이 사용되는 편이나, calloc함수를 사용하는 것이 더 좋은 경우또한 존재한다.

    - void *calloc(size_t nmemb, size_t size);

    - calloc는 size byte만큼의 공간을 할당하고 모든 공간을 0으로 초기화한다. 만약 충분한 공간이 존재하지 않을 경우 null pointer를 리턴한다. 

    - int * a = calloc(n, sizeof(int));

    - 위처럼 사용하며, 할당된 공간은 모두 0으로 초기화 되어있다. 이는 배열 뿐만 아니라 구조체 형식에도 해당되며 calloc으로 할당된 구조체들의 멤버는 모두 0으로 초기화된다.

### The realloc Function

    - 만약 우리가 배열을 위해서 메모리를 할당한 경우에, 우리는 나중에 크기가 크거나 작다는 것을 발견할 수 있다.

    - 이런 때에 사용해야하는 함수가 realloc이다. 함수 prototype은 아래와 같다. 

    - void *realloc(void *ptr, size_t size);

    - realloc을 호출할때 전달해야하는 ptr은 반드시 이전에 malloc, calloc, realloc으로 할다했던 메모리 블록이어야 한다. 그렇지 않을 경우, undefined behavior를 일으킨다. 

    - realloc도 마찬가지로 배열뿐만 아니라 다른 자료구조에도 사용이 가능하나 대부분 배열에 사용한다.

    - C언어에는 realloc을 사용하기 위한 몇 가지 규칙이 존재한다. 

    - 메모리블럭을 추가로 확장할 경우에 추가된 블록을 초기화 하지 않는다.

    - 만약 추가로 할당이 불가한 상황이면 null Pointer를 리턴하고 기존의 메모리는 바뀌지 않는다.

    - realloc에 null pointer를 대입하여 사용할 경우 malloc처럼 동작한다. 

    - 만약 size를 0으로 호출하면 free처럼 동작한다. 

    - realloc의 경우 데이터 자체를 최대한 옮기지 않으면서 메모리 공간을 확장하거나 축소하려고 한다. 만약 데이터자체를 옮기지 않고 불가한 경우에는 데이터 공간 자체를 옮기고 이전 데이터를 복사하게 된다. 

    
## 17.4 Deallocating Storage

   - malloc등 동적할당에 사용되는 함수들은 heap이라고 불리는 메모리 공간을 사용한다. 동적할당 함수를 너무 자주 사용하거나, 너무 큰 공간을 할당하게 되면 heap 공간의 부족으로 null pointer를 리턴하게 된다.

   p = malloc(...);
   q = malloc(...);
   p = q; 

   - 우리는 분명이 메모리 공간을 할당했으나 처음 p에 할당되었던 공간을 참조할 수 있는 방법은 없다. 이렇게 할당되었지만 참조가 불가능한 공간을 garbage라고 칭한다. 

   - 또한 위처럼 garbage를 남기는 프로그램을 memory leak을 일으킨다고 표현한다. c#과 같은 언어들은 garbage collecter가 존재하여 이러한 garbage들을 자동적으로 처리하나 C에는 그러한 기능이 존재하지 않는다. 

   - 각각의 c프로그램은 free함수를 통해서 자신의 garbage를 확실히 처리해야 한다. 

### free fucntion

   - void free(void *ptr)

   - free함수의 prototype은 위와 같다. free함수를 사용하는 방법은 간단하다.

   - 우리가 더이상 필요하지 않은 포인터를 대입하여 호출하면 된다. 

   - free를 통해 해제된 메모리블록은 다시 malloc과 같은 동적할당 함수에 의해 사용될 수 있다. 

   - free에 인자로 들어가는 포인터는 반드시 malloc과 같은 동적할당함수로 인해 할당된 포인터이어야 하며, 그렇지 않은 object를 전달하였을 경우 undefined behavior를 일으킬 수 있다. 


### The "Dangling Pointer" Problem 

   - free함수가 더 이상 필요하지 않은 메모리 공간에 대한 해제를 담당하지만, 이는 또 다른 문제를 일으킨다.

   char *p = malloc(4);
   free(p);
   strcpy(p, "abc");

   - 위 예시를 보자. strcpy에서 참조하는 p는 실제로 사용가능하지 않은 메모리 공간을 참조하고 있다. 이러한 문제를 dangling pointer문제라고 지칭한다. 

   - 이미 해제된 메모리공간을 참조하는 것은 undefined behavior를 일으킨다. 따라서 프로그래머는 블록이 해제될 때 이를 가리키는 모든 포인터들이 dangling pointer가 됨을 명심해야 한다. 


## 17.5 Linked List


### Declaring a Node Type 

   struct node {
      int value;
      struct node *next;
   };

   typedef struct node {
      int value;
      node *next;
   }

   - 자신의 포인터형을 가지는 구조체는 위와 같이 선언할 수 있다. 이러한 선언이 가능한 이유는 구조체 포인터의 크기는 메모리내의 주소값만을 저장하면 되기 때문에 컴파일 진행 시에 예측할 수 있기 때문이다. 


### creating node

   - 구조체 포인터를 사용해서 멤버에 접근할려고 할 때, -> 연산자를 사용할 수 있다. ->연산자는 lvalue를 의미한다. 따라서 우리는 변수가 사용되는 모든 공간에 이를 활용할 수 있다.  


### Inserting a Node at the Beginning of a Linked List 

    struct node *add_to_list(struct node *list, int n)
    {
	struct node* new_node;

	new_node = malloc(sizeof(struct node));
	if( new_node == NULL) {
	    printf("Error: malloc failed in add_to_list\n");
	    exit(EXIT_FAILURE);
	}
	new_node->value = n;
	new_node->next = list;
	return new_node;
    }

### Searching a Linked List

    struct node* search_list(struct node* list, int n)
    {
	struct node *p;

	for( p = list; p!= NULL; p = p->next)
	     if( p->value == n)
	     	 return p;
	return NULL;
     }

     struct node *search_list(struct node* list, int n)
     {
	for(; list!= NULL; list = list->next)
	      if( list->value == n)
	      	  return list;
	return NULL;
     }

     struct node *search_list(struct node* list, int n)
     {
	for(; list!= NULL && list->value != n; list = list->next);
	return list;
     }

     struct node *search_list(struct node *list, int n)
     {
	while( list != NULL && list->value != n)
	       list = list->next;
	return list;
     }

### Deleting a Node from a Linked List 

    struct node *delete_from_list(struct node *list, int n)
    {
	struct node *cur, *prev;

	for( cur = list, prev = NULL;
	     cur != NULL && cur->value != n;
	     prev = cur, cur = cur->next);

	if( cur == NULL)
	    return list;
	if (prev == NULL)
	   list = list->next;
	else 
	   prev -> next = cur->next;
	free(cur);
	return list;
     }

