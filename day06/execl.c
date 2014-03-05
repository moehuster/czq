#include <stdio.h>
#include <unistd.h>

int main()
{
	execl("pp","pp","hehe",NULL);
	puts("error");
}
