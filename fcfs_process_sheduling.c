#include<stdio.h>
struct easy
{
	float burst_time;
	float waiting_time;
}p[10];
int main()
{
	float a[10],b[10];
	int i,n;float s=0,f=0,avgwaitingtime,avgturnaroundtime;
	printf("ENTER NO OF PROCESS\n");
	scanf("%d",&n);
	printf("ENTER BURST TIME OF EACH PROCESS\n");
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
		s=s+a[i];
	}
	avgwaitingtime=s/n;
	printf("AVERAGE WAITING TIME USING FCFS=%f\n",avgwaitingtime);
	for(i=0;i<n;i++)
	{
		b[i]=p[i].burst_time+b[i-1];
	}
	for(i=0;i<n;i++)
	{
		f=f+b[i];
	}
	avgturnaroundtime=f/n;
	printf("AVERAGE TURN AROUND TIME USING FCFS=%f\n",avgturnaroundtime);
}
