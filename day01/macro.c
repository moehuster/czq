#include <stdio.h>

int main()
{//_cplusplus
	puts(__DATE__);
	puts(__TIME__);
	puts(__FILE__);
	puts(__func__);
	printf("%d\n", __LINE__);
	return 0;
}

