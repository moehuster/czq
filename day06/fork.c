#include <stdio.h>
#include <unistd.h>

int main()
{
	puts("Hello"); //只有一份进程
	printf("world "); //数据在缓冲区中
	int oldpid=getpid();
	sleep(5);
	fork();//复制进程,缓冲区也会被复制
	puts("csd1208");//已经是两份进程了
	int pid=getpid();
	printf("oldpid=%d, pid=%d\n",oldpid,pid);
	return 0;
}
