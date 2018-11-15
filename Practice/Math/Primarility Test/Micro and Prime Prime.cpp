#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
int ans[MAX_SIZE];
int an[MAX_SIZE];
int PP[MAX_SIZE]={0};
int m;
void seive()
{
    isprime[0] = isprime[1] = 1 ;
    for (int i=2; i<MAX_SIZE ; i++)
    {
	    if (!isprime[i])
        {
            prime[m++]=i;
            ans[i]=1;
            SPF[i] = i;
        }
        for (int j=0;j<m && i*prime[j]<MAX_SIZE && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=1;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
    an[0]=ans[0];
    for(int i=1;i<MAX_SIZE;i++)
    	an[i]=an[i-1]+ans[i];
    for(int i=0;i<MAX_SIZE;i++)
		if(ans[an[i]])	
			PP[i]=1;
	for(int i=1;i<MAX_SIZE;i++)
		PP[i]+=PP[i-1];		
}
int main()
{
	seive();
	int T;	cin>>T;
	while(T--)
	{
		int l,r;	cin>>l>>r;
		cout<<PP[r]-PP[l-1]<<endl;
	}
}
