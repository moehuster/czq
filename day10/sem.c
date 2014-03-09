#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

typedef struct task{
	char file[20];
	int size;
}task;

sem_t s;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
task jobs[5];
int cnt=0;

void *fun(void* p)//工作线程
{
	for (;;){//无限循环
		int shouldwait=0;
		pthread_mutex_lock(&m);
		if (cnt==0) shouldwait=1;
		if (shouldwait){ //如果没有任务就等待
			pthread_mutex_unlock(&m);
			sem_wait(&s);//等待减1
		}
		else{//如果有任务
			task t=jobs[0];
			--cnt;
			int i;
			pthread_mutex_unlock(&m);
			for (i=0; i<cnt; i++) jobs[i]=jobs[i+1];
			printf("线程%d做任务%s大小%d\n",(int)p,t.file,t.size);
			sleep(t.size/100);
			printf("线程%d完成任务%s大小%d\n",(int)p,t.file,t.size);
		}
	}
}

int main()
{
	sem_init(&s,0/*不在进程间共享*/,0/*计数器值*/);
	int i;
	pthread_t ids[5];
	for (i=0; i<5; i++)
		pthread_create(ids+i,0,fun,(void*)(i+1));
	for (;;){
		if (cnt==5){sleep(1);continue;}
		task t;
//		printf("请输入文件名和大小:");
		if (scanf("%s%d",t.file,&t.size)!=2) break;
		pthread_mutex_lock(&m);
		jobs[cnt++]=t;
		pthread_mutex_unlock(&m);
		sem_post(&s);//计数器加1
	}
}
