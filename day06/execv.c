#include <stdio.h>
#include <stdlib.h>

int main()
{
	puts("begin==========");
	char* argv[]={"/usr/bin/cal","8","2012",NULL};
	if (fork()==0)//子进程
		execv("/usr/bin/cal",argv);//覆盖当前进程全部代码
	else//父进程
		puts("end==========");//(没)有机会执行
}
