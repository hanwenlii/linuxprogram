#include"my.h"
int main()
{
	int ret;
	printf("caller2:pid=%d,ppid=%d\n",getpid(),getppid());
	//execl("/home/han/Desktop/week9/test2","./test2","123","456",NULL);
	char* arg[]={"./test2","123","456",NULL};
	execv("/home/han/Desktop/week9/test2",arg);
	printf("after calling");
	sleep(100);
	return 0;
}
