#include <stdio.h>
#include <unistd.h>

int main()
{
//	char *argv[]={"pp","hehe",NULL};
//	execv("pp",argv);
	char* argv[]={"ls","-a",NULL};
	execvp("ls",argv);//使用环境变量path
	puts("error");
}
