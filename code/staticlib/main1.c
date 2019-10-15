#include"my.h"
int main()
{
	int a[UNUMBER];
	randinit(a,UNUMBER);
	printf("max=%d",max(a,UNUMBER));
	return 0;
}
