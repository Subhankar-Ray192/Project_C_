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
void main_thread();

void *exe_thread(void *args)
{
	sem_wait(&obj.S);
	shared_res++;
	printf("Message:%s\n",(char *)args);
	sleep(3);
	sem_post(&obj.S);
	pthread_exit("Finished");
}

void main_thread()
{
	struct thread obj1;
	struct thread obj2;

	pthread_create(&obj1.T,NULL,exe_thread,(void *)msg);
	
	pthread_create(&obj2.T,NULL,exe_thread,(void *)msg);

	pthread_join(obj1.T,&stat);
	printf("Thread(%d)-Status:%s\n",obj1.T,(char *)stat);
	
	pthread_join(obj2.T,&stat);
	printf("Thread(%d)-Status:%s\n",obj2.T,(char *)stat);
	
	printf("Shared-Resouce:%d\n",shared_res);
}

void main()
{
	sem_init(&obj.S,0,1);
	main_thread();
}
