#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	int i;
	if(n==0||n==1)		return 0;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;		
}
int main()
{
	int n;	cin>>n;
	int i,ans1=0,ans2=0;
	if(n==0||n==1)
	{
		cout<<'2'<<endl;
		return 0;
	}	
	for(i=n;i>1;i--)
		if(isprime(i))
			break;
	ans1=n-i;
	for(i=n;;i++)
		if(isprime(i))
			break;	
	//cout<<i<<" "<<ans2<<" ";
	ans2=i-n;
	cout<<min(ans1,ans2)<<endl;	
	return 0;	
}
