#include <stdio.h>
#include <malloc.h>
struct process
{
int pid,at,bt,wt,ft,tat,finish,arr,rt,got;
};
typedef struct process p_adt;
void dis(p_adt *p,int no,float avg,float tat)
{
	int i;
	printf("\n\t\t*****Round Robin*********\n");
	printf("\nP_ID   Arrival\t\tBurst\t\tTurnAround\tfinish\t\twait\n");
	for(i=0;i<no;i++)
	{
		printf("%d\t %d\t\t %d\t\t %d\t\t %d \t\t %d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].ft,p[i].wt);
	}
	printf("Average Waiting Time is :%f\n",avg);
	printf("Average Turn Around time is:%f\n",tat);
}
void finish(p_adt *p,int n)
{
	int cputime=0,i,remain=n;
	for(i=0;remain!=0;)
	{
		if(p[i].rt<=3 && p[i].rt>0)
		{
			cputime+=p[i].rt;
			p[i].rt=0;
			p[i].finish=1;
		}
		else if(p[i].rt>0)
		{
			p[i].rt-=3;
			cputime+=3;
		}
		if(p[i].rt==0)
		{
			if(p[i].finish==1 && p[i].got==0)
				{
					remain--;
					p[i].ft=cputime;
					p[i].got=1;
				}
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(p[i+1].at<=cputime)
		{
			i++;
		}
		else
		{
			i=0;
		}


	}
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
	printf("enter the number of processes\n");
	scanf("%d",&n);
	p_adt *p=(p_adt*)malloc(n*sizeof(p_adt));
	for(i=0;i<n;i++)
		{
			printf("Enter the arrival time of process %d-> ",i);
			p[i].pid=i;
			p[i].got=0;
			scanf("%d",&p[i].at);
		}
	for(i=0;i<n;i++)
		{
		printf("Enter the burst time of process %d-> ",i);
		p[i].finish=0;
		scanf("%d",&p[i].bt);
		p[i].rt=p[i].bt;
		}
	finish(p,n);
	float avg=average(p,n);
	float tat=turnAround(p,n);
	dis(p,n,avg,tat);
	}