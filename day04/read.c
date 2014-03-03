#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct Person{
	char name[20];
	int age;
	char gender;
	double salary;
}Person;

void show(const Person *p)
{
	printf("我是%s %s,今年%d岁,收入%lg\n",p->name,p->gender=='F'?
			"美女":"帅哥",p->age,p->salary);
}

int main()
{
	Person fr;
	Person cg;
	int fd=open("person",O_RDONLY);
	if (fd<0){
		perror("open");
		return 1;
	}
	read(fd,&fr,sizeof(fr));
	read(fd,&cg,sizeof(cg));
	close(fd);
	show(&fr);
	show(&cg);
}
