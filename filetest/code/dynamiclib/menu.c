#include"my.h"

void menu1_1(FILE* fd,char* path,char* buf,int buf_length,int fp)
{
	int choice;
	while(1)
	{
		
		printf("********************************\n");
		printf("1.使用系统IO\n");
		printf("2.使用标准IO\n");
		printf("********************************\n");
		printf("Please input your choice(1/2):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				menu3_1(fp,path,buf,buf_length);
				break;
			case 2:
				menu2_1(fd,path,buf,buf_length);
				break;
		}
	}
}
void menu2_1(FILE* fd,char* path,char* buf,int buf_length)
{
	int choice;
	while(1)
	{
		
		printf("********************************\n");
		printf("0.退出\n");
		printf("1.创建新文件\n");
		printf("2.写文件\n");
		printf("3.读文件\n");
		printf("4.修改文件权限\n");
		printf("5. 查看当前文件的权限修改文件权限\n");
		printf("********************************\n");
		printf("Please input your choice(0-6):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				exit(0);
				break;
			case 1:
				create1_1(fd,path);
				break;
			case 2:
				write1_1(fd,path,buf,buf_length);
				break;
			case 3:
				read1_1(fd,path,buf,buf_length);
				break;
			case 4:
				modify1_1(fd,path);
				break;
			case 5:
				check1_1(fd,path);
				break;
		}
	}
}
void menu3_1(int fp,char* path,char* buf,int buf_length)
{
	int choice;
	while(1)
	{
		
		printf("********************************\n");
		printf("0.退出\n");
		printf("1.创建新文件\n");
		printf("2.写文件\n");
		printf("3.读文件\n");
		printf("4.修改文件权限\n");
		printf("5. 查看当前文件的权限修改文件权限\n");
		printf("********************************\n");
		printf("Please input your choice(0-6):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				exit(0);
				break;
			case 1:
				create2_1(fp,path);
				break;
			case 2:
				write2_1(fp,path,buf,buf_length);
				break;
			case 3:
				read2_1(fp,path,buf,buf_length);
				break;
			case 4:
				modify2_1(fp,path);
				break;
			case 5:
				check2_1(fp,path);
				break;
		}
	}

}
