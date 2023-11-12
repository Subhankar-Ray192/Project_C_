#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h>

struct semaphore
{
	sem_t S;
};

struct thread
{
	pthread_t T;
};

void * stat;
int shared_res=0;
char msg[]={"Hello World!"};

struct semaphore obj;

void *exe_thread(void *args);
void main_thread(int);

void *exe_thread(void *args)
{
	sem_wait(&obj.S);
	shared_res++;
	printf("Message:%s\n",(char *)args);
	sleep(2);
	sem_post(&obj.S);
	pthread_exit("Finished");
}

void main_thread(int limit)
{
	struct thread obj_1[10];

	for(int i=0;i<limit;i++)
	{
		pthread_create(&obj_1[i].T,NULL,exe_thread,(void *)msg);
	}

	for(int i=0;i<limit;i++)
	{
		pthread_join(obj_1[i].T,&stat);
		printf("Thread(%d)-Status:%s\n",obj_1[i].T,(char *)stat);
	}
	printf("Shared-Resouce:%d\n",shared_res);
}

void main()
{
	int n=0;
	printf("\nEnter Number of Threads:");
	scanf("%d",&n);
	sem_init(&obj.S,(n-2),1);
	main_thread(n);
}
