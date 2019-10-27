#include"my.h"

void create1_1(FILE* fd,char* path)
{
	fd=fopen(path,"w+");
	if(fd==NULL)
	{
	  perror("test.txt创建失败");       //必须处理打开流的错误情况
	  exit(0);
	}
    printf("创建文件：%s\n",path);
	fclose(fd);
}
void write1_1(FILE* fd,char* path,char* buf,int buf_length)
{
	fd=fopen(path,"w+");
	printf("输入文件内容：");
	scanf("%s",buf);
	if(fwrite(buf,sizeof(char),sizeof(buf),fd)==sizeof(buf))
	{	
		printf("写文件成功！\n");
		fclose(fd);
	}
	else
	{	
		printf("写文件失败！\n");
		fclose(fd);
	}
}
void read1_1(FILE* fd,char* path,char* buf1,int buf_length)
{
	fd=fopen(path,"r");
	if(fread(buf1,sizeof(char),sizeof(buf1),fd)==sizeof(buf1))
	{
		printf("写入到test.txt文件中的内容是:%s\n",buf1);
		fclose(fd);
	}
	else
	{	
		printf("读取文件失败！\n");
		fclose(fd);
	}
}
void modify1_1(FILE* fd,char* path)
{
	char buf[128];
	int mode;
	printf("请输入文件权限（0-777）:");
	scanf("%s",buf);
	mode=(atoi(buf));
	if(mode>777||mode<0){
		perror("模式错误");
	}
	if(chmod(path,mode)==-1){
		perror("Error mode\n");
	}
	printf("修改文件权限成功\n");
}
void check1_1(FILE* fd,char* path)
{
	system("ls -al ./test.txt");
	
}
