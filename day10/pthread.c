#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *f1(void* p)
{
	int i;
	printf("mytid=%u\n",pthread_self());
	for (i=0; i<10; i++){
		write(1,".",1);
		sleep(1);
	}
	return (void*)123;//c++ reinterpret_cast
}

void *f2(void* p)
{
	int i;
	printf("mytid=%u\n",pthread_self());
	for (i=0; i<5; i++){
		write(1,"*",1);
		sleep(1);
	}
	pthread_exit("Hello");
	puts("you cannot see me");
}

void* f3(void* p)
{
	int i;
	printf("mytid=%u\n",pthread_self());
	for (i=0;;i++){
		write(1,"$",1);
		sleep(1);
	}
	return (void*)456;
}

int main()
{
	pthread_t ids[3];
	pthread_create(ids+0,NULL,f1,NULL);
	pthread_create(ids+1,NULL,f2,NULL);
	pthread_create(ids+2,NULL,f3,NULL);
	sleep(3);
	pthread_cancel(ids[2]);
	void* ret;
	pthread_join(ids[0],&ret);
	printf("线程%u返回%d\n",ids[0],(int)ret);
	pthread_join(ids[1],&ret);
	printf("线程%u返回%s\n",ids[1],(char*)ret);
	pthread_join(ids[2],&ret);
	printf("线程%u返回%p\n",ids[2],ret);
}
