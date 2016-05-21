#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
void main ()
{	printf("Before fork\n");
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
		printf("parent ID:%d\n",getppid());
	}
	else
	{
		printf("child ID:%d\n",getpid());
		execl("/bin/ls", "ls", "-1", 0);
		 // system("ls");
	}
}