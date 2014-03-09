#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <ctype.h>

#define PORT 8888
#define A(x) (struct sockaddr*)(&x)

void* fun(void *p)
{
	int c = (int)p;//套接字
	char buf[1024];
	for (;;){
		int n=read(c,buf,sizeof(buf)-1);
		if (n<=0) break;//出错或者关闭就退出
		buf[n]='\0';
		if (!strcmp(buf,"bye\n")||!strcmp(buf,"bye\r\n"))break;
		int i;
		write(1,buf,n);//在屏幕上显示
		for (i=0; i<n; i++) buf[i]=toupper(buf[i]);
		write(c,buf,n);//发送到客户端
	}
	close(c);
	return 0;
}

int main()
{
	int s=socket(AF_INET,SOCK_STREAM,0);//建立套接字
	struct sockaddr_in si;
	si.sin_family = AF_INET;//跟前面一致
	si.sin_addr.s_addr = INADDR_ANY;//本机的任何ip
	si.sin_port = htons(PORT);
	if (bind(s,A(si),sizeof(si))<0){
		perror("bind");
		exit(1);
	}
	listen(s,5);
	for (;;){
		socklen_t len = sizeof(si);
		int c = accept(s,A(si),&len);//等待客户端连接
		if (c<0) continue; //成功就返回套接字
		char buf[128],ip[100];
		inet_ntop(si.sin_family,&si.sin_addr,ip,sizeof(ip));
		printf("%s到此一游\n",ip);
		sprintf(buf,"welcom friend from <%s,%d>\n",ip,ntohs(si.sin_port));
		write(c,buf,strlen(buf));
		pthread_t id;
		pthread_create(&id,NULL,fun,(void*)c);
		pthread_detach(id);
//		close(c);
	}
	return 0;
}
