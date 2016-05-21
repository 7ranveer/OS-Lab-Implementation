#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void *runner(void *param)
{
	int i,j,indi,upper=atoi(param);
	for(j=2;j<=upper;j++)
	{
		indi=0;
		for(i=2;i<=sqrt(j);i++)
		{
			if(j%i==0)
			{
				indi=1;
			}
			
		
		}
		if(indi==0)
		{
			printf("%d ",j);
		}


	}
	
	pthread_exit(0);
}
int main(int argc, char const *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	if(argc!=2)
	{
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}
	if(atoi(argv[1])<0)
	{
		fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
		return -1;
	}
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
}