#include<stdio.h>
#include<stdlib.h>


int ref_string[100];

struct page_queue
{
	int queue[100];
	int frame_count;
	int max_frame_count;
	float hit_counter;
};

struct page_queue obj = {.max_frame_count = 3, .frame_count = 0};

void enque(int);
void display();
int isHit(int *);


void display()
{
	printf("\nQueue:");
	for(int i=0 ; i< obj.max_frame_count; i++)
	{
		printf("%d,",obj.queue[i]);
	}
}

void enque(int data)
{
	display();
	if(obj.frame_count < obj.max_frame_count)
	{
		printf("M");
		obj.queue[obj.frame_count] = data;
		obj.frame_count = obj.frame_count + 1;
	}
	else
	{
		if(!isHit(data))
		{
			printf("M");
			obj.queue[obj.frame_count % obj.max_frame_count] = data;
		}
		else
		{
			printf("H");
		}
		obj.frame_count = obj.frame_count + 1;
	}

}

int isHit(int *data)
{
	int o_count = 0;
	while(o_count < obj.max_frame_count)
	{
		int i_count = 0;
		while(i_count < obj.max_frame_count)
		{
			if(data == obj.queue[i_count])
			{
				obj.hit_counter = obj.hit_counter + 1;
				return 1;
			}
			i_count = i_count + 1;
		}
	}
	return 0;
}

void main()
{
	int ref_string_len = 0;
	printf("\nEnter Length:");
	scanf("%d",&ref_string_len);

	printf("\nEnter Reference String:");
	for(int i =0 ; i< ref_string_len; i++)
	{
		scanf("%d",&ref_string[i]);
		//printf("%d",ref_string[i]);
		enque(ref_string[i]);
	}
	display();
	printf("M");
	printf("\nHit-Ratio:%f",(obj.hit_counter)/8.0);

}
