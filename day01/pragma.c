#include <stdio.h>
#pragma pack(1)
typedef struct Person{
	char name[17];
	int age;
	char gender;
} Person;
int main()
{
	printf("%d\n", sizeof(Person));
	return 0;
}
