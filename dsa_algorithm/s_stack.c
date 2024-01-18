#include<stdio.h>
#include<stdlib.h>

#include "List.c"

#define MAX_CAP 100

typedef struct Stack{
   int top ;
   List * list;
}Stack;

Stack stack={.top = 0};

void push(int);
int pop();
int isEmpty();
int size();
int peek();

void push(int data)
{
   if(stack.top > MAX_CAP)
   {
      printf("\nERROR:OVERFLOW");
      return;
   }
   
   stack.top++;
   insertH(stack.list,data);
}

int pop()
{
   if(isEmpty())
   {
      printf("\nERROR:UNDERFLOW");
      return 0;
   }

   stack.top--;
   return delH(stack.list);
}

int isEmpty()
{
    if(stack.top == 0)
    {
       return 1;
    }
    return 0;
}

int size()
{
   return stack.top;
}

int peek()
{
   return peekList(stack.list);
}

void main()
{
   stack.list = mem_allocate();
   
   printf("\nStack:%d",isEmpty());
   push(10);
   printf("\nStack:%d",peek());
   push(20);
   printf("\nStack:%d",peek());
   push(-20);
   printf("\nStack:%d",peek());
   printf("\nSize:%d",size());
   printf("\nStack:%d",pop());
   printf("\nSize:%d",size());
   printf("\nStack:%d",pop());
   printf("\nSize:%d",size());
   printf("\nStack:%d",pop());
   printf("\nSize:%d",size());
   printf("\nStack:%d",pop());
}
