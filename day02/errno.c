#include <stdio.h>
#include <errno.h>
#include <string.h>
//extern int errno;
int main()
{
	FILE* fp = fopen("furong","r");
	if(fp==NULL){
		printf("%d-->%m\n",errno);
		printf("%s\n",strerror(errno));
		perror("fopen出错了");
	}
	fp = fopen(__FILE__,"r");
	//if(fp==NULL){}...
	char buf[1000];
	fgets(buf,sizeof(buf),fp);
	printf("%s",buf);
	printf("没出错时的%d-->%m\n",errno);
	fclose(fp);
}
