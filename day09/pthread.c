#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

typedef struct {
	char c;
	int rep;
}Job;

void* fun(void *p)
{
	Job* q = p;
	int i;
	for (i=0; i<q->rep; i++){
		write(1,&q->c,1);
		sleep(1);
	}
	return p;
}

int main()
{
	Job a[3]={{'a',10},{'b',20},{'c',15}};
	pthread_t ids[3];
	int i;
	for (i=0; i<3; i++)
		pthread_create(&ids[i],NULL,fun,&a[i]);
	for (i=0; i<3; i++)
		pthread_join(ids[i],NULL);
	printf("OK\n");
	return 0;
}
