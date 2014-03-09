#include <stdio.h>
#include <unistd.h>

int main()
{
	if (fork()==0){//child process
		printf("child in group:%d\n",getpgrp());
		setsid();//自己建立一个进程组
		puts("after setsid()");
		printf("child in group:%d\n",getpgrp());
		for (;;){
			write(1,".",1);
			sleep(1);
		}
	}
	else{
		printf("parent in group:%d\n",getpgrp());
		for (;;){
			write(1,"$",1);
			sleep(1);
		}
	}
}
