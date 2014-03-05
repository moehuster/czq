#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	//open id file
	int fd=open("id",O_RDONLY);
	if (fd==-1) return 0;
	//repeat until reach the end of the file:
	char cmd[100];
	pid_t id;
	while (read(fd,&id,sizeof(id))==sizeof(id)){
		// read an id from file
		// create command string like "kill <id>"
		sprintf(cmd,"kill %d",id);
		// call system to execute command
		system(cmd);
	}
	close(fd);
	//remove the file
	unlink("id");
}
