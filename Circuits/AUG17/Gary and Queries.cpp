#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;	cin>>n>>q;
	int A[n],i;
	for(i=0;i<n;i++)	cin>>A[i];
	while(q--)
	{
		int c;	cin>>c;
		if(c==1)
		{
			int x,y;	cin>>x>>y;
			A[x-1]=y;
		}
		else
		{
			long long int ans=0;
			int x;	cin>>x;
			for(i=0;i<n;i++)
				ans+=(A[i]/x);
			cout<<ans<<endl;	
		}
		
		
	}
}
