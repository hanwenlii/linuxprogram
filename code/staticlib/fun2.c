#include"my.h"

int max(int* a,int n)
{
	int i,j;
	int temp=0;
	for(i=0;i<n;i++)
	{
		if(temp < a[i])
		{
			temp=a[i];
		}
	}
	return temp;
}
