#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#define port 5000
void main(){
struct sockaddr_in serveraddr,newaddr;
int i,c=0;
int sersocket,newsocket,s,size;
char buffer[100],word[100],ant[100];
char dict[3][3][100]={"black","color","white","red","color","green","blue","color","yello"};
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
listen(sersocket,1);
size=sizeof(newaddr);
printf("server ready\n");
newsocket=accept(sersocket,(struct sockaddr*)&newaddr,&size);
if(newsocket>0){
printf("accept is success\n");
}
recv(newsocket,buffer,sizeof(buffer),0);
printf("Data received:%s\n",buffer);
for(i=0;i<3;i++){
if(strcmp(buffer,dict[i][0])==0){
strcpy(word,dict[i][1]);
send(newsocket,word,sizeof(word),0);
strcpy(ant,dict[i][2]);
send(newsocket,ant,sizeof(ant),0);
}
else{
c++;
}
}
if(c==3){
strcpy(word,"NOT FOUND\n");
send(newsocket,word,sizeof(word),0);
}
close(sersocket);
}

