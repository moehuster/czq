#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* p = getenv("JAVA_HOME");
	if(p)
		puts(p);
	setenv("cpp","chenzongquan",1);
	p = getenv("cpp");
	if(p)
		puts(p);
}
