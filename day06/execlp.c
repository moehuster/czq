#include <stdio.h>
#include <unistd.h>

int main()
{
//	char *argv[]={"pp","hehe",NULL};
	execlp("cal","cal","12","2012",NULL);
	puts("error");
}
