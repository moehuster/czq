#include <stdio.h>
#include "dll.h"
#include <dlfcn.h>

int main()
{
	void* handle = dlopen("./libmax.so",RTLD_NOW);
	if(handle==NULL){
		puts(dlerror());
		return 1;
	}
	double* pv = dlsym(handle, "v");
	int(*pf)(int[],int) = dlsym(handle, "max");
	printf("%lg\n", *pv);
	int x[]={3,9,2,6,8,5};
	printf("%d\n", pf(x,6));
	dlclose(handle);
}
