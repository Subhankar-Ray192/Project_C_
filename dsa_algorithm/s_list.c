#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
  int x;
  struct LinkedList *next;
}List;

List *null = (void *)0;

List* mem_allocate();

void insertH(List *,int);
void insertT(List *,int);
void insertB(List *,int,int);
void insertA(List *,int,int);

int delH(List *);
int delT(List *);
int delB(List *,int);
int delA(List *,int);

void display(List *);
int peekList(List *);

List * mem_allocate()
{
   return (List *)malloc(sizeof(List));
}

void insertH(List *head,int item)
{
  List *ptr =mem_allocate();

  ptr->x = item;
  ptr->next = head->next;
  head->next = ptr;
}

void insertT(List *head,int item)
{
  List *ptr =mem_allocate();
  ptr->x = item;
  ptr->next = null;

  List *copy =head;
  while(copy->next!=null)
  {
     copy =copy->next;
  }
  copy->next =ptr;
}

void insertB(List *head,int locator,int item)
{
  List *ptr =mem_allocate();
  ptr->x = item;

  List *iterator =head;
  List *copy =head;
  while((iterator->next!=null)&&(iterator->x!=locator))
  {
    copy=iterator;
    iterator=iterator->next;
  }
  ptr->next = copy->next;
  copy->next = ptr;
}

void insertA(List *head,int locator,int item)
{
  List *ptr=mem_allocate();
  ptr->x=item;

  List *iterator=head;
  while((iterator->next!=null)&&(iterator->x!=locator))
  {
    iterator=iterator->next;
  }
  ptr->next=iterator->next;
  iterator->next=ptr;
}

int delH(List *head)
{
  if(head->next==null)
  {
    return -1;
  }

  List *copy=head->next;
  head->next=copy->next;
  int item=copy->x;
  free(copy);
  return item;
}

int delT(List *head)
{

   if(head->next==null)
   {
      return -1;
   }

   List *copy=head;
   List *iterator=head;

   while(iterator->next!=null)
   {
       copy=iterator;
       iterator=iterator->next;
   }
   
   copy->next=null;
   int item=iterator->x;
   free(iterator);
   return item;
}

int delA(List *head, int locator)
{
   if(head->next==null)
   {
      return -1;
   }

   List *copy=head;
   
   while((copy->next!=null)&&(copy->x!=locator))
   {
      copy=copy->next;
   }
   List *free_node=copy->next;
   copy->next=free_node->next;
   int item=free_node->x;
   free(free_node);
   return item;
   
}

int delB(List *head, int locator)
{
   if(head->next==null)
   {
     return -1;
   }

   if(head->next->next==null)
   {
     return -1;
   }
   
   List *copy=head;
   List *free_node=head;
   List *iterator=head;

   while((iterator->next!=null)&&(iterator->x!=locator))
   {
      copy=free_node;
      free_node=iterator;
      iterator=iterator->next;
   }
   
   copy->next=iterator;
   int item=free_node->x;
   free(free_node);
   return item;
}

void display(List *head)
{
  printf("\nElements:");
  List *iterator = head->next;
  while(iterator->next!=null)
  {
     printf("%d,",iterator->x);
     iterator=iterator->next;
  }
  printf("%d.\n\n",iterator->x);
}

int peekList(List *head)
{
   return (head->next->x);
}
