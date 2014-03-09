#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void fun(int sig,siginfo_t* p,void* x)
{
	printf("uid:%d, pid:%d, sig:%s, data:%d, code:%s\n",
		p->si_uid,p->si_pid,strsignal(p->si_signo),p->si_value.sival_int,
		p->si_code==SI_QUEUE?"sigqueue":"other");
}

int main()
{
	struct sigaction sa;
	printf("pid=%d\n",getpid());
	memset(&sa,0,sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = fun;
	sigaction(SIGINT,&sa,NULL);
	sigaction(SIGTERM,&sa,NULL);
	for(;;){
		write(1,"zZ...\n",6);
		sleep(2);
	}
}
