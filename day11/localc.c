#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>

int main()
{
	int s=socket(AF_LOCAL,SOCK_DGRAM,0);
	struct sockaddr_un su;
	su.sun_family = AF_LOCAL;
	strcpy(su.sun_path,"mysock");
	if (connect(s,(struct sockaddr*)&su,sizeof(su))<0){
		perror("connect");
		return 1;
	}
	char buf[1024];
	for (;;){
		write(1,"input:",6);
		int n=read(0,buf,sizeof(buf));
		write(s,buf,n);
		if (!strncmp(buf,"bye\n",4)) break;
	}
	close(s);
//	unlink("mysock");
}
