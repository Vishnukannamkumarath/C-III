#include<stdio.h>
#include<stdlib.h>
struct easy
{
	float burst_time;
	float waiting_time;
}p[10];
int main()
{
	float avg_waiting_time=0;
	float a[10];
	float avg;
	int i,n;
	printf("ENTER NUMBER OF PROCESSES\n");
	scanf("%d",&n);
	printf("ENTER BURST TIME OF EACH PROCESSES\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i].burst_time);
	}
	p[0].waiting_time=0;
	for(i=0;i<n-1;i++)
	{
		a[i]=p[0].waiting_time+p[i].burst_time+a[i-1];
	}
	for(i=0;i<n-1;i++)
	{
		avg_waiting_time=a[i]+avg_waiting_time;
	}
	avg=(avg_waiting_time)/n;
	printf("AVERAGE WAITING TIME=%fms",avg);
}
