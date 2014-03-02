#include <stdio.h>
//#include <stdlib.h>
extern char** environ;
int main(int argc, char*argv[], char* env[])
{
	int i=0;
	while(env[i])
		puts(env[i++]);
//	i=0;
//	while(environ[i])
//		puts(environ[i++]);
}
