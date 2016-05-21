//RANVIRSINH DADUBHA GOHIL 201452010
#include <stdio.h>
#include <malloc.h>
void main(){
int n,r,i,j,s,q,e;
printf("Enter the Number of processes\n");		//number of processes
scanf("%d",&n);
printf("Enter the Number of resources\n");		//number of resources
scanf("%d",&r);
int allc[n][r],max[n][r],need[n][r],ins[r],arr[r],finish[n];
printf("Enter the maximum instances of resources\n");
for(i=0;i<r;i++)
{
	arr[i]=0;												//maximum number of instances for each resources
	scanf("%d",&ins[i]);
}
printf("Enter the allocated resources for each process\n");
	for(i=0;i<n;i++)
	{
		finish[i]=0;
		for(j=0;j<r;j++)
		{
			scanf("%d",&allc[i][j]);							//allocated resources matrix
			
			arr[j]=arr[j]+allc[i][j];		//sum calculated
			
		}
	}
	for(i=0;i<r;i++)
	{
		arr[i]=ins[i]-arr[i];				//difference calculated
	}
printf("Enter the maximum resources that can be allocated\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{														//maximum resources matrix
			scanf("%d",&max[i][j]);
		}
	}
						for(i=0;i<n;i++)
						{
							for(j=0;j<r;j++)
							{													
								need[i][j]=max[i][j]-allc[i][j];
																	//need matrix
							}
						}
	
		for(i=0;i<n;i++)
		{
			q=0;
			if(finish[i]==0)			//remaining processes
			{
							for(j=0;j<r;j++)
						{
							if(need[i][j]<=arr[j])
							{								//condition for process execution
								q++;
							}
						}
						if(q==r)
						{	
							printf("process %d executed\n",i);
							finish[i]=1;
							for(s=0;s<r;s++)
							{
								arr[s]=arr[s]+allc[i][s];			//reallocating resources 
								printf("%d ",arr[s]);
							}
							printf("\n");

						i=-1;

						}
									}
			

		}
	
			for(j=0;j<r;j++)
			{
				if(arr[j]<ins[j])
				{														//unsafe condition
					e++;
				}
			}
			if(e==r)
			{
				printf("UNSAFE CONDITION\n");
			}
}