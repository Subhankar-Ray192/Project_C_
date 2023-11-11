#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
	pid_t q = fork();

	if(q == 0)
	{
		printf("c-env:%d-->%d\n",getppid(),getpid());
		execl("/bin/ps","ps","-aux",NULL);
	}
	else if(q > 0)
	{
		wait(NULL);
	}
	else
	{
		fprintf(stderr,"FORK FAILED\n");
	}
}
