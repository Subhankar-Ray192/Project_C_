#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>


struct semaphore
{
	sem_t S;
};

struct thread
{
	pthread_t T;
};

struct semaphore obj;
void *stat;

void *exe_thread(void *args);
void main_thread();

char msg[2][15]={"Hello World-1","Hello World-2"};

void *exe_thread(void *args)
{
	printf("Message-A:%s\n",(char *)args);
	sem_post(&obj.S);
	sem_wait(&obj.S);
	printf("Message-B:%s\n",(char *)args);
	pthread_exit("Finished");
}

void main_thread()
{
	struct thread obj1;
	struct thread obj2;

	pthread_create(&obj1.T,NULL,exe_thread,(void *)msg[0]);
	pthread_create(&obj2.T,NULL,exe_thread,(void *)msg[1]);

	pthread_join(obj1.T,&stat);
	printf("Status-Thread(%d):%s\n",obj1.T,(char *)stat);
	
	pthread_join(obj2.T,&stat);
	printf("Status-Thread(%d):%s\n",obj2.T,(char *)stat);

	
}

void main()
{
	sem_init(&obj.S,0,1);
	main_thread();
}
