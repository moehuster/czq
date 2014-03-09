#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	if (fork()==0){
		int id=shmget(0x8888,1000,0600|IPC_CREAT);
		if (id==-1){
			perror("shmget 0x8888");
			return 1;
		}
		char* p=shmat(id,NULL,0); //SHM_RDONLY
		//if (p==(void*)-1) //error
		//flag: *p==0xf4/0x4f 分别表示有数据和没有数据
		while (1){
			if (*p!=(char)0xf4) sleep(1);
			else{
				printf("get data: %s\n",p+1);
				if (!strncmp(p+1,"quit",4)) break;
				*p = 0x4f;
			}
		}
		*p = 0x4f;
		shmdt(p);
	}
	else{
		int id=shmget(0x8888,1000,0600|IPC_CREAT);
		//if (id==-1) // error
		char *p=shmat(id,NULL,0);
		*p = 0x4f;
		for (;;){
			if (*p==0x4f){
				printf("input:");
				scanf(" %[^\n]",p+1);
				*p = 0xf4;
				if (!strncmp(p+1,"quit",4)) break;
			}
			else sleep(1);
		}
		while (*p!=0x4f) sleep(1);//把CPU交给对方,等待对方取数据
		shmdt(p);
		shmctl(id,IPC_RMID,NULL);
	}
}
