#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int main()
{
	int id=semget(0x9999,1,IPC_CREAT|IPC_EXCL|0600);
	if (id==-1){perror("semget");return 1;}
	// 初始化信号量集
	semctl(id,0,SETVAL,5);
	// 访问资源之前将信号量-1
	int res = 10;
	for (;res;){
		printf("访问资源%d\n",res);
		struct sembuf op;
		op.sem_num = 0; //数组下标
		op.sem_op = -1; //操作:对信号量-1
		op.sem_flg= 0;  //默认
		semop(id,&op,1/*1个操作*/);
		printf("请求访问资源%d成功\n",res);
		res--; // 访问资源
	}
	semctl(id,0,IPC_RMID,NULL);
}
