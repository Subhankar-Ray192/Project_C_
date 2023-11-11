#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void main()
{
	pid_t q = fork();
	
	if(q == 0)
	{
		sleep(10);
		printf("c-env:%d-->%d\n",getppid(),getpid());
		
		pid_t r = fork();
		
		if(r==0)
		{
			execl("/bin/ps","ps","-aux",NULL);
		}
		else if(r>0)
		{
			wait(NULL);
		}
		else
		{
			fprintf(stderr,"FORK FAILED");
		}
	}
	else if(q > 0)
	{
		sleep(2);
		printf("p-env:%d-->%d\n",getpid(),q);
		
		pid_t w=fork();
		
		if(w==0)
		{
			execl("/bin/ps","ps","-aux",NULL);
		}
		else if(w>0)
		{
			wait(NULL);
		}
		else
		{
			fprintf(stderr,"FORK FAILED");
		}
	}
	else
	{
		fprintf(stderr,"FORK FAILED\n");
	}
}
