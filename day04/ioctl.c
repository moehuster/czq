#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
	struct winsize w; //ws_row, ws_col
	int r=0,c=0;
	for (;;){
		ioctl(STDIN_FILENO,TIOCGWINSZ,&w);
		if (w.ws_row!=r||w.ws_col!=c){
			r = w.ws_row;
			c = w.ws_col;
			printf("%d x %d\n",r,c);
		}
	}
}
