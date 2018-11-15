#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;	cin>>n>>m;
	int i=0,temp;
	int ans=0;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		if(i==0)	ans=temp;
		ans=__gcd(ans,temp);
	}
	cout<<ans<<endl;
}
