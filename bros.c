#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#define port 5000
void main(){
struct sockaddr_in serveraddr,newaddr;
int i,n;
printf("Enter no of Clients\n");
scanf("%d",&n);
int sersocket,newsocket[n],s,size;
char buffer[100];
sersocket=socket(PF_INET,SOCK_STREAM,0);
if(sersocket>0){
printf("socket is created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=PF_INET;
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(s==0){
printf("bind success\n");
}
listen(sersocket,n);
size=sizeof(newaddr);
printf("SERVER READY\n");
for(i=0;i<n;i++){
newsocket[i]=accept(sersocket,(struct sockaddr*)&newaddr,&size);
printf("Accepted From%s:%d\n",inet_ntoa(newaddr.sin_addr),ntohs(newaddr.sin_port));
}
while(1){
printf("Enter Data\n");
scanf("%s",buffer);
for(i=0;i<n;i++){
send(newsocket[i],buffer,sizeof(buffer),0);
}
if(strcmp(buffer,"bye")==0){
break;
}
}
for(i=0;i<n;i++){
close(newsocket[i]);
}
}

