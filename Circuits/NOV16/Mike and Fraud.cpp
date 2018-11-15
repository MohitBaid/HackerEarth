#include<stdio.h>
int main()
{
	int n,k;	scanf("%d %d",&n,&k);
	int A[n];
	int i,j,f,ans=0,c=1;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<n;i++)
	{
		if(A[i]%k==0)
		{
			printf("Increamenting answer by %d for %d\n",n-i,A[i]);
			ans+=(n-i);
			c=1;
		}	
		else
		{
			c=A[i];
			for(j=i+1;j<n;j++)
				{
					c=c*A[j];
					if(c%k==0)
					{
						printf("Increamenting answer by %d for %d\n",n-j,A[i]);
						ans+=(n-j);
						i=j-1;
						break;
					}			
				}
		}	
	}
	printf("%d",ans);			
}
