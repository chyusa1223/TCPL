
## Chapter 13. Strings 

## 1

   b) c) e) g) h) i)

## 2

   c) 
   * b) -> *p는 char형태로 당연히 puthchar로 출력이 가능하다.  

## 3

   12, abc, 34
   * %s는 string형으로 abc34까지 입력을 받는다. 따라서 12, abc34, 56이 답이 된다. 

## 4

   a) int read_line(char str[], int n)
      {
	int ch, i=0;
	while(isspace(getchar()));
	while((ch = getchar()) != '\n' && ch != EOF && isspace(ch) != true)
	    if( i<n-1) str[i++] = ch;
	    str[i++] = '\n';
	    str[i] = '\0';
	return i;
      }

## 5

   void Capitalize(char * str) {
	while( str[i] != '\0;){
	if( isalpha(str[i]) ) str[i] = toupper(str[i]);
	i++;
	}
   }

   void Capitalize(char * str) {
	while( *str != '\0){
	if( isalpha(str) ) str = toupper(str[i]);
	str++;
	}
   }

## 6

   void sense(char * s, char * t) {
   	char *p = "xxx";
	int cnt=0;

	while( *s){
	   if( *s == *p) {
	       cnt++;
	       if( cnt == 3) {
	           s -=3;
	       	   while( *s = *p && *p);
	       }
	   }
	   else cnt = 0;
	   s++;
	}
   	
   }

## 7

   d)

## 8

   "tired-or-wired?"
   
## 9

   "computers"

## 10

   지역변수로 선언되어 있어 return후에 이를 참조할 수 없다. 

## 11

   int strcmp(char *s, char *t)
   {
	while( *s == *t && *t && *s) s++,t++;
	return *s - *t;
   }

## 12

   void get_extension( const char *file_name, char *extension)
   {
	while(*file_name){
		if(*file_name++ == '.'){
		strcpy(extension,file_name);
		return;
		}
	}
	strcpy(extension,"");
   }

## 14

   "Grinch"

## 15

   a) 3, b) 0, c) 다른 문자열에 있지 않은 char의 위치 

## 16

   int count_space(const char *s)
   {
	int count = 0;
	while(*s ){
	   if(*s == ' ') count++;
	   s++;
	}
   }

## 18

   void remove_filename(char *url){
   	char *p = &url[strlen(url)-1];
   	while( *p-- == '/');
	*++p = '\0'; 
   }