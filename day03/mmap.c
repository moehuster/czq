#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	char *p=mmap(NULL,0x100,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	printf("%p\n",p);
	if (p==MAP_FAILED){
		printf("%m");//printf("%s",strerror(errno));
		return -1;
	}
	strcpy(p,"欢迎使用mmap");
	puts(p);
	char *q=mmap((void*)0x9f5a000,0x88,PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	//if (q==MAP_FAILED)
	printf("%p\n",q);
	munmap(p,0x100);
	munmap(q,0x88);
}
