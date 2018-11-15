#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{	
		long long int n;	scanf("%lld",&n);
		if(n==1)			printf("1\n");
		else
		{
			long long int ans=(n*n);
			ans=(ans/2) -1;
			printf("%lld\n",ans);
		}
	}
}
