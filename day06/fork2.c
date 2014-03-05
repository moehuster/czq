#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t oid=getpid();
	fork();
	pid_t nid=getpid();
	if (oid==nid){ //父进程(旧jincheng)
		int i;
		for (i=0; i<10; i++){
			write(1,"*",1);
			sleep(1);
		}
	}
	else {//子进程(新进程)
		int i;
		for (i=0; i<20; i++){
			write(1,"#",1);
			sleep(1);
		}
	}
}
