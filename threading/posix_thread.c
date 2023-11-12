#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

void *exec_thread(void *args);
void main_thread();
char msg[] = "Hello World!";

struct thred
{
	pthread_t T;
};

struct thred obj;
void *stat;

void *exec_thread(void *args)
{
	printf("Child-Thread-Start:%d\n",obj.T);
	printf("Message:%s\n",(char *)args);
	sleep(5);
	strcpy(msg,"Bye");
	printf("New-Message:%s\n",msg);
	pthread_exit("Child Thread Joined");
}

void main_thread()
{
	printf("\nMain-Thread-Start\n");
	sleep(3);
	pthread_create(&obj.T,NULL,exec_thread,(void *)msg);
	pthread_join(obj.T,&stat);
	printf("%s\n",(char *)stat);
	printf("Main-Thread-Finish\n");
}

void main()
{
	main_thread();
}

