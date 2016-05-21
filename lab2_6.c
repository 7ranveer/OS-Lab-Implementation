#include<stdio.h>
#include<math.h>
void main()
{
FILE *a, *b;
char inp[100];
a=fopen("myfile.txt", "r");
b=fopen("mydetails.txt", "w");
if(a==NULL||w==NULL)
{
printf("FILE Error!!\n");
}
while(!feof(a))
{
fscanf(a,"%s",inp);
fprintf(b,"myinput:%s\n",inp);
}
}
