#include <stdio.h>
#include <signal.h>

void fun(int sig)
{
	printf("时间到!\n");
	alarm(2);
}

int main()
{
	signal(SIGALRM,fun);
	alarm(2);
	puts("after alarm");
	while (1){
		write(1,".",1);
		int remain = 10;
		while ((remain=sleep(remain))!=0)
//			printf("remain=%d\n",remain);
	}
}
