#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1=open("myfile",O_WRONLY|O_CREAT,0666);
	if (fd1<0){
		perror("myfile");
		return 1;
	}
	int fd2=dup(fd1);
	write(fd1,"a",1);
	write(fd2,"b",1);
	close(fd1);
	close(fd2);
	int fd3=open("myfile",O_RDWR);
	if (fd3<0){
		perror("myfile");
		return 1;
	}
	dup2(fd3,1); //把文件描述符复制成1,先关闭标准输出
	char c;
	read(fd3,&c,1);
	write(2,&c,1);//显示到屏幕上
	close(fd3);
	read(1,&c,1);
	write(2,&c,1);//显示到屏幕上
	printf("hello my dear friends\n");
	fflush(stdout);
	close(1);
}
