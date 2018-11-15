#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		int A[n];
		for(i=0;i<n;i++)	scanf("%d",&A[i]);
		sort(A,A+n);
		long long int ans1=0,ans2=0;
		for(i=0;i<n;i=i+2)		ans1+=abs(A[i]-A[i+1]);
		for(i=0;i<n/2;i++)		ans2+=abs(A[i]-A[n-i-1]);
		cout<<ans1<<" "<<ans2<<endl;
	}
}
