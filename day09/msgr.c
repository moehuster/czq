#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
	int id=msgget(0x8888,0644|IPC_CREAT);
	if (id==-1){perror("msgget");return 1;}
	char buf[128];
	msgrcv(id,buf,sizeof(buf),0,0);
	printf("第一条:"); puts(buf);
	msgrcv(id,buf,sizeof(buf),0,0);
	printf("第二条:"); puts(buf);
	msgctl(id,IPC_RMID,NULL);
}
