#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
	//共享方式映射,不适用文件
	char *p=mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,-1,0);
	if (p==MAP_FAILED){
		perror("mmap");
		return 1;
	}
	if (fork()==0){
		strcpy(p,"Hello,芙蓉");
		sleep(5);
	}
	else{
		sleep(2);
		puts(p);
	}
	munmap(p,20);
}
