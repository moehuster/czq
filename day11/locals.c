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
	if (bind(s,(struct sockaddr*)&su,sizeof(su))<0){
		perror("bind");
		return 1;
	}
	char buf[1024];
	for (;;){
		int n=read(s,buf,sizeof(buf));
		if (n<=0) break;
		printf("n=%d\n",n);
		write(1,buf,n);
		if (!strncmp(buf,"bye\n",4)) break;
	}
	close(s);
	unlink("mysock");
}
