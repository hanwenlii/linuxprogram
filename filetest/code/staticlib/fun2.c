#include"my.h"

void create2_1(int fd,char* path)
{
	//以可读可写方式打开文件
    if ( (fd = open(path,O_RDWR|O_CREAT,0700)) < 0){
        perror("打开失败\n");
         exit(0);
    }
    printf("创建文件：%s\n",path);
	close(fd);
}
void write2_1(int fd,char* path,char* buf,int buf_length)
{
	fd = open(path,O_RDWR|O_CREAT,0700);
	printf("请输入要写入文件的字符串：");
    scanf("%s",buf);
    //从fd中输入buff的内容
    buf_length = sizeof(buf);
    if(  write(fd,buf,buf_length) < 0)
	{
        perror("写入文件失败");
        exit(1);
    }
    printf("写入成功\n");
	close(fd);
}
void read2_1(int fd,char* path,char* buf1,int buf_length)
{
	fd = open(path,O_RDWR|O_CREAT,0700);
	buf1[0]='\0';//将buf1清空
    lseek(fd,0,SEEK_SET);//定位到文件开头
    if( read(fd,buf1,BUFSIZE) < 0 ){
        perror("读取失败\n");
        exit(0);
    }
    printf("读取数据：%s\n",buf1);
	close(fd);
}
void modify2_1(int fd,char* path)
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
void check2_1(int fd,char* path)
{
	system("ls -al ./test.txt");
	
}
