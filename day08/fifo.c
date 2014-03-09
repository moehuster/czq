#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
	umask(0);
	mkfifo("myfifo",0666);
	if(access("myfifo",F_OK|R_OK|W_OK)){
		perror("myfifo");
		return 1;
	}
	int fd=open("myfifo",O_RDONLY);
	puts(fd==-1?"cannot open":"opend");
	char buf[128];
	for(;;){
		int n=read(fd,buf,sizeof(buf));
		if (n<=0) break;
		write(1,buf,n);
		write(1,"\n",1);
		if (n==4&&strncmp(buf,"quit",4)==0) break;
	}
	close(fd);
	unlink("myfifo");
}
