#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct Node{
	char c;
	struct Node* next;
}Node;

Node* head=NULL;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;

void printlist()
{
	Node* p = head;
	while (p){
		write(1,&p->c,1);
		p = p->next;
	}
	putchar('\n');
}

void* f1(void* p)
{
	char i;
	for (i='A'; i<='Z'; i++){
		Node* q = malloc(sizeof(Node));//if(q==NULL)...
		q->c = i;
		q->next = head;
		pthread_mutex_lock(&m);
		usleep(100000);
		head = q;
		printlist();
		pthread_mutex_unlock(&m);
	}
}

void* f2(void* p)
{
	char i;
	for (i='a'; i<='z'; i++){
		Node* q = malloc(sizeof(Node));//if(q==NULL)...
		q->c = i;
		pthread_mutex_lock(&m);
		q->next = head;
		usleep(90000);
		head = q;
		printlist();
		pthread_mutex_unlock(&m);
	}
}

int main()
{
	pthread_t ids[2];
	pthread_create(ids,NULL,f1,NULL);
	sleep(1);
	pthread_create(ids+1,NULL,f2,NULL);
//	pthread_join(ids[0],NULL);
//	pthread_join(ids[1],NULL);//等待两个线程跑完
	pthread_exit(NULL);
//	printlist();
//	free();
}
