#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
	char cmd[1024];
	puts("欢迎使用MyShell!");
	for(;;){
		printf("ms>");
		scanf(" %[^\n]",cmd);
		if (!strcmp(cmd,"furong"))
			break;
		if (!strncmp(cmd,"cd ",3))
			chdir(cmd+3);
		else
			system(cmd);
	}
	puts("谢谢!");
}
