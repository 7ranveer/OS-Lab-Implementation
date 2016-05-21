#include<stdio.h>
#include<math.h>
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void bubblesort(int *arr,int size)
{
int pass,j;
for(pass=0;pass<size-1;++pass)
{
for(j=0;j<size-1;++j)
{
if(arr[j]>arr[j+1])
{
swap(&arr[j],&arr[j+1]);
}
}
}
}
void main(){
int arr[10],s=10,i;
printf("enter 10 integers\n");
for(i=0;i<10;i++)
{
scanf("%d",&arr[i]);
}
printf("before sorting\n")
for(i=0;i<10;i++)
{
printf("%d\t",arr[i]);
}
printf("\n");
bubblesort(arr,s);
printf("after sorting\n");
for(i=0;i<10;i++)
{
printf("%d\t",arr[i]);
}
}
