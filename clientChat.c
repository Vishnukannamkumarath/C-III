#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define port 5000
void chat(int clisocket)
{
	char buffer[100];
	while(1)
	{
		printf("To server:\n");
		fgets(buffer,sizeof(buffer),stdin);
		send(clisocket,buffer,sizeof(buffer),0);
		recv(clisocket,buffer,sizeof(buffer),0);
		printf("From Client:%s\n",buffer);
		if(strcmp(buffer,"bye\n")==0)
		break;
	}
}
int main()
{
	struct sockaddr_in serveraddr;
	int clisocket;
	clisocket=socket(PF_INET,SOCK_STREAM,0);
	if(clisocket>0)
	{
		printf("socket created\n");
	}
	serveraddr.sin_family=PF_INET;
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	chat(clisocket);
	close(clisocket);
}
