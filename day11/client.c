#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
	if (argc!=2){
		printf("%s serverip\n",argv[0]);
		return 0;
	}
	int s=socket(AF_INET,SOCK_STREAM,0);//建立套接字
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	inet_pton(AF_INET,argv[1],&si.sin_addr);
	si.sin_port = htons(8888);
	if (connect(s,(struct sockaddr*)&si,sizeof(si))<0){
		perror("connect");
		return 1;
	}
	char buf[1024];
	for (;;){
		int n=read(s,buf,sizeof(buf));
		if (n<=0) {if (errno!=EINTR) break; else continue;}
		write(1,buf,n); //显示到屏幕上
		write(1,"input:",6);//提示输入
		n=read(0,buf,sizeof(buf));//从键盘读取
		write(s,buf,n);//发送到服务器
	}
	close(s);
}
