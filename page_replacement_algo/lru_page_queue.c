#include<stdio.h>
#include<stdlib.h>


int ref_string[100];
int ref_string_len = 0;
char hit_miss[3] = {'M','H','$'};

struct page_queue
{
	int queue[100];
	int frame_count;
	int max_frame_count;
	float hit_counter;
};

struct page_queue obj = {.max_frame_count = 3, .frame_count = 0, .queue[0]=1};

void enque(int);
void display(int,int);
int isHit(int);


void display(int hm_count,int stat)
{
	if(stat)
	{
		printf("\n|Curr --> ");
		for(int i=1 ; i<=obj.max_frame_count; i++)
		{
			if(i!=obj.max_frame_count)
			{
				printf("%d,",obj.queue[i]);
			}
			else
			{
				printf("%d ",obj.queue[i]);
			}
		}
		printf("|   %c    | %0.2f%",hit_miss[hm_count], ((obj.hit_counter)/ref_string_len)*100);
	}
	else
	{
		printf("\n----------------------------------");
		printf("\n|Fina --> ");
		for(int i=1 ; i<=obj.max_frame_count; i++)
		{
			if(i!=obj.max_frame_count)
			{
				printf("%d,",obj.queue[i]);
			}
			else
			{
				printf("%d ",obj.queue[i]);
			}
		}
		printf("|   %c    | %0.2f%",hit_miss[hm_count], ((obj.hit_counter)/ref_string_len)*100);
		printf("\n----------------------------------");
	}
}

void enque(int data)
{
	if(!isHit(data))
	{
		obj.queue[(obj.frame_count % obj.max_frame_count) + 1] = data;
		obj.frame_count = obj.frame_count + 1;
		display(0,1);
	}
	else
	{
		obj.frame_count = obj.frame_count + 1;
		display(1,1);
	}

}

int isHit(int data)
{
	int count = 1;
	while(count <=obj.max_frame_count)
	{
		if(data == obj.queue[count])
		{
			obj.hit_counter = obj.hit_counter + 1;
			return 1;
		}
		count = count + 1;
	}
	return 0;
}

void main()
{
	printf("\nEnter Length:");
	scanf("%d",&ref_string_len);

	printf("\nEnter Reference String:");
	for(int i =0 ; i< ref_string_len; i++)
	{
		scanf("%d",&ref_string[i]);
	}
	
	printf("\n----------------------------------");
	printf("\n|    Frames    | Status | Hit(%)");
	printf("\n----------------------------------");
	
	for(int i =0 ; i< ref_string_len; i++)
	{
		enque(ref_string[i]);
	}
	display(2,0);
	printf("\n");
}
