#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void fun(int sig)
{
	int state;
	pid_t cid;
	while ((cid=waitpid(-1,&state,WNOHANG))>0)
		printf("子进程%d结束,返回%d\n",cid,WEXITSTATUS(state));
}

int main()
{
	signal(SIGCHLD,fun);
	int i;
	char c='A';
	for (i=0; i<8; i++,c++){ // child process
		if (fork()==0){
			int j;
			for (j=0; j<10; j++){
				write(1,&c,1);
				sleep(1);
			}
			exit(i+10);
		}
	}
	//parent process
	for (;;){
		write(1,".",1);
		sleep(1);
	}
}
