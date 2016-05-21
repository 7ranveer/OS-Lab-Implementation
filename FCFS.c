#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct process
{
	int at,bt,ft,wt,pid,tat;
};
typedef struct process p_adt;
void dis(p_adt *p,int no,float avg,float tat)
{
	int i;
	printf("\n\t\t********FCFS*********\n");
	printf("\nP_ID   Arrival\t\tBurst\t\tTurnAround\t\tWait\n");
	for(i=0;i<no;i++)
	{
		printf("%d\t %d\t\t %d\t\t %d\t\t %d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt);
	}
	printf("Average Waiting Time is :%f\n",avg);
	printf("Average Turn Around time is:%f\n",tat);
}
float turnAround(p_adt*p,int n)
{
	int i;
	float tave=0;
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ft-p[i].at;
		tave+=p[i].tat;
	}
	return tave/n;
}
void finish(p_adt *p,int n)
{
	int current=0,i;
	for(i=0;i<n;i++)
	{
		current+=p[i].bt;
		p[i].ft=current;
	}
}
float average(p_adt *p,int n)
{
	int i;
	float ave=0;
	for(i=0;i<n;i++)
	{
		p[i].wt=p[i].ft-(p[i].bt+p[i].at);
		ave+=p[i].wt;
	}
	return ave/n;
}
void main()
{
	int n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	p_adt *p=(p_adt*)malloc(n*sizeof(p_adt));
	for(i=0;i<n;i++)
		{
			printf("Enter the arrival time of process %d-> ",i);
			p[i].pid=i;
			scanf("%d",&p[i].at);
		}
	for(i=0;i<n;i++)
		{
		printf("Enter the burst time of process %d-> ",i);
		scanf("%d",&p[i].bt);
		}
	finish(p,n);
	float avg=average(p,n);
	float tat=turnAround(p,n);
	dis(p,n,avg,tat);
}
