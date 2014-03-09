#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct Person{
	long no;//通道号
	char name[20];
	char gender;
	int age;
}Person;

int main()
{
	int id=msgget(0x9999,0666|IPC_CREAT);
	if (id==-1){
		perror("msgget");
		return 1;
	}
	Person p;
	for (;;){
		printf("请输入通道号,姓名,性别和年龄:");
		scanf("%ld",&p.no);
		if (p.no<=0) break;
		scanf("%s %c%d",p.name,&p.gender,&p.age);
		msgsnd(id,&p,sizeof(p),0);
	}
	msgctl(id,IPC_RMID,NULL);
}
