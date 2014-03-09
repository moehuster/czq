#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
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
	char *p=mmap(NULL,s.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	//if (p==MAP_FAILED) ...
	if (fork()==0){
		int i;
		for (i=0; i<3; i++){
			if (islower(p[i])) p[i]=toupper(p[i]);
			else p[i] = tolower(p[i]);
		}
		sleep(5);
	}
	else{
		int i;
		sleep(2);
		printf("%c%c%c\n",p[0],p[1],p[2]);
		for (i=5; i<9; i++){
			if (islower(p[i])) p[i] = toupper(p[i]);
			else p[i] = tolower(p[i]);
		}
	}
	munmap(p,s.st_size);
	close(fd);
}
