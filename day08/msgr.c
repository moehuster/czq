#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct Peron{
	long no; //通道号
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
	int n;
	Person p;
	for (;;){
		printf("请输入通道号:");
		scanf("%ld",&p.no);
		n=msgrcv(id,&p,sizeof(p),p.no,IPC_NOWAIT);
		if (n<=0) puts("没有数据");
		else {
			printf("通道:%ld,姓名:%s,性别:%c,年龄:%d\n",
				p.no,p.name,p.gender,p.age);
		}
	}
}
