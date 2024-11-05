#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[25],i,j,n,e,flag=0;
	printf("enter size of array\n");
	scanf("%d",&n);
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//sort
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}printf("enter search element\n");
	scanf("%d",&e);
	int low=0;
	int high=n-1;
	i=0;
	while(i<n)
	{
	   int mid=(low+high)/2;
	   if(e==a[mid])
	   {
		    flag=1;
		   break;
	   }
	   else if(e<a[mid])
	   {
		   low=0;
		   high=mid-1;
	   }
	   else if(e>a[mid])
	   {
		   low=mid+1;
		   high=n-1;
	   }
	   
	}
	if(flag==1)
	{
		printf("element present \n");
	}
	else
	{
		printf("element not present\n");
	}
	
}
