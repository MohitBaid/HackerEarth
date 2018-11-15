#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;	cin>>n;
	long long int A[n];
	for(i=0;i<n;i++)	cin>>A[i];
	int k;	cin>>k;
	for(i=0;i<n;i++)
	{
		if(A[i]==k)
		{
			cout<<i<<endl;
			break;
		}
	}
}

