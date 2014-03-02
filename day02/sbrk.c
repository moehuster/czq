#include <stdio.h>
#include <unistd.h>

int main()
{
	int* p = sbrk(0);
	printf("%p\n", p);
	//printf("%d\n", *p);段错误
	sbrk(4);//映射后面一页
	*p = 123456789;
	printf("%d\n", *p);
	*(p+10) = 987654321;
	printf("%d\n", *(p+10));
	printf("page:%d\n",getpagesize());
//	*(p+1024) = 1;
//	printf("%d\n", *(p+1024));
	//sbrk(-4);取消后面一页的映射
	brk(p);//与用sbrk(-4)等效
	//printf("%d\n", *p);
}

