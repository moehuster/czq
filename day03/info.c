#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>

int main()
{
	if (access(__FILE__,F_OK)) //检查文件或者目录是否存在
		puts("不存在"__FILE__);
	else
		puts(__FILE__"存在");
	if (access("/etc/shadow",R_OK))
		puts("/etc/shadow不可读");
	if (access("main",R_OK|X_OK)==0)
		puts("对main有读和执行权限");
	struct stat s;
	if (lstat("furong",&s)==-1)
		perror("lstat furong");
	if (lstat(__FILE__,&s)==-1)
		perror(__FILE__);
	printf("mode:0%o\nsize:%d\nuser:%d\nmtime:%d\n",
			s.st_mode,s.st_size,s.st_uid,s.st_mtime);
	printf("类型:%s\n",S_ISREG(s.st_mode)?"文件":
			S_ISDIR(s.st_mode)?"目录":"其他");
	printf("权限:0%o\n",s.st_mode & 0777);
	printf("所有者:%s\n",getpwuid(s.st_uid)->pw_name);
	struct tm* p = localtime(&s.st_mtime);
	printf("最后修改时间:%d-%02d-%02d %02d:%02d:%02d\n",
			p->tm_year+1900,p->tm_mon+1,p->tm_mday,p->tm_hour,
			p->tm_min,p->tm_sec);
	char buf[200];
	strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",p);
	puts(buf);
}
