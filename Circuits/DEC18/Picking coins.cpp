#include<bits/stdc++.h>
#define ull unsigned long long int 
using namespace std;
int main()
{
    int T,i;	cin>>T;
	while(T--)
	{
		ull n,k;
		cin>>n>>k;
		ull m  = 0,t = k;
		if(k == 1)
		    n = n%2;
		while(n>= 1LL*2*k)
		{
			n-=(1LL*2*k);
			k = 1LL * k * t;
		}
		if(n>=k)	
			m=1;
		if(m%2)		cout<<"Alice"<<endl;
		else		cout<<"Bob"<<endl;
	}
}
