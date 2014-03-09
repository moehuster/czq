#include <signal.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc!=3){
		printf("%s pid intvl\n",argv[0]);
		return 0;
	}
	sigval_t s;
	s.sival_int = atoi(argv[2]);
	sigqueue(atoi(argv[1]),SIGINT,s);
	printf("mypid=%d, myuid=%d\n",getpid(),getuid());
}
