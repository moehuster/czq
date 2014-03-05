#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char *exe[]={"陈","宗","权"};
	char*argv[]={"",NULL};
	int i;
	pid_t cid;
	int fd=open("id",O_WRONLY|O_APPEND|O_CREAT,0600);
//	if (fd==-1) ...
	for (i=0; i<3; i++){
		if ((cid=vfork())==0){//子进程
//			argv[0]=exe[i];
			execl("pp","pp",exe[i],NULL);
			_exit(1);//return 1;
		}
		else{
			write(fd,&cid,sizeof(cid));
		}
	}
	close(fd);
	//父进程执行到这里来
	puts("hello");
}
