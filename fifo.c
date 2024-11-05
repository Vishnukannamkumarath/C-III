#include<stdio.h>
int main()
{
	int i,j,n,f,pf=0,ph=0,rs[25],m[10],count=0;
	printf("enter length of rs\n");
	scanf("%d",&n);
	printf("enter rs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter no of frames\n");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		m[i]=-1;
	}
	printf("page replacement process\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				ph++;
				break;
			}
		}
		if(j==f)
		{
			m[count]=rs[i];
			count++;
			pf++;
		}
		if(j!=f)
		{
			ph++;
		}
		for(j=0;j<f;j++)
		{
			printf("%d\t",m[j]);
		}
		if(j==f)
		{
			printf("PF=%d\n",pf);
		}
		if(j!=f)
		{
			printf("PH=%d\n",ph);
		}
		if(count==f)
		{
			count=0;
		}
	}
	printf("PF=%d\n",pf);
	printf("PH=%d\n",n-pf);
}
