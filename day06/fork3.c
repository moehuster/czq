#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd=open("letter",O_CREAT|O_WRONLY,0644);
	// if(fd<0) ...
	if (fork()>0){//父进程
		char c;
		for (c='a'; c<'z'; c++){
			write(fd,&c,1);
			sleep(1);
		}
		close(fd);
	}
	else {//子进程
		char c;
		for (c='A'; c<='Z'; c++){
			write(fd,&c,1);
			sleep(1);
		}
		close(fd);
	}
}
