#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	for (;;){
		write(1,"权",3);
		sleep(1);
	}
}
