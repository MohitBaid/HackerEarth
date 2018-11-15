#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
long long int ans[MAX_SIZE];
int m;
void seive()
{
    isprime[0] = isprime[1] = 1 ;
    for (int i=2; i<MAX_SIZE ; i++)
    {
	    if (!isprime[i])
        {
            prime[m++]=i;
            ans[i]=i;
            SPF[i] = i;
        }
        for (int j=0;j<m && i*prime[j]<MAX_SIZE && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=1;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
    for(int i=1;i<MAX_SIZE;i++)
    	ans[i]+=ans[i-1];
}
int main()
{
	seive();
	int T;	cin>>T;
	while(T--)
	{
		int l,r;	cin>>l>>r;
		cout<<ans[r]-ans[l-1]<<endl;
	}
}
