#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;	cin>>n;
	int A[n];
	set < int > s;
	set < int > q;
	map < int , int  > mp,mp2;
	set < int > ::iterator it;
	for(i=1;i<=n;i++)
	{
		q.insert(i);
	}
	for(i=0;i<n;i++)
	{
		cin>>A[i];
		//s.insert(A[i]);
		q.erase(A[i]);
		mp[A[i]]++;	
		mp2[A[i]]++;
	}
	int ans[n];
	int T[n+1];
	for(i=1;i<=n;i++)	T[i]=0;
	for(i=0;i<n;i++)
	{
		/*for(it=q.begin();it!=q.end();it++)
			cout<<*it<<" ";
		cout<<endl;*/	
		if(mp[A[i]]==1)	
		{
			ans[i]=A[i];
			T[A[i]]=1;
			s.erase(A[i]);
		}
		else if(q.size()==0)
		{
			ans[i]=A[i];
			T[A[i]]=1;
		}
		else			
		{
			it=q.begin();
			if(T[A[i]]==0)
			{
				if(A[i]<*it)
				{
					ans[i]=A[i];
					T[A[i]]=1;
				}
				else
				{
					ans[i]=*it;
					T[*it]=1;
					q.erase(*it);
				}
			}
			else
			{
				ans[i]=*it;
				T[*it]=1;
				q.erase(*it);
			}
		}
	}
	int c=0;
	for(i=0;i<n;i++)
	{
		if(A[i]!=ans[i])
			c++;
	}
	cout<<c<<endl;
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
}
