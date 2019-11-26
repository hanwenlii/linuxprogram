#include"my.h"
int main()
{
	int pid,fd[2],len;
	char buf[1024*64];
	FILE *stream;
	if(pipe(fd)!=0)
	{
		fprintf(stderr,"pipe create filed.\n error reason=%s\n",strerror(errno));
		return -1;
	}
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"fork filed.\n error reason=%s\n",strerror(errno));
		return -2;
	}else if(pid==0)
	{
		close(fd[1]);
		fups(fd[0],0);
		close(fd[0]);
		if(excel("/bin/cat","cat",NULL,NULL))
		{
			fprintf(stderr,"excel filed.\n error reason=%s\n",strerror(errno));
			return -3;
		}
		exit(0);
	}else
	{
		close(fd[0]);
		printf("you can type aline and the line will echoed:\n");
		dup2(fd[1],1);
		while(gets(buf)!=NULL)
			puts(buf);
	}
	return 0;
}
