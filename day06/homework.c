#include <stdio.h>
#include <unistd.h>

int main()
{
	char *exe[]={"aa","bb","cc"};
	char *argv[]={"",NULL};
	int i;
	for (i=0; i<3; i++){
		if (vfork()==0){//子进程
			argv[0] = exe[i];
			execv(exe[i],argv);
			_exit(1); return 1;
		}
	}
	//父进程执行到这里来
	puts("hello");
}
