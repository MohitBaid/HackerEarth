#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,j,flag=1,flag1=1;	scanf("%d",&n);
		long long int A[n],count[n];
		long long max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
			count[i]=1;
			if(A[i]>max)
				max=A[i];
		}	
		for(i=0;i<n;i++)
		{
			if(A[i]==0)
			{
				A[i]=-1;
				continue;
			}
			for(j=i+1;j<n;j++)
			{		
				if(A[i]==A[j]&&A[i]!=-1)
				{
					count[i]++;
					flag1=0;
					A[j]=-1;
				}
			}
		}	
		for(i=0;i<n;i++)
		{
			if(count[i]%2!=0&&count[i]!=1)
				flag=0;
		}		
		if(flag==1)
		{
			if(flag1==0)
				printf("Draw\n");
			else
				printf("Alice\n%lld",max);	
		}
		else
			printf("Alice\n%lld",max);					
	}
	return 0;
}
