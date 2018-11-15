#include<bits/stdc++.h>
using namespace std;

long long MOD=1e9+7;
bool visited[100002];
bool connected(vector<pair<int,int> >&edge,int n)
{
	int m = edge.size();
	int i,j;
	for(i=0;i<n;i++)
		visited[i] = false;
	for(i=0;i<m;i++)
	{
		if(edge[i].first == -1)	
			continue;
		visited[edge[i].first] = visited[edge[i].second] = true;
	}
	for(i=0;i<n;i++)
		if(!visited[i])
			return false;
	return true;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int i,j;
	int n,m,k;
	cin>>n>>m>>k;
	unsigned long long sum = 0;
	long long token[k];
	for(i=0;i<k;i++)
	{
		cin>>token[i];
		sum += token[i];	
	}
	int u,v,w,x;
	vector< pair<int,int> >edge;
	vector< set<int> > etok;
	for(i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		u--;
		v--;
		edge.push_back(make_pair(u,v));
		set<int> s;
		for(j=0;j<w;j++)
		{
			cin>>x;
			x--;
			s.insert(x);
		}
		etok.push_back(s);
	}
	if(!connected(edge,n))
		{
			cout<<"-1\n";
			return 0;	
		}
	for(j = k-1; j>=0; j--)
	{
		
		vector< pair<int,int> >new_edge;
		x = edge.size();
		for(i=0;i<x;i++)
		{
			if(etok[i].find(j) == etok[i].end())
				new_edge.push_back(edge[i]);
		}
		if(connected(new_edge,n))
			{
				sum -= token[j];
				x = edge.size();
				for(i=0;i<x;i++)
				{
					if(etok[i].find(j) != etok[i].end())
						edge[i].first = -1;
				}		
			}
				
	}
	cout<<sum<<endl;
}
