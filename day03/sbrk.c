#include <stdio.h>
#include <unistd.h>

int main()
{
	int d;
	char* p = sbrk(4);
	printf("%p\n", p);
	p = sbrk(4);
	printf("%p\n", p);
	scanf("%d", &d);
	printf("d=%d\n", d);
	p = sbrk(4);
	printf("%p\n", p);
	p = sbrk(4);
	printf("%p\n", p);
}
