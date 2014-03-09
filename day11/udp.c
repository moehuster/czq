#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define A(x) (struct sockaddr*)&x

int main(int argc, char* argv[])
{
	if (argc!=2){
		printf("%s port\n",argv[0]);
		return 0;
	}
	int s=socket(AF_INET,SOCK_DGRAM,0);//udp套接字
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_addr.s_addr = INADDR_ANY;
	si.sin_port = htons(atoi(argv[1]));
	bind(s,A(si),sizeof(si));
	char cmd;
	char ip[128];
	short port;
	char msg[1024];
	for (;;){
		printf("input:");
		scanf(" %c",&cmd);
		if (cmd=='q') break;
		if (cmd=='w'){//send
			scanf("%s%hd %[^\n]",ip,&port,msg);
			//si.sin_family = AF_INET;
			inet_pton(AF_INET,ip,&si.sin_addr);
			si.sin_port = htons(port);
			sendto(s,msg,strlen(msg),0,A(si),sizeof(si));
		}
		else if (cmd=='r'){
			socklen_t len = sizeof(si);
			int n;
			n=recvfrom(s,msg,sizeof(msg)-1,MSG_DONTWAIT,A(si),&len);
			if (n<0) puts("no message");
			else{
				msg[n]='\0';
				printf("%s:%d %s\n",inet_ntop(AF_INET,&si.sin_addr,ip,
					sizeof(ip)),ntohs(si.sin_port),msg);
			}
		}
		else{
		//无效命令
		}
	}
	close(s);
}
