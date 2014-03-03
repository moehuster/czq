#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd=open("id",O_RDWR|O_CREAT,0600);//打开
	int id=10000;
	read(fd,&id,sizeof(id)); //读取,如果成功,读写位置后移4字节
	printf("id:%d\n",id++);
	lseek(fd,-4,SEEK_CUR); //读写位置倒回到文件开始位置
	write(fd,&id,sizeof(id));//覆盖文件的前4个字节
	lseek(fd,10,SEEK_END); // 产生空洞
	write(fd,"hello",5);
	lseek(fd,4,SEEK_SET);
	write(fd,"xxxx",4);
	close(fd);
}
