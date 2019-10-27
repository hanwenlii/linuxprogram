#include"my.h"
int main()
{
	FILE* fd;
	int fp;
	char* path="./test.txt";
	char buf[BUFSIZE];
	int buf_length;
	menu1_1(fd,path,buf,buf_length,fp);
	return 0;
}
