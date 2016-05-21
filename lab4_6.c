#include <stdio.h>
#include <signal.h>
void hello()
{
	//if(a==SIGINT)
	//{
		printf("signal received\n");
	/*}
	else
	{
		printf("not received");
	}*/
}
void main ()
{
		signal(SIGINT,hello);
		while(1);

}
