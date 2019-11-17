#include"my.h"
static void fun1(void)
{
	printf("invoked callbackfun!\n");
}
int main()
{
	FILE *fp;
	char buf[]="hello world   ";
	atexit(fun1);
	printf("%s",buf);

	if((fp=fopen("test.txt","w+"))==NULL)
	{
		perror("fail to fopen");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("fail to fputs");
		return -1;
	}

	exit(0);
}
