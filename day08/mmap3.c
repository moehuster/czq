#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main()
{
	int fd=open("file",O_RDWR);
	if (fd==-1){
		perror("open");
		return 1;
	}
	struct stat s;
	fstat(fd,&s);
	char* p=mmap(NULL,s.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	//if (p==MAP_FAILED)...
	if (fork()==0){
		int i;
		for (i=0; i<3; i++)
			p[i]^=1<<5;
		sleep(5);
	}
	else{
		int i;
		sleep(2);
		printf("%c%c%c\n",p[0],p[1],p[2]);
		for (i=5; i<9; i++)
			p[i]^=1<<5;
	}
	munmap(p,s.st_size);
	close(fd);
}
