#include<stdio.h>
int main()
{
	long long  int i,j=1,c=0;
	long long int A[44721];
	for(i=0;c<44721;i++)
	{
		A[c]=i;
		i+=j;
		j++;
		c++;
	}
	for(i=0;i<44;i++)
		printf("%d ",A[i]);	
	long long int t,n;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,ans=0;	scanf("%lld",&n);
		for(i=0;;i++)
		{
			if(A[i]==n)
			{
				printf("%lld\n",(A[i]-i)*2);
				break;
			}
			else if(A[i]<n&&A[i+1]>n)
			{
				printf("%lld\n",(A[i]-i)*2+(n-A[i])*2);
				break;
			}
		}		
	}
}
