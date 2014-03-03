#include <stdio.h>
#include <unistd.h>

int main()
{
	symlink(__FILE__,"mylink");
	char buf[100];
	int n=readlink("mylink",buf,sizeof(buf));
	write(STDOUT_FILENO,buf,n);
	puts("");
}
