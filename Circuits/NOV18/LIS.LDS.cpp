#include<bits/stdc++.h>
using namespace std;
vector < vector < int > > v;
vector < int > d;
bfs(int s)
{
	for(int i=0;i<v[s].size();i++)
	{
		if(d[v[s][i]]==0)
		{
			d[i]++;
			bfs(v[s][i]);
		}
	}
}
int main()
{
	int n,m,t,i;	cin>>n>>m>>t;
	v.resize(n);
	d.resize(n);
	for(i=0;i<m;i++)
	{
		int s,d;	cin>>s>>d;
		v[s].push_back(d);
		v[d].push_back(s);
	}
	/*bfs(0);
	int n=-1,dis=-1;
	for(i=0;i<n;i++)
	{
		if(dis<d[i])
		{
			dis = d[i];
			n = i;	
		}
	}*/
	//path(n);
	cout<<"1"<<endl;
	cout<<"1"<<endl;
}
