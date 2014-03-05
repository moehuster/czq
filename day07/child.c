#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	if (fork()!=0){
		printf("父进程id:%d\n",getpid());
		sleep(5);
		printf("父进程结束\n");
		exit(0);
	}
	int i;
	for (i=0; i<10; i++){
		printf("myid=%d, my parent:%d\n",getpid(),getppid());
		sleep(1);
	}
}
