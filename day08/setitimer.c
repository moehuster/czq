#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void fun(int sig)
{
	puts("时间到!");
}

int main()
{
	signal(SIGALRM,fun);
	struct itimerval iv;
	iv.it_value.tv_sec = 3;
	iv.it_value.tv_usec = 0;
	iv.it_interval.tv_sec = 1;
	iv.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL,&iv,NULL);
	while (1);
}
