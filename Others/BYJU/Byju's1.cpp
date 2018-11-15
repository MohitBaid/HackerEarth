#include<bits/stdc++.h>
using namespace std;
int A[10000+2];
int B[100000 +2];
int main()
{
	int n,i,s=0,j,c=1;	cin>>n;
	int A[n],B[20];
	
	for(i=0;i<n;i++)			cin>>A[i];
	vector < int > C;
	sort(A,A+n);
	for(j=1;j<=A[0];j++)
	{
		B[j]=s + (n)*j;
		C.push_back(B[j]);
	}
	
	s = A[0];
	for(i=1;i<n;i++)
	{
		for(j=A[i-1]+1;j<=min(A[i],100000);j++)
		{
			B[j] = s + (n-i)*j;
			C.push_back(B[j]);
		}
		s+=A[i];
	}
	for(i=0;i<C.size();i++)
		cout<<C[i]<<" ";	cout<<endl;
	
	int q;	cin>>q;
	while(q--)
	{
		int k ;	cin>>k;
		int p = lower_bound(C.begin(),C.end(),k) - C.begin();
		if(C[p]>=k)	cout<<p+1<<endl;
		else		cout<<"-1"<<endl;
	}
}
