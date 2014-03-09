#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

void showbyte(void* addr, int bytes)
{
	unsigned char *p=addr;
	int i;
	for (i=0; i<bytes; i++)
		printf("%d ",*p++);
	printf("\n");
}

int main()
{
	char *sip="192.168.9.66";
	unsigned int nip=0;

	inet_pton(AF_INET,sip,&nip);
	showbyte(&nip,sizeof(nip));

	char buf[128];
	puts(inet_ntop(PF_INET,&nip,buf,sizeof(buf)));

	int n=1; //host 0x00000001:1,0,0,0
	showbyte(&n,sizeof(n));

	n=htonl(n);//network 0.00000001:0,0,0,1
	showbyte(&n,sizeof(n));

	short s=356;//host 0x0164: 100,1
	showbyte(&s,sizeof(s));

	s=htons(s);//network 0x0164: 1,100
	showbyte(&s,sizeof(s));
	return 0;
}
