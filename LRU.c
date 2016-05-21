#include <stdio.h>

void main ()
{
	int n,r,i,j,f1=0,f2=0,faults=0,g,h,index;
	printf("Enter the number of Page Frames\n");
	scanf("%d",&n);
	int a[n],c[n];
	printf("Enter the number of number of characters in reference strings\n");
	scanf("%d",&r);
	int b[r];
	printf("Enter the Reference String\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		a[i]= -1;
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[j]);
		}
		printf("\n");
		f1=0;
		f2=0;
		for(j=0;j<n;j++)
		{
			if(b[i]==a[j])
			{
				f1=1;
				f2=1;
				break;
			}
		}
		if(f1==0)
		{
			for(j=0;j<n;j++)
			{
				if(a[j]==-1)
				{
					a[j]=b[i];
					f2=1;
					faults++;
					break;
				}
			}
		}
		if(f2==0)
		{
			for(j=0;j<n;j++)
			{
				c[j]=0;
			}
			for(g=i-1,h=1;h<n;h++,g--)
			{
				
					for(j=0;j<n;j++)
					{
						if(b[g]==a[j])
						{
							c[j]=1;
						}
					}
			}
			for(j=0;j<n;j++)
			{
				if(c[j]==0)
				{
					index=j;
				}
			}
			a[index]=b[i];
			faults++;
		}
		
	}
	printf("Number of Page Faults are %d\n",faults);
}