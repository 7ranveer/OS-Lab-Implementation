#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void main ()
{	printf("Before fork\n");
	printf("%d\n",getppid());
	printf("%d\n",getpid());
	int i;
	pid_t pid=fork();
	printf("After fork");
	if(pid<0)	
	{
		printf("no process can be created\n");
	}
	else if(pid>0)
	{
		wait(NULL);
		for(i=0;i<10;i++)
		printf("parent ID:%d\n",getppid());
	}
	else
	{
		sleep(3);
		for(i=0;i<10;i++)
		printf("child ID:%d\n",getpid());
	}
}