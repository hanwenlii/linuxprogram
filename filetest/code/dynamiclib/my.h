#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define BUFSIZE 1024

void menu1_1(FILE*,char*,char*,int,int);
void menu2_1(FILE*,char*,char*,int);
void menu3_1(int,char*,char*,int);

//使用标准IO
void create1_1(FILE*,char*);
void write1_1(FILE*,char*,char*,int);
void read1_1(FILE*,char*,char*,int);
void modify1_1(FILE*,char*);
void check1_1(FILE*,char*);

//使用系统IO
void create2_1(int,char*);
void write2_1(int,char*,char*,int);
void read2_1(int,char*,char*,int);
void modify2_1(int,char*);
void check2_1(int,char*);
