#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1 = open("furong",O_WRONLY);
	if (fd1==-1)
		perror("furong");
	int fd2 = open("furong",O_WRONLY|O_CREAT,0666);
	if (fd2==-1){
		perror("furong2");
		return 1;
	}
	int fd3 = open("fengjie",O_RDWR|O_EXCL|O_CREAT,0666);
	if (fd3==-1)
		perror("fengjie");
	else
		puts("成功");
	close(fd1);
	close(fd2);
	close(fd3);
	sleep(10);
	unlink("furong");
	unlink("fengjie");
}
