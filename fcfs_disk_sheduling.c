#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int dq[10],i,n,head,da[10];
	printf("enter length of disk queue\n");
	scanf("%d",&n);
	printf("enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&dq[i]);
	}
	printf("enter current head position\n");
	scanf("%d",&head);
	for(i=0;i<n;i++)
	{
		da[i]=abs(head-dq[i]);
		head=dq[i];
	}
	int sum=0;
	for(i=0;i<n;i++)
	{
	  sum=sum+da[i];
    }
	printf("no of head movement=%d\n",sum);
}
	
