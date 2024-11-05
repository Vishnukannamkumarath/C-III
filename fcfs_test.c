#include<stdio.h>
struct node
{
	float burst_time;
	float waiting_time;
	float turn_time;
}p[10];
int main()
{
	float avgwtime=0,avgttime=0,r=0;
	float a[10],b[10];float s=0;
	int i,n;
	printf("enter no of process--\n");
	scanf("%d",&n);
	printf("enter burst time of each process--\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i].burst_time);
	}
	p[0].waiting_time=0;
	for(i=0;i<n;i++)
	{
		a[i]=p[0].waiting_time+p[i].burst_time+a[i-1];
	}
	for(i=0;i<n-1;i++)
	{
		avgwtime=avgwtime+a[i];
	}
	s=avgwtime/n;
	printf("average waiting time=%f\n",s);
	for(i=0;i<n;i++)
	{
		b[i]=p[i].burst_time+b[i-1];
	}
	for(i=0;i<n;i++)
	{
		avgttime=avgttime+b[i];
		}
		r=avgttime/n;
		printf("average turn around time=%f\n",r);
	}
