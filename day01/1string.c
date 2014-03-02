#include <string.h>
#include <ctype.h>
char* format(char* str)
{//isupper,islower,isdigit,isspace,isblink,isalpha,...
	if(str==NULL||*str=='\0')
		return str;
	char* s = str;
	*str = toupper(*str);//tolower
	while(*++str)
		*str = tolower(*str);
	return s;
}

