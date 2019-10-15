#include"mylib.h"
int max(int *a,int n)
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

int sum(int* a,int n)
{
	int sum=0,i;
	for(i=0;i<n;i ++)
	{
		sum=sum+a[i];	
	}
	return sum;
}
