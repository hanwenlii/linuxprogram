#include"my.h"
int main()
{
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	r=fork();
	if(r<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(r==0)
	{
		close(pipefd[0]);
		for(int i=0;i<65537;i++)
		{
			if(write(pipefd[1],"1",1)!=-1)
			{
				printf("child write %d ok .\n",i);
			}
		}
		close(pipefd[1]);
		exit(0);
	}
	else
	{
		wait(NULL);
		close(pipefd[1]);
		if((r_num=read(pipefd[0],buf,100))>0)
		{
			printf("parent read from pipe:%s,total=%d\n",buf,r_num);
		}
		close(pipefd[0]);
		return 0;
	}
	return 0;
}
