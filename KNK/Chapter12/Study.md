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

### Using an Array Name as a Pointer ###

   - 만약 일반적인 변수가 함수로 전달될 때, 변수의 값만이 복사된다. 그러므로 함수 내에서 전달된 파라미터에 대해 값이 변경되어도 함수 외부의 변수에는 영향을 주지 못한다.

   - 만약에 함수에 배열이 전달될 경우, 배열의 이름은 언제나 포인터형으로 취급된다. 따라서 함수에 전달되는 배열의 크기에 따른 오버헤드는 존재하지 않는다.

   - 배열 파라미터는 포인터 형으로 작성될 수 있으며, 이는 사실상 동일하다고 봐도 무방하다.

   - 만약 함수에 배열의 일부만 전달하고 싶을 경우 다음과 같이 전달하는 것이 가능하다.

   - ex) find_largest(&b[5],10);

   - 배열명을 포인터로 사용할 수 있듯이 포인터 또한 배열명처럼 사용하는 것이 가능하다.
    
   - 컴파일러는 p[i] -> *(p+i)처럼 취급한다.

### Pointers and Multidimensional Arrays ###

   - for( p = &a[0][0]; p <= &a[ROW][COL]; p++) *p=0;

   - for( p= &a[0];p<&a[rows];p++) (*p)[i] = 0;

   - 여기서 p는 int (*p)[10]과 같이 선언되며 이는 int변수 10개를 가지는 배열에 대한 포인터를 의미한다.

   - 이차원 배열에서 배열명은 a[0][0]를 가리키지 않는다. 대신 a는 a[0]를 가리킨다. 이는 2차원 배열또한 1차원 배열을 원소로 가지는 1차원 배열로서 취급하기 때문이다. 따라서 a는 &a[0]이며, int(*p)[row]와 동일하다. 

      int find_largest(int a[],int n)
      {
	int i, max;

	max = a[0];
	for(i=1;i<n;i++){
	    if(a[i]>max){
		max = a[i];
	    }
	return max;
       }

   - 이차원 배열의 경우에도 위의 find_largest함수를 동일하게 사용이 가능하다.

   - find_largest(a[0],rows*cols); // a가 아닌 a[0]를 전달하는 이유는 a를 전달하게 되면, a의 타입이 int(*)[cols]이므로 타입이 일치하지 않기 때문이다. 


### Q&A ###

   - You said that treating a two-demensional array as one-dimensional works with "most" C compilers. Doesn't it work with all compilers?

   - No, Some modern "bounds-checking" compilers track not only the type of a pointer, but-when it points to an array-also the length of the array. For example, suppose that p is assigned a pointer to a[0][0]. Technically, p points to the first element of a[0], a one-dimensional array. If we increment p repeatedly in an effort to visit all the elements of a, we'll go out of bounds once p goes past the last elements of a[0]. A compiler that performs bounds-checking may insert code to check that p is used only to access elements in the array pointed to by a[0]; an attempt to increment p past the end of this array would be detected as an error 
