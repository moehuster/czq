#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void f1(void){puts("calling f1()");}
void f2(void){puts("calling f2()");}
int main()
{
	puts("begin======");
	atexit(f1);
	atexit(f2);
	puts("in main...");
	fork();
	return 0;
}
