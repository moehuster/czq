#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd=open("letter",O_RDWR);
	if (fd==-1){
		perror("letter");
		return 1;
	}
	printf("my pid=%d\n",getpid());
	printf("打开文件成功,fd=%d\n",fd);
	struct flock f;
	f.l_type = F_WRLCK; //写锁
	f.l_whence = SEEK_SET;
	f.l_start = 0; //相对于文件头偏移量为0的地方开始
	f.l_len = 10; //锁10字节
	f.l_pid = -1; //不需要,兼容性考虑
	if (fcntl(fd,F_SETLK,&f)==-1){
		perror("F_SETLK");
		struct flock k;
		k.l_whence = SEEK_SET;
		k.l_start = 0;
		k.l_len = 10;
		k.l_type= F_WRLCK;
		fcntl(fd,F_GETLK,&k);//取得锁信息
		printf("%d locked it\n",k.l_pid);
		return 0;
	}
	sleep(20);
	f.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&f);
	close(fd);
}
