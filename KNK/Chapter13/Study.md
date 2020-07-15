## Strings ##

### String Literals

   - String literal is a sequence of characters enclosed within double quotes

   - String Literal을 연속하여 쓰기 어려운 경우에는 두 가지 방법이 존재한다. 첫 번째는 \를 문장의 끝에 사용할 경우 다음 문장을 다음 줄에 이어서 쓸 수 있으나, 들여쓰기는 불가하다. 두 번째는 "str1" "str2"와 같이 쓰는 방법으로 두 string이 붙어있고 가운데 공백이외의 문자가 없을 경우에는 두 문자열을 하나로 합쳐준다.

   - C언어는 String Literal을 char배열로 취급하며, 길이 n이 입력되었을 경우 n+1만큼 할당하고, 마지막에는 null문자를 쓴다.

   - String Literal이 배열의 형태로 저장되므로 C언어는 String literal을 char* 처럼 취급한다.

   - String Literal은 포인터 변수에 대입이 가능하다. 위에서 언급하였듯이 String Literal이 포인터로 취급하기 때문에 "ABCDEFG"[1]과 같이 접근하는것도 가능하다.

   - String Literal은 수정이 불가하며, 수정할려고 할 경우 UB를 유발한다.

### String Variables

   - 다른 언어들과는 다르게 C언어는 string을 위한 별도의 변수형이 존재하지 않으며, Char 배열을 str로 사용한다.

   - C언어에서는 문자열 변수의 마지막에는 무조건 null문자를 포함하고 있다고 가정하기 때문에 null문자가 존재하지 않을 경우에는 예상치 못한 결과를 초래할 수 있다.

   - 문자열 변수는 다음과 같이 초기화한다. char str[10] = "Apple";. 여기서 "Apple"은 String literal이 아니며 배열 초기화인자로서 취급한다.

   - 먄약 초기화로 주어진 문자열이 짧은 경우 마지막 문자열 이후는 \0가 기입되고, 길 경우에는 에러가 발생한다. 그러나 길이가 정확히 같은 경우에는 어떻게 될까? 익 여우에는 초기화를 허락하며 마지막에 null문자는 들어가지 않는다.

   - 만약 char date4[] = "June 14"와 같이 초기화할 경우에 date는 자동적으로 길이 8인 배열이 되며, 당연히 null 문자또한 포함되어 초기화 된다.

   - char dat[] = "JUNE" vs char *date = "JUNE"

   - 배열로 선언된 경우에는 배열내의 각 문자에 수정이 가능하다. 포인터의 경우에는 String literal을 참조하므로 수정이 불가하다.

   - date는 포인터 변수이므로 이후 다른 문자열을 가리키도록 수정 될 수 있지만, dat는 배열명으로 수정이 불가한 lvalue이다.


### Reading and Writing Strings

   - printf("%s",str); printf는 null문자를 만날때 까지 문자를 출력한다. 만약 null문자가 없을 경우 메모리상에 null문자를 찾을때 까지 출력한다. 

   - 만약 문자열의 일부만 출력하고 싶을 경우 printf("%.6s\n",str)과 같이 사용하면 된다. 

   - 만약 문자열의 일정한 공간에 출력하고 싶을 경우 printf("%6s\n",str)과 같이 사용하면 된다. 

   - printf외에도 puts 또한 string을 출력할 수 있으며, printf와는 다르게 항상 개행을 자동적으로 붙여준다.

   - scanf가 호출될 때 항상 문자열에 자동적으로 null문자를 추가하여 준다.

   - 그러나 scanf의 경우 공백문자가 존재할 경우 바로 string 입력을 중단한다. 만약 공백을 포함하여 입력받고 싶은 경우 gets를 사용할 수 있다.

   - gets의 경우의 경우에는 scanf와는 다른 점이 2가지 존재한다. 첫 번째는 공백문자를 포함하여 입력받으며 개행문자를 입력 받았을때만 입력을 멈춘다는 점이다. 두번째는 입력받은 개행문자를 null문자로 치환하여 저장한다는 점이다.

   - scanf, gets 모두 입력받은 문자가 배열의 사이즈를 넘어감에도 감지할 수 없다는 단점이 존재한다. scanf에서는 %ns와 같이 입력하여 이를 감지할 수 있다.

### Accessing characters in Strings

   - int count_space(const char *s)
     {
	int count=0;
	for(;*s!='\0';s++)
	if(*s == ' ') count++;
	return count;
     }

   - 공백문자를 count하기 위해 위와 같이 함수를 작성할 수 있다.

   - 배열과 포인터 둘 중 어떤 방식을 택해도 위와 같은 함수에서 속도상의 이득은 없으나 일반적으로 포인터로 접근하는 것을 관례적으로 선호한다.


### Using the C String Library

   - 이전에 언급하였듯이, char str1[10]; char str2[10]; 에서 str1 = "abc", str2와 같은 동작은 성립하지 않는다. 이는 배열명이 unmodifiable lvalue이기 때문이다. 또한 str1 != str2와 같은 비교도 불가한데 이는 둘이 포인터 이며 당연히 각 포인터의 주소는 항상 다르므로 언제나 false가 리턴된다.
   
   - char *strcpy(char *s1, const char *s2)  
   - s2에서 s1으로 문자열을 복사할 때 사용한다. 만약 s2의 길이가 s1보다 길다면 UB가 발생할 수 있다. 

   - char *strncpy(char *s1, const char *s2, sizeof(str1))
   - strncpy는 strcpy보다 속도는 느리지만 길이에 대한 정보를 추가함으로써 길이를 초과하는 입력을 제한한다. 그러나 길이가 같거나 큰 경우 마지막에 null문자를 입력하지는 않는다. 따라서 strncpy를 안전하게 사용하기 위해서는 다음과 같이 사용하여야 한다. strncpy(str1,str2,sizeof(str1)-1); str1[sizeof(str1)-1]='\0'; 

   - size_t strlen(const char *s)
   - 문자열의 길이를 리턴한다.

   - char *strcat(char *s1, const char *s2)
   - s2를 s1의 뒤에 붙인다. 이전의 함수와 마찬가지로 s1뒤에 s2를 붙일 공간이 충분치 않을 경우 어떠한 결과를 초래할 지 알 수 없다.

   - strncat(str1,str2,sizeof(str1)-strlen(str1)-1);
   - strncpy와 마찬가지로 남은 공간의 길이에 대한 정보를 포함시킬 수 있는 strncat함수가 존재한다. 다만 strncat함수보다 속도가 보다 느리다.

   - int strcmp(const char *s1, const char *s2)
   - 두 문자열간의 비교 결과값을 리턴한다. 문자열 간의 비교는 사전순에 따라 비교가 이루어진다.

### String Idioms

   - size_t strlen(const char *s) {
	size_t n;
	for(n=0;*s!='\0';s++) n++;
	return n;
     }

   - size_t strlen(const char *s) {
	size_t n=0;
	for(;*s!='\0';s++) n++;
	return n;
     }

   - size_t strlen(const char *s) {
	size_t n=0;
	for(;*s;s++) n++;
	return n;
     }

   - size_t strlen(const char *s) {
	size_t n=0;
	for(;*s++;) n++;
	return n;
     }

   - size_t strlen(const char *s) {
	size_t n=0;
	while(*s++) n++;
	return n;
     }

   - size_t strlen(const char *s) {
	char* p = s;
	while(*s++) n++;
	return s-p;
     }

   - char *strcat(char *s1, const char *s2)
     {
	char *p = s1;
	while( *p != '\0') p++;
	while( *s2 != '\0') {
	       *p++ = *s2++;
	}
	*p = '\0';
	return s1;
     }

   - char *strcat(char *s1, const char *s2)
     {
	char *p = s1;

	while( *p) p++;
	while( *p++ = *s2++);
	return s1;
     }

### Arrays of Strings

   - char *planet[]과 같이 선언할 경우 char이차원 배열을 선언할 경우에 생기는 공간의 낭비를 없앤 string의 포인터를 가지는 배열을 선언 할 수 있다.

   - 