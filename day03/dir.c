#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	umask(0022);
	if (mkdir("dira",0777)==0)//因为屏蔽，实际是0755
		puts("创建dira成功");
	scanf("%*c"); // 等待按回车键
	umask(0700);
	if (!mkdir("dirb",0777))//因为屏蔽，实际是0077
		puts("创建dirb成功");
	scanf("*[^\n]");
	if (!chmod("dirb",0755)) // rwxr-xr-x
		puts("修改权限成功");
	scanf("%*c");
	rename("dira","dirb/abc");//移动dira到dirb目录下并改名为abc
	if (chdir("dira")) puts("进入dira失败");
	if (!chdir("dirb")) puts("进入dirb成功");
	char dir[200];
	if (getcwd(dir,sizeof(dir))!=NULL)//取得当前工作目录
		puts(dir);
	chdir("..");
	if (rmdir("dirb")) puts("删除dirb失败");
	rmdir("dirb/abc");
	if (!rmdir("dirb")) puts("删除dirb成功");
}

