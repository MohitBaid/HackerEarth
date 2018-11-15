#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
int A[MAX_SIZE];
int m;
void seive()
{
    isprime[0] = isprime[1] = 1 ;
    int i,j=0;
	for (i=2; i<MAX_SIZE ; i++)
    {
	    if (!isprime[i])
        {
            prime[m++]=i;
            A[i]=1;
            SPF[i] = i;
        }
        for (int j=0;j<m && i*prime[j]<MAX_SIZE && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=1;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
    for(i=1;i<MAX_SIZE;i++)	
    	A[i]+=A[i-1];		
}
int main()
{
	seive();
	int Q;	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;	scanf("%d %d",&l,&r);
		if(l>r)		printf("%d\n",A[l]-A[r-1]);
		else        printf("%d\n",A[r]-A[l-1]);
	}
}
