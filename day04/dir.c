#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	char *path;
	path=argc==1?".":argv[1];
	DIR* p=opendir(path);
	if (p==NULL){
		perror("opendir");
		return 1;
	}
	char buf[1024],cmd[1024];
	struct stat s;
	struct dirent* q;
	while ((q=readdir(p))!=NULL){
		if (q->d_name[0]=='.')//跳过隐藏文件
			continue;
		strcat(strcat(strcpy(buf,path),"/"),q->d_name);
//		strcat(buf,"/");
//		strcat(buf,q->d_name);
		printf("%s ",buf);
		lstat(buf,&s);
		if (S_ISDIR(s.st_mode)) puts("是目录");
		else{
			puts("是文件");
			strcat(strcpy(cmd,"head "),buf);
			system(cmd);
		}
	}
	puts("");
	closedir(p);
}
