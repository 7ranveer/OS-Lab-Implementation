#include<stdio.h>
#include<math.h>
void main(){
int a1,b1,a2,b2,i,j,k;
int *p,*q,*r;
printf("Enter the rows and column of the first matrix\n");
scanf("%d%d",&a1,&b1);
printf("Enter the rows and column of the second matrix\n");
scanf("%d%d",&a2,&b2);
int a[a1][b1],b[a2][b2], c[a1][b2];    
if(a2!=b1)
{printf("please enter correct dimensions such that the multiplication is possible\n");}
else
{
printf("enter the elements of the first matrix column wise\n");
for(i=0;i<a1;i++)
{
for(j=0;j<b1;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("Please enter the elements of the second matrix column wise\n");
for(i=0;i<a2;i++)
{
for(j=0;j<b2;j++)
{
scanf("%d",&b[i][j]);
}
}                            
p=&a[0][0];
q=&b[0][0];
r=&c[0][0];
for(i=0;i<a1;i++)
{
for(k=0;k<b2;k++)
{
*(r+(i*a1+k))=0;
for(j=0;j<b1;j++)
{
*(r+(i*a1+k))+=*(p+(i*a1+j))**(q+(j*b2+k));
}
}
}
for(i=0;i<a1;i++)
{
for(j=0;j<b2;j++)
{
printf("%d\t",c[i][j]);
}		                            
printf("\n");
}                              
}
}       
       


