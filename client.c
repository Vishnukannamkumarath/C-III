#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#define port 5000
int main()
{
	struct sockaddr_in serveraddr;
	int clisockt;
	char buffer[100];
	clisockt=socket(PF_INET,SOCK_STREAM,0);
	if(clisockt>0)
	{
		printf("socket created successfully\n");
	}
	serveraddr.sin_family=PF_INET;
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(clisockt,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	printf("\nEnter string:\n");
	scanf("%s",buffer);
	send(clisockt,buffer,sizeof(buffer),0);
	close(clisockt);
}
	
	
