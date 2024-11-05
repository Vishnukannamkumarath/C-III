#include<stdio.h>
int main()
{
	int i,j,k,n,m,alloc[20][20],max[20][20],avail[25],y,ind=0;
	printf("enter no of process\n");
	scanf("%d",&n);
	printf("enter no of resources\n");
	scanf("%d",&m);
	printf("enter allocation matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter max matix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("enter avail matrix\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	int finish[n],safeseq[n],work[m],need[n][m];
	for(i=0;i<m;i++)
	{
		work[i]=avail[i];
	}
	for(j=0;j<n;j++)
	{
		finish[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("need matrix\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%d\t",need[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		work[i]=avail[i];
	}
	for(j=0;j<n;j++)
	{
		finish[j]=0;
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(finish[i]==0)
			{
				int flag=0;
				for(j=0;j<m;j++)
				{
					if(need[i][j]>work[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					safeseq[ind++]=i;
					for(y=0;y<m;y++)
					{
						work[y]+=alloc[i][y];
					}
					finish[i]=1;
				}
			}
		}
	}
	printf("safe sequence\n");
	for(i=0;i<=n-1;i++)
	{
		printf("P%d\t",safeseq[i]);
	}
}
