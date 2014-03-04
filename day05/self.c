#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("我的id: %d\n",getuid());
	printf("我的有效id: %d\n",geteuid());
	printf("我的进程id: %d\n",getpid());
	printf("我的父进程id: %d\n",getppid());
}
