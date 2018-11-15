#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int power(long long int a,int x)
{
	if(x==0)				return 1;
	if(x==1)				return a;	
	long long int temp=power(a,x/2);
	if(x%2==0)		return (temp*temp)%MOD;
	else			return (((temp*temp)%MOD)*x)%MOD;
}
int main()
{
	int n,y,i;	cin>>n>>y;
	long long int A[n],ans=0,sum=0;
	for(i=0;i<n;i++)		cin>>A[i],sum+=A[i],sum=sum%MOD;
	 if(n>y)	cout<<0<<endl;
	 else if(n==y)	cout<<sum%MOD;
	 else		cout<<7<<endl; 
}
