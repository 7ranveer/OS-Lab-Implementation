#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
void main ()
{	pid_t pid1,pid2;
	printf("%d\n",getpid());
	pid1=fork();
	pid2=fork();
	if(pid1>0)
		printf("pid1 p:%d\n",getpid());
	if(pid1==0)
		printf("pid1 c:%d\n",getpid());
	if(pid2>0)
		printf("pid2 p:%d\n",getpid());
	if(pid2==0)
		printf("pid2 c:%d\n",getpid());
	Dir dir;
	dir=opendir(.);
	printf("%s",readdir(dir));

}
