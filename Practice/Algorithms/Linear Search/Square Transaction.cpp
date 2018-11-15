#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	int A[T];	
	for(i=0;i<T;i++)
	{
		cin>>A[i];
		if(i!=0)	A[i]=A[i]+A[i-1];
	}
	int q;	cin>>q;
	while(q--)
	{
		int t;	cin>>t;
		for(i=0;i<T;i++)
			if(A[i]>=t)
			{
				cout<<i+1<<endl;
				break;
			}
		if(i==T)	cout<<-1<<endl;	
	}
	return 0;
}
