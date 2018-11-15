#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 401;
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
}
int main()
{
	seive();
	int n,i,j,ans=0;	cin>>n;
	int B[102][102];
	for(i=0;i<102;i++)
		for(j=0;j<102;j++)
			B[i][j]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>B[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			int temp=B[i-1][j]+B[i+1][j]+B[i][j-1]+B[i][j+1];
			//cout<<temp<<" "<<A[0]<<endl;
			if(A[temp])		ans++;
		}		
	cout<<ans<<endl;	
}
