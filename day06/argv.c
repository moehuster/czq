#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc!=2){
		printf("%s 要打印的字符串\n",argv[0]);
		return 0;
	}
	for (;;){
		write(1,argv[1],strlen(argv[1]));
		sleep(1);
	}
}
