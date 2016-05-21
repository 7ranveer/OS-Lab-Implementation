#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main()
{
	int n,i,j=0,k=1,r,g=0;
	printf("Enter the memory space\n");
	scanf("%d",&n);
	printf("\n");
	int a[n];
	while(k=1)
	{
		printf("Press\n1. producer\n2.Consumer\n");
		scanf("%d",&i);
		printf("\n");
		switch(i)
		{
			case 1:
			{
				if((j-1)!=n)
				{
					printf("Enter the product\n\n");
					scanf("%d",&a[j]);
					j++;

				}
				else
				{
					printf("Cannot produce more\n\n");
				}
				printf("top points to %d\n",a[g]);
				for(r=j-1;r>=0;r--)
					{printf("%d ",a[r]);}
				printf("\n");
				break;
			}
			case 2:
			{
				if(j!=0)
				{
					printf("The Product is %d\n",a[g]);
					g++;
				}
				else
				{
					printf("No product to display\n");
				}
				printf("top points to %d\n",a[g]);
				for(r=j-1;r>=0;r--)
					{printf("%d ",a[r]);}
				printf("\n");
				break;

			}
			default:
			{
				printf("Dont try to be oversmart\n");
			}
		}
		printf("press 1 to continue and 0 to exit\n");
		scanf("%d",&k);
		if(k==0)
		{
			break;
		}
	}
}