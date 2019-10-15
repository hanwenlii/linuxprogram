#include "/home/han/Desktop/exam1/dynamiclib/mylib.h"
#include<dlfcn.h>
int main()
{
	int a[5]={12,4346,-999,45,32};
	void *handle;
	int(*f1)();
	int(*f2)();
	int(*f3)();
	char *error;
	handle=dlopen("/home/han/Desktop/exam1/dynamiclib/libdynamiclib.so",RTLD_LAZY);
	if(!handle)
	{
		perror("load failed!");
		exit(1);
	}
	f1=dlsym(handle,"show");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f2=dlsym(handle,"max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f3=dlsym(handle,"sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f1(a,5);
	printf("maxdlc=%d\n",f2(a,5));
	printf("sum=%d\n",f3(a,5));
	if(dlclose(handle)<0)
	{
		fprintf(stderr,"%s\n",error);
		exit(1);
	}	
	return 0;
}
