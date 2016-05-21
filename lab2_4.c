#include<stdio.h>
#include<math.h>
#include<string.h>
void main(){
char input[50];
printf("enter the string\n");
gets(input);
int length=strlen(input),i,a=0,b=0,c=0;
for( i=0;i<len;i++)
{
if(*(input+i) == ' ')
{a++;}
else if(isdigit(*(input+i)))
{b++;}
else  if(isalpha(*(input+i)))
{c++;}
}
printf("number of whitespace:%d\nnumber of digits:%d\nnumber of alphabet%d\n",a,b,c);
fflush(stdin);
}
