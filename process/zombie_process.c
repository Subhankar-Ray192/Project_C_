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
	}
	else if(q > 0)
	{
		sleep(3);
		printf("p-env:%d-->%d\n",getpid(),q);
		execl("/bin/ps","ps","aux",NULL);
		exit(EXIT_SUCCESS);
	}
	else
	{
		fprintf(stderr,"FORK FAILED\n");
	}
}
