## Pointers and Arrays ## 

### Pointer Arithmetic ###

	- 포인터 p가 배열 a의 원소를 가리키고 있다고 할 때, 포인터 연산을 통해서 다른 원소에 접근이 가능하다. 
	
	- 가능한 연산은 크게 3가지 이다.

	- pointer에 정수 더하기, 빼기, 한 포인터에서 다른 포인터 빼기이다. 

	- ex) int a[10], *p, *q, i,j;
	
	- p+j == a[i+j], p-j == a[i-j], p-q == i-j
	
	- 만약 포인터 연산의 결과가 배열의 원소를 가리키고 있지 않을 경우 Undefined behavior를 유발할 수 있다. 추가적으로 포인터간의 뺄셈 또한 같은 배열내의 원소를 가리키고 있는 포인터가 아닐 경우 정의되어 있지 않다. 

	- 포인터 간의 비교 연산 또한 가능하다.(<,<=,>,>=)
	
	- 위의 사칙연산과 마찬가지로 두 포인터 변수 모두 같은 배열을 참조하여야만 의미를 가진다. 
	
	- 참조 C99 : int *p = (int []){3,0,3,4,1}

### Using Pointers for Array Processing ###

	- ex) for(p=&a[0];p<&a[N];p++) sum+=*p;
	
	- *p++ or *(p++) : Value of expression is *p before increment; increment p later 

	- (*p)++ : Value of expression is *p before increment; increment p later 

	- *++p or *(++p) : Increment p first; value of expression is *p after increment

	- ++*p or ++(*p) : increment *p first; value of expression is *p after increment; 
   
### Using an Array Name as a Pointer ###

	- The name of an array can ve used as a pointer to the first element in the array.
	
	- Although an array name can be used as a pointer, it's not possible to assign it a new value. Attempting to make it point elsewhere is an erro: 

### Pointer Arithmetic ###
