//http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
#include<bits/stdc++.h>
using namespace std;
long long int E[100000][70];
long long int D[100000][4];
long long int M[100];
class Graph
{
    int V;    
    list<int> *adj;    
    void DFSUtil(long long int v, bool visited[]);  
public:
    Graph(long long int V);   
    void addEdge(long long int v, long long int w);  
    int DFS();    
};
Graph::Graph(long long int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(long long int v,long long int w)
{
    adj[v].push_back(w); 
} 
void Graph::DFSUtil(long long int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
int Graph::DFS()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
	 DFSUtil(0, visited);
	 for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return 0;
      return 1;      
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,m,k,i,j;		cin>>n>>m>>k;
	long long int C[k+1];
	for(i=0;i<k;i++)	cin>>C[i];
	for(i=0;i<m;i++)
	{
		cin>>D[i][0]>>D[i][1]>>D[i][2];
		D[i][0]--;	D[i][1]--;
		for(j=0;j<D[i][2];j++)		
		{
				cin>>E[i][j];
				E[i][j]--;
		}
	}
	Graph g(n);
	for(j=0;j<m;j++)
	{
		g.addEdge(D[j][0],D[j][1]);
		g.addEdge(D[j][1],D[j][0]);
	}
	long long int m2=g.DFS();
	if(m2==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	long long int f=k;
	for(i=f-1;i>=0;i--)
	{
		M[i]=1;
		long long int C2[100000]={0};
		long long int m3=0;
		for(j=0;j<m;j++)
			for(k=0;k<D[j][2];k++)
				if(E[j][k]==i && D[j][3]==0)			
				{
					D[j][3]=1;
					C2[m3++]=j;
					break;
				}
		Graph g(n);
		for(j=0;j<m;j++)
		{
			if(D[j][3]==0)
			{
				g.addEdge(D[j][0],D[j][1]);
				g.addEdge(D[j][1],D[j][0]);
			}
		}
		long long int m2=g.DFS();
		if(m2==0)
		{
			M[i]=0;
			for(j=0;j<m3;j++)
				D[C2[j]][3]=0;
		}
	}
	long long int ans=0;
	for(i=0;i<f;i++)
		if(M[i]==0)
			ans+=C[i];
	cout<<ans<<endl;		
	return 0;
}
