#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if (fork()==0){
		printf("myid=%d, my parent:%d",getpid(),getppid());
		return 0;
	}
	pause();
}
