#include <stdio.h>

int sum=0;
int main()
{
	int d;
	printf("sum at %p\n", &sum);
	for(;;){
		printf("input:");
		scanf("%d", &d);
		sum += d;
		printf("sum=%d,at %p\n",sum,&sum);
	}
}
