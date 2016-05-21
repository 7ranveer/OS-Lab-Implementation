#include<stdio.h>
#include<math.h>
void main()
{
FILE *a, *b;
int points;
char input[100],x,y;
a=fopen("myfile.txt","r");
b=fopen("toupper.txt","w");
if(a==NULL||b==NULL)
{
printf("File Error!!\n");
}
while(!feof(a))
{
x=fgetc(a);
y=toupper(x);
fputc(y,b);
}
fclose(a);
fclose(b);
}
