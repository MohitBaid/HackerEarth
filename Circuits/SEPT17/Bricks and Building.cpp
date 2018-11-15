#include<bits/stdc++.h>
using namespace std;
int ans[1000001];
int main()
{
	int n,i,q,j;	cin>>n;
	int A[n];
	for(i=0;i<n;i++)	cin>>A[i];
	cin>>q;
	for(j=0;j<n;j++)
	{
		int temp=A[j];
		for(i=1;i*i<A[j];i++)
		{
			if(temp%i==0)	
			{
				ans[i]++;
				ans[temp/i]++;
			}
		}
		if(i*i==A[j])
		{
			ans[i]++;
		}
	}
	while(q--)
	{
		int k;	cin>>k;
		cout<<ans[k]<<endl;		
	}
}
