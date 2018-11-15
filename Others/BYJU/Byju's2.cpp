#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;	cin>>n;
	int A[n],B[n];
	int ans = 0;
	for(i=0;i<n;i++)
	{
		cin>>A[i]>>B[i];
	}
	for(i=n-1;i>=0;i--)
	{
		int diff =  (A[i]+ans) % B[i] ;
		if(diff > 0)	diff = B[i]-diff;
		ans+=diff;
	}
	cout<<ans<<endl;
}
