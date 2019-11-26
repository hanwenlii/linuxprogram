#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid1,pid2;
	char *buf1;
	char buf2[10]="\0";
	char *b=(char *)malloc(sizeof(char)*14);
	int status;

	FILE *f;
	//pid=fork();//先fork后Open文件文件为不共享文件
	if((f=fopen("user.dat","w+"))==NULL)
	{
		perror("Open failed\n");
		exit(1);
	}
	pid1=fork();//先Open文件后fork文件为共享文件
	pid2=fork();//先Open文件后fork文件为共享文件
	if(pid1<0 || pid2<0)
	{
		perror("fork error!\n");
		exit(0);	
	}
	else if(pid1==0)
	{
		printf("child1 pid=%d ppid=%d :f=%p\n",getpid(),getppid(),f);
		for(int i=0;i<10;i++)
		{
			
			fputs(pid,f);
			fputs(i,f);
		}
		
		
		fseek(f,0L,SEEK_SET);
		while(fgets(b,14,f)!=NULL)
			fputs(b,stdout);
		putchar('\n');
		
		free(b);
		exit(0);
	}
	if(pid1&&pid2){
    	waitpid(, &status, 0);
	}else{
		system("vi temp.txt");
		exit(0);
	}
	fclose(f);
	return 0;
}
