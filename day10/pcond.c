#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct node{
	char c;
	struct node* next;
}node;

node* head=NULL;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c=PTHREAD_COND_INITIALIZER;

void* printlist(void* q)
{
	for (;;){
		pthread_mutex_lock(&m);//给互斥量加锁
		pthread_cond_wait(&c,&m);//解锁m,等待条件,加锁m;
		node* p;
		while (head!=NULL){//操作链表
			write(1,&head->c,1);
			p = head;
			head = head->next;
			free(p);
		}
		pthread_mutex_unlock(&m);//解锁m
	}
}

void* f1(void* p)//添加节点线程
{
	char i;
	for (i='A'; i<='Z'; i++){
		node*q = malloc(sizeof(node));//if(q==NULL)...
		q->c = i;
		pthread_mutex_lock(&m);//插入链表前先加锁
		q->next = head;
		usleep(100000);
		head = q;
		pthread_mutex_unlock(&m);//插入后解锁
		pthread_cond_signal(&c);//发条件信息唤醒打印线程
		usleep(100000);//让系统有更多机会切换到另一个线程
	}
}

void* f2(void* p)
{
	char i;
	for (i='a'; i<='z'; i++){
		node* q = malloc(sizeof(node));//if(q==NULL)...
		q->c = i;
		pthread_mutex_lock(&m);
		q->next = head;
		usleep(90000);
		head = q;
		pthread_mutex_unlock(&m);
		pthread_cond_signal(&c);
		usleep(90000);
	}
}

int main()
{
	pthread_t ids[3];
	pthread_create(ids+2,NULL,printlist,NULL);
	pthread_create(ids+0,NULL,f1,NULL);
	pthread_create(ids+1,NULL,f2,NULL);
	pthread_join(ids[0],NULL);
	pthread_join(ids[1],NULL);
	sleep(1);
	pthread_cancel(ids[2]);//终止printlist线程
	// free();
}
