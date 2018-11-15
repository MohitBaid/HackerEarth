#include<bits/stdc++.h>
using namespace std;
int main()
{
		int Q;	cin>>Q;
		while(Q--)
		{
			int n,i,ans=0;	cin>>n;
			for(i=1;i<n;i++)
				if(n%i==0)	
					ans+=i;
			cout<<ans<<endl;		
		}
}
