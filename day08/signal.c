#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fun(int sig)
{
	if (sig==SIGINT)
		puts("我不怕Ctrl+C");
	else if (sig==SIGTERM)
		puts("不带这样暗杀的");
	else if (sig==SIGTSTP)
		puts("不挂起");
	else
		puts("impossible");
}

int main()
{
	printf("大家好,我叫坚强\n");
	printf("pid=%d\n",getpid());
	signal(SIGINT,fun);
	signal(SIGTERM,fun);
	signal(SIGTSTP,fun);
	for (;;){
		write(1,"z",1);
		sleep(3);
	}
}
