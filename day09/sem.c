#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	//创建一个信号量集
	int id=semget(0x9999,1/*信号量的个数*/,0600|IPC_CREAT);
	int i;
	for (i=0; i<6; i++){
		if (fork()==0){
			struct sembuf ops[1]={
				{.sem_num=0,.sem_op=-1,.sem_flg=SEM_UNDO}
			};
			if (semop(id,ops,1)==0){
				printf("%d进入房间\n",getpid());
				srand(getpid());
				int n=rand()%6+5;
				sleep(n);
				printf("%d退出房间\n",getpid());
				ops[0].sem_op = 1;
				semop(id,ops,1);
			}
			exit(0);
		}
	}
	puts("房间开放,准入4人:");
	semctl(id,0,SETVAL,4);//设置计数器值为4
	while (wait(0)>0);//等待所有子进程结束
	semctl(id,0,IPC_RMID,NULL);
}
