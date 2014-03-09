#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){
	psignal(sig,"SIGINT");
}

int main()
{
	sigset_t new,old,wait;
	struct sigaction act;
	printf("pid=%d\n",getpid());
	memset(&act,0,sizeof(act));
	act.sa_handler = handler;
	sigaction(SIGINT,&act,0);
	sigaction(SIGQUIT,&act,0);
	sigemptyset(&new);
	sigemptyset(&wait);
	sigaddset(&wait,SIGQUIT);
	sigaddset(&new,SIGINT);
	sigprocmask(SIG_BLOCK,&new,&old);//阻塞SIGINT信号
	if (sigsuspend(&wait)!=-1)
		perror("sigsuspend");
	puts("After sigsuspend");
	sigprocmask(SIG_SETMASK,&old,NULL);//取消阻塞
	for (;;){
		write(1,"zZ...\n",6);
		sleep(2);
	}
}
