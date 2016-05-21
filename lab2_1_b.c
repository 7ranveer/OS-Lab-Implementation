#include<stdio.h>
#include<math.h>
void main()
{
int *r[10];
int i;
printf("Enter 10 integers\n");
for(i=0;i<10;i++)
{
scanf("%d",&r[i]);
}
for(i=0;i<10;i++)
{
printf("The address of int %d = %d\n",r[i],&r[i]);
}
}


