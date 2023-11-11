#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int counter=0;
int counter1 =1;
int pid[10];

void display();

void display()
{
  printf("\n");
  for(int i=0;i<10;i++)
  {
    printf("%d,",pid[i]);
  }
  printf("\n");
}

void main()
{
	//Fork-Process: Child-Process Creation
	pid[counter]=fork();

	if(pid[counter]<0)
  	{
    		fprintf(stderr,"\nFork Failed\n");
  	}
  	else if(pid[counter]==0)
  	{
    		printf("\nExecuting Child-Process:");
    		printf("\nC-%d:%d-->%d\n",(counter+1),getppid(),getpid());
		fflush(stdout);

		pid[counter1] = fork();
		
		if(pid[counter1]<0)
  		{
    			fprintf(stderr,"\nFork Failed\n");
  		}
  		else if(pid[counter1]==0)
  		{
    			printf("\nExecuting Child-Process:");
    			printf("\nC-%d:%d-->%d",(counter1+1),getppid(),getpid());
  		}
  		else
  		{
			wait(NULL);
    			printf("\nExecuing Parent-Process:");
    			printf("\nP-%d:%d-->%d\n",(counter1+1),getpid(),pid[counter1]);
			fflush(stdout);
  		}
		exit(0);
  	}
  	else
  	{
		wait(NULL);
		printf("wait-status:%d",wait);
    		printf("\nExecuing Parent-Process:");
    		printf("\nP-%d:%d-->%d\n",(counter+1),getpid(),pid[counter]);
		fflush(stdout);
  	}
	
	exit(0);
}
