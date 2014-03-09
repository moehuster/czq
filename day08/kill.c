#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void fun(int sig)
{
	psignal(sig,"sig");
	printf("%d收到信号%s\n",getpid(),strsignal(sig));
}

int main()
{
	signal(SIGUSR1,fun);
	pid_t pid = getpid();
	printf("parent:%d\n",pid);
	if (fork()==0){//child process
		printf("child:%d\n",getpid());
		kill(pid,SIGUSR1);
		raise(SIGUSR1);
		sleep(4);
	}
	else { //parent process
		sleep(5);
	}
}
