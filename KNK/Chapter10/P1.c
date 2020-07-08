#include <stdio.h>

#define SIZE 1000

typedef int bool;
typedef char stack_type;

stack_type stack[SIZE];
int top=0;

void print_stack()
{
  int i;
  for(i=0;i<top;i++){
    printf("%c,",stack[i]);
  }
  printf("\n");
}

bool issame(stack_type a, stack_type b)
{
  printf("issame = %c %c\n",a,b);
  if( a == '(' && b == ')') return 1;
  else if( a == '[' && b == ']') return 1;
  else if( a == '{' && b == '}') return 1;
  else if( a == '<' && b == '>') return 1;
  else return 0;
}

stack_type push(stack_type a)
{
  if( top == SIZE-1){
    printf("Stack is Full!!\n");
    return -1;
  }
   
  stack[top] = a;
  print_stack();
  return stack[top++];
}

stack_type pop()
{
  if( top > 0){
    print_stack();
    return stack[--top];
  }
  else{
    print_stack();
    printf("Stack is empty!!\n");
    return -1;
  }
}

stack_type peek()
{
  if( top != -1)
    return stack[top-1];
  else{
    printf("Stack is empty!!\n");
    return -1;
  }
}

int main(int argc, char *argv[])
{
  char ch;

  while((ch = getchar()) != '\n') {
    if( issame(peek(),ch)){
      pop();
    }
    else {
      push(ch);
    }
  }

  printf("Final Stack :"); print_stack();

  if( top == 0) printf("Parenthese/braces are nested properly\n");
  else printf("Parenthese/braces are Not nested properly\n");

  return 0;
}
