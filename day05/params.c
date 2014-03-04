#include <stdio.h>

int func()//参数表为表示可以有任意多个参数
{}
int a(int x, int y){return x+y;}
int b(int n){return n*n;}
int main()
{
	int (*fp[2])()={a,b};
	func();
	func(1);
	func(1,"2");
	printf("%d\n",fp[0](3,5));
	printf("%d\n",fp[1](6));
}
