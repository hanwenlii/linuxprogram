#include"my.h"

void * fun(void *arg)
{
	struct sendval * k=(struct sendval *)arg;
	int i=0,sum=0;
	for(i=0;i<k->s;i++)
		sum+=i;
	printf("worker--%d:pthread_self return %p,sum of %d=%d\n",k->n,(void*)pthread_self(),k->s,sum);
	pthread_exit(NULL);
	return NULL;
}
int main()
{
	pthread_t tid[NUM];
	int ret[NUM],t;
	struct sendval d;
	for(t=0;t<NUM;t++)
	{	
		d.n=t;
		d.s=100*(t+1);
		ret[t]=pthread_create(&tid,NULL,fun,(void*)&d);
		if(ret[t]!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
	}
	for(t=0;t<NUM;t++)
		pthread_detach(tid[t]);
	printf("Master %d;All Done\n",getpid());
	sleep(30);
	return 0;
}

