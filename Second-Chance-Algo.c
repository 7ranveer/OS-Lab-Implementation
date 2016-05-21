#include <stdio.h>
void main(){
	int n,i,j,k,a[3],r[3],f1,f2,g,h,index,faults=0,c[3];
	printf("Enter the number of number of characters in reference strings\n");
	scanf("%d",&n);
	int b[n];
	printf("Enter the Reference String\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<3;i++)
	{
		a[i]= -1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",a[j]);
		}
		printf("\n");
		f1=0;
		f2=0;
		for(j=0;j<3;j++)
		{
			if(a[j]==b[i])
			{
				r[j]=1;
				f1=1;
				f2=1;
				break;
			}
		}
		if(f1==0)
		{
			for(j=0;j<3;j++)
			{
				if(a[j]==-1)
				{
					a[j]=b[i];
					r[j]=0;
					f2=1;
					faults++;
					break;
				}
			}
		}
		if(f2==0)
		{

			for(j=0;j<3;j++)
			{
				c[j]=0;
			}
			for(g=i-1,h=1;h<3;h++,g--)
			{
				
					for(j=0;j<3;j++)
					{
						if(b[g]==a[j])
						{
							c[j]=1;
						}
					}
			}
			for(k=0;k<3;k++)
			{
				if(c[k]==0 && r[k]==0)
				{
					index=k;
				}

			}
			a[index]=b[i];
			faults++;
			for(k=index;k>=0;k--)
			{
				r[k]=0;
			}
			
		}
	}
	printf("Number of Page Faults are %d\n",faults);
}
