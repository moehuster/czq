#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>

void fun(int sig)
{
	unlink("a.txt");
	exit(0);
}

int main()
{
	signal(SIGTERM,fun);
	if (fork()>0) return 0;//结束父进程,交换终端给shell
	printf("pid=%d\n",getpid());
	int i;
	for (i=0; i<3; close(i++));
	setsid();//自成一个进程组
	umask(0022);//设置自己的权限屏蔽
	chdir(getenv("HOME"));//重设当前目录
	//精灵进程工作
	char c='A';
	for (;;){
		int fd=open("a.txt",O_CREAT|O_WRONLY,0644);
		if (fd>=0){
			write(fd,&c,1);
			close(fd);
		}
		if (c++=='Z') c='A';
		sleep(1);
	}
}
