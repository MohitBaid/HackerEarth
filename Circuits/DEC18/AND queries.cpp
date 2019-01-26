#include<bits/stdc++.h>
using namespace std;
int B[256][1000000+2];
int main()
{
	int n,i,j;	cin>>n;
	int A[n+1];
	for(i=1;i<=n;i++)
		cin>>A[i];
	for(i=0;i<=256;i++)
	{
		cout<<i<<endl;
		B[i][0]=0;
		for(j=1;j<=n;j++)
		{
			if(  (i&A[j]) == i)
			{
				B[i][j]++;
			}
			cout<<j<<endl;
		}
		for(j=1;i<=n;j++)
		{
			B[i][j]+=B[i][j-1];
		}
	}
	
	for(i=0;i<=3;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
}
