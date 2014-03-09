#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
	int id=msgget(0x8888,0644|IPC_CREAT);
	if (id==-1){perror("msgget");return 1;}
	msgsnd(id,"hello, everyone!",17,0);
	msgsnd(id,"good morning, csd1208!",23,0);
}
