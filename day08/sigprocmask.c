#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void fun(int sig)
{
	psignal(sig,"收到信号");
}

int main()
{
	signal(SIGINT,fun);
	signal(SIGTERM,fun);
	printf("pid=%d\n",getpid());
	sigset_t ss,oss,temp;
	sigemptyset(&ss);
	sigaddset(&ss,SIGINT);
	sigaddset(&ss,SIGTERM);
	sigprocmask(SIG_BLOCK,&ss,&oss);
	sleep(10);
	puts("zZ...");
	sigpending(&temp);
	if (sigismember(&temp,SIGINT))puts("SIGINT来过");
	if (sigismember(&temp,SIGTERM))puts("SIGTERM来过");
	sigprocmask(SIG_UNBLOCK,&ss,NULL);
	puts("hello");
	sleep(5);
}
