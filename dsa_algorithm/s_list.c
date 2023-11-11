#include<stdio.h>
#include<stdlib.h>

struct data
{
  int x;
  struct data *next;
};

struct data *null = (void *)0;

void insertH(struct data *,int);
void insertT(struct data *,int);
void insertB(struct data *,int,int);
void insertA(struct data *,int,int);

int delH(struct data *);
int delT(struct data *);
int delB(struct data *,int);
int delA(struct data *,int);

void display(struct data *);

void insertH(struct data *head,int item)
{
  struct data *ptr =(struct data *)malloc(sizeof(struct data));

  ptr->x = item;
  ptr->next = head->next;
  head->next = ptr;
}

void insertT(struct data *head,int item)
{
  struct data *ptr =(struct data *)malloc(sizeof(struct data));
  ptr->x = item;
  ptr->next = null;

  struct data *copy =head;
  while(copy->next!=null)
  {
     copy =copy->next;
  }
  copy->next =ptr;
}

void insertB(struct data *head,int locator,int item)
{
  struct data *ptr =(struct data *)malloc(sizeof(struct data));
  ptr->x = item;

  struct data *iterator =head;
  struct data *copy =head;
  while((iterator->next!=null)&&(iterator->x!=locator))
  {
    copy=iterator;
    iterator=iterator->next;
  }
  ptr->next = copy->next;
  copy->next = ptr;
}

void insertA(struct data *head,int locator,int item)
{
  struct data *ptr=(struct data *)malloc(sizeof(struct data));
  ptr->x=item;

  struct data *iterator=head;
  while((iterator->next!=null)&&(iterator->x!=locator))
  {
    iterator=iterator->next;
  }
  ptr->next=iterator->next;
  iterator->next=ptr;
}

int delH(struct data *head)
{
  if(head->next==null)
  {
    return -1;
  }

  struct data *copy=head->next;
  head->next=copy->next;
  int item=copy->x;
  free(copy);
  return item;
}

int delT(struct data *head)
{

   if(head->next==null)
   {
      return -1;
   }

   struct data *copy=head;
   struct data *iterator=head;

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

int delA(struct data *head, int locator)
{
   if(head->next==null)
   {
      return -1;
   }

   struct data *copy=head;
   
   while((copy->next!=null)&&(copy->x!=locator))
   {
      copy=copy->next;
   }
   struct data *free_node=copy->next;
   copy->next=free_node->next;
   int item=free_node->x;
   free(free_node);
   return item;
   
}

int delB(struct data *head, int locator)
{
   if(head->next==null)
   {
     return -1;
   }

   if(head->next->next==null)
   {
     return -1;
   }
   
   struct data *copy=head;
   struct data *free_node=head;
   struct data *iterator=head;

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

void display(struct data *head)
{
  printf("\nElements:");
  struct data *iterator = head->next;
  while(iterator->next!=null)
  {
     printf("%d,",iterator->x);
     iterator=iterator->next;
  }
  printf("%d.\n\n",iterator->x);
}

void main()
{
  struct data *list=(struct data *)malloc(sizeof(struct data));

  insertH(list,5);
  display(list);
  insertH(list,-2);
  display(list);
  insertT(list,18);
  display(list);
  insertT(list,-31);
  display(list);
  insertB(list,18,7);
  display(list);
  insertB(list,7,4);
  display(list);
  insertA(list,7,-7);
  display(list);
  printf("%d",delH(list));
  display(list);
  printf("%d",delT(list));
  display(list);
  printf("%d",delA(list,7));
  display(list);
  printf("%d",delB(list,7));
  display(list);
}

