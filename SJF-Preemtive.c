#include <stdio.h>
#include <malloc.h>
struct process
{
int pid,at,bt,wt,ft,tat,finish,arr,count;
};
typedef struct process p_adt;
void dis(p_adt *p,int no,float avg,float tat)
{
	int i;
	printf("\n\t\t*****Preemptive    SJF*********\n");
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
	int cputime=0,i,j,k,a,s,min,id,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=p[i].bt;
	}
	for(i=0;i<=sum;i++)
	{
		k=0;
		for(j=0;j<n;j++)
			{
				if(p[j].finish==0)
				{	
					if(p[j].at<=cputime)
					{
						p[k].arr=p[j].pid;
						a=j;
						k++;
					}
				}
			}
		min=p[a].bt;
		id=p[k-1].arr;
		for(s=p[0].arr;s<p[k-1].arr;s++)
		{
			if(p[s].finish==0)
			{
				if(p[s].bt<=min)
				{
					min=p[s].bt;
					id=s;
				}
			}
		}
		cputime++;	
		p[id].ft=cputime;
		p[id].count++;
		if(p[id].count==p[id].bt)
		{
			p[id].finish=1;
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
			scanf("%d",&p[i].at);
		}
	for(i=0;i<n;i++)
		{
		printf("Enter the burst time of process %d-> ",i);
		p[i].finish=0;
		p[i].count=0;
		scanf("%d",&p[i].bt);
		}
	finish(p,n);
	float avg=average(p,n);
	float tat=turnAround(p,n);
	dis(p,n,avg,tat);
	}