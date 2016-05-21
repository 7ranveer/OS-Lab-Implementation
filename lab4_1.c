#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main ()
{	printf("Before fork");
	printf("%d\n",getppid());
	printf("%d\n",getpid());
	
	pid_t pid=fork();
	printf("After fork");
	if(pid<0)	
	{
		printf("no process can be created\n");
	}
	else if(pid>0)
	{
		printf("pid:%d\n",pid);
		printf("parent ID:%d\n",getppid());
		printf("%d\n",getpid());
	}
	else
	{
		printf("child ID:%d\n",getpid());
	
	}
}