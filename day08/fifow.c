#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	umask(0);
	mkfifo("myfifo",0666);
	if (access("myfifo",F_OK|R_OK|W_OK)){
		perror("myfifo");
		return 1;
	}
	int fd=open("myfifo",O_WRONLY);
	puts(fd==-1?"cannot open":"opened");
	char buf[128];
	for (;;){
		printf("input:");
		scanf(" %[^\n]",buf);
		write(fd,buf,strlen(buf));
		if (!strcmp(buf,"quit")) break;
	}
	close(fd);
	unlink("myfifo");
}
