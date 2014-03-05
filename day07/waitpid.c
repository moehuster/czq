#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int i;
	if (fork()==0){//the first child process
		printf("first child:%d\n",getpid());
		for (i=0; i<20; i++){
			write(1,".",1);
			sleep(1);
		}
		return 5;
	}
	if (fork()==0){//the second child process
		printf("second child:%d\n",getpid());
		for (i=0; i<15; i++){
			write(1,"*",1);
			sleep(1);
		}
		exit(8);
	}
	//parent process
	for (i=0;;i++){
		pid_t cid;
		int state;
		cid=waitpid(-1,&state,WNOHANG);
		if (cid==-1) break; //无子进程
		if (cid!=0){//有子进程结束
			if(WIFEXITED(state)){
				printf("%d正常结束,返回值:%d\n",cid,WEXITSTATUS(state));
			}
			else if (WIFSIGNALED(state)){
				printf("%d被信号%d终止\n",cid,WTERMSIG(state));
			}
		}
		else{
//			puts("无子进程结束");
		}
		write(1,"#",1);
		sleep(1);
	}
	puts("子进程全部终止");
}
