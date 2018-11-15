#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int C[750001];
int prime(int a)
{
		for(int j=2;j*j<=a;j++)
			if(a%j==0)
				return 0;
		return 1;		
}
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
			int i,j;
			for(i=0;i<=750000;i++)		C[i]=0;
			int n,m=0;	scanf("%d",&n);
			int A[n];
			int flag=0;
			long long int ans=0;
			for(i=n-1;i>=0;i--)
			{
				scanf("%d",&A[i]);	
				for(j=2;j*j<=A[i];j++)
					if(A[i]%j==0)
					{
						C[j]++;
						if(j!=A[i]/j)
							C[A[i]/j]++;
					}		
				C[A[i]]++;
				if(A[i]==1)
					flag=1;	
			}
			for(i=2;i<=750000;i++)
			{
				if(C[i]!=0)
				{
					if(prime(i))
					{
							ans+=(pow(2,C[i])-1-C[i]);
							ans=ans%MOD;
					}
				}
			}
			ans+=n;
			ans=ans%MOD;
			if(flag)
				ans=((2*ans)%MOD)-1;
			printf("%lld\n",ans);	
		}
}
