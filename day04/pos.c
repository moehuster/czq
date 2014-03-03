#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd=open("letter",O_RDWR);
	if (fd==-1){
		perror("letter");
		return 1;
	}
	char c;
	read(fd,&c,1);
	write(STDOUT_FILENO,&c,1);
	write(fd,"*",1);
	read(fd,&c,1);
	write(STDOUT_FILENO,&c,1);
	write(fd,"*",1);
	close(fd);
}
