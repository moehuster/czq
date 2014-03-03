#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct Person{
	char name[20];
	int age;
	char gender;
	double salary;
}Person;

int main()
{
	Person fr={"芙蓉",18,'F',1234.5};
	Person cg={"春哥",20,'M',5432.1};
	int fd=open("person",O_WRONLY|O_CREAT,0644);
	if (fd<0){
		perror("open");
		return 1;
	}
	write(fd,&fr,sizeof(fr));
	write(fd,&cg,sizeof(cg));
	close(fd);
}
