#include<stdio.h>
#include<math.h>
void main()
{
FILE *a,*b;
char inp[100],c;
a=fopen("myData.txt", "r");
b=fopen("consonant.txt", "w");
if(a==NULL||b==NULL)
{
printf("Error!!\n");
}
while(!feof(a))
{
c=fgetc(a);
if(c!='a'&& c!='e' && c!='i'&& c!='o'&& c!='u' && c!='A'&& c!='E'&& c!='I'&& c!='O'&& c!='U')
	fputc(c,b);
}
fclose(a);
fclose(b);
	
}
