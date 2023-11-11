#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

void handle_sigint(int sig)
{
	write(STDOUT_FILENO,"I won't die!\n",13);
	execl("/bin/clear","clear",NULL);
}

void main()
{
	signal(SIGINT,handle_sigint);
	while(1)
	{
		printf("Hello%d\n",getpid());
	}
}
