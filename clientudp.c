#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#define port 4000
void main()
{
	struct sockaddr_in serveraddr,newaddr;
	int clisocket,size;
	char buffer[100];
	clisocket=socket(AF_INET,SOCK_DGRAM,0);
	if(clisocket>0)
	{
		printf("socket created successfully\n");
	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	printf("Enter message:\n");
	scanf("%s",buffer);
	size=sizeof(newaddr);
	sendto(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*),&serveraddr,sizeof(serveraddr));
	recvfrom(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*)&newaddr,&size);
	printf("received mesage:%s\n",buffer);
	close(clisocket);
}
