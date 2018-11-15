#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int pow(long long int a,long long int x)
{
	if(x==0)	return 1;
	if(x==1)	return a;
	long long int temp=pow(a,x/2);
	if(x%2==0)		return (temp*temp)%MOD;
	else		return (((temp*temp)%MOD)*a)%MOD;
}
long long int modInverse(long long int a, long long int m)
{
    long long int m0 = m, t, q;
    long long int x0 = 0, x1 = 1;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
    return x1;
}
int main()
{
	int x,i,j;	cin>>x;
	long long int A[x],B[x];
	long long int sum=0,ans=1,temp=1;
	for(i=0;i<x;i++)	cin>>A[i],temp=(temp*(A[i]+1))%MOD;
	for(i=0;i<x;i++)
	{
		long long int tem=(((1LL*((1LL*A[i]*(A[i]+1))/2))%MOD)*((temp*modInverse(A[i]+1,MOD))%MOD)%MOD);
		ans=ans*(tem+1);
		ans=ans%MOD;
	}
	cout<<ans%MOD<<endl;
}
