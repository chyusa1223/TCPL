#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
/* Global variables */

int stack[SIZE] = {0};
int top=0;

/* prototypes */

/* stack func */
void push(int num);
int pop();
void print();

/* ETC */
void init();

/* arithmatic function */
void ar(char ch);

void ar(char ch)
{
  int a,b=0;
  switch(ch) {
  case '+':
    a = pop();
    b = pop();
    push(b+a);
    return;
  case '-': 
    a = pop();
    b = pop();
    push(b-a);
    return;
  case '*': 
    a = pop();
    b = pop();
    push(b*a);
    return;
  case '/': 
    a = pop();
    b = pop();
    push(b/a);
    return;
  case '=': 
    if(top != 1){
      printf("Not enough operands in expression\n");
      init();
    }
    else {
      printf("Value of expression: %d\n",pop());
      init();
    }
    return;
  default:
    return;
  }
}
void init()
{
  printf("Enter an RPN expression: ");
  for(int i=0;i<top;i++) stack[i] = 0;
  top = 0;
}
void print(){
  for(int i=0;i<top;i++) printf("%d ",stack[i]);
  printf("\n");
}

void push(int num)
{
  stack[top++] = num;
  print();
}

int pop()
{
  return stack[--top];
}

int main(int argc, char *argv[])
{
   
  char ch;

  init();
  do{

    scanf(" %c",&ch);
    if( ch >= '0' && ch<='9') {
      push(ch-'0');
    }
      else {
	ar(ch);
      }
    }while(1);

    return 0;
  }

