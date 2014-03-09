#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int main()
{
	int id=semget(0x9999,0,0);
	struct sembuf op;
	op.sem_num = 0; //数组下标
	op.sem_op = 1;  //操作:对信号量+1
	op.sem_flg= 0;  //默认
	semop(id,&op,1/*1个操作*/);
	printf("释放一个资源成功！\n");
}
