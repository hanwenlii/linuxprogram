#include"my.h"
int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("/home/han/Desktop/week9/test1");
	printf("after calling");
	sleep(100);
	return 0;
}
