#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Num_Threads 5 
int min,max,med,argno;
float avg,sd;
void *maximum(void *a)
{
	int i,*ar=(int *)a;

	max=ar[0];
	for(i=0;i<argno-1;i++)
	{
		if(ar[i]>max)
		{
			max=ar[i];
		}
		else
		{
			continue;
		}
	}
	pthread_exit(0);
}
void *minimum(void *a)
{	
	int i,*ar=(int *)a;
	min=ar[0];
	for(i=0;i<argno-1;i++)
	{
		if(ar[i]<min)
		{
			min=ar[i];
		}
		else
		{
			continue;
		}
	}
	pthread_exit(0);
}
void *median(void *a)
{
	int i,j,*ar=(int *)a;
	for(i=0;i<argno-1;i++)
	{
		for(j=0;j<i;j++)
		{
			if(ar[j]>ar[i])
			{
				int temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}
	
	med=ar[(argno-1)/2];
	pthread_exit(0);
}
void *standard_deviation(void *a)
{
	int i,*ar=(int *)a,sed=0,mean=0,sum=0;
	for(i=0;i<argno-1;i++)
	{
		sum+=ar[i];
	}
	mean=sum/(argno-1);
	for(i=0;i<argno-1;i++)
	{
		sed+=(ar[i]-mean)*(ar[i]-mean);
	}
	sd=sqrt(sed/(argno-2));
	pthread_exit(0);
}
void *average(void *a)
{	int i,*ar=(int *)a,sum=0;
	for(i=0;i<argno-1;i++)
	{
		sum+=ar[i];
	}
	avg=sum/(argno-1);
	
	pthread_exit(0);
}
int main(int argc, char const *argv[])
{
	argno=argc;
	int a[1000];
	pthread_t workers[Num_Threads];
	pthread_attr_t attr;
	
	if(argc==1)
	{
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}
	if(atoi(argv[1])<0)
	{
		fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
		return -1;
	}
	for(int i=1;i<argc;i++)
	{
		a[i-1]=atoi(argv[i]);
	}
	pthread_attr_init(&attr);
	pthread_create(&workers[0],&attr,average,(void *)a);
	pthread_create(&workers[1],&attr,maximum,(void *)a);
	pthread_create(&workers[2],&attr,minimum,(void *)a);
	pthread_create(&workers[3],&attr,median,(void *)a);
	pthread_create(&workers[4],&attr,standard_deviation,(void *)a);

	for(int o=0;o<Num_Threads;o++)
	{
		pthread_join(workers[o],NULL);	
	}
	printf("The Average value is:%f\n",avg);
	printf("The minimum value is:%d\n",min);
	printf("The maximum value is:%d\n",max);
	printf("The standard deviation value is:%f\n",sd);
	printf("The median value is:%d\n",med);

}