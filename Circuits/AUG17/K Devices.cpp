#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,i;	cin>>n>>k;
	long long int X[n],Y[n];
	long long int d[n];
	for(i=0;i<n;i++)		cin>>X[i];
	for(i=0;i<n;i++)		cin>>Y[i];
	for(i=0;i<n;i++)		d[i]=X[i]*X[i]+Y[i]*Y[i];
	sort(d,d+n);
	long long int ans=d[k-1];
	long long int ans2=sqrt(ans);
	if(ans2*ans2<ans)		ans2++;
	cout<<ans2<<endl;
}
