#include<stdio.h>
#include<math.h>
#include<string.h>
void main(){
int length,i,j,forward,backward;
char inp[100],*a;
printf("enter a string\n");
gets(inp);
a=inp;
*(a+strlen(inp))='\0';
length=strlen(inp);
backward=length-1;
for(i=length-1;i>=0;i--)
{
if(inp[i]==32||i==0)
{
if(i==0)
{forward=0;}
else
{forward=i+1;}
for(j=forward;j<=backward;j++)
{
printf("%c",inp[j]);
}
}
backward=i-1;
printf(" ");
}
}

