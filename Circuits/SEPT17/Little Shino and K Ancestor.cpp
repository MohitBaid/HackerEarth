#include<bits/stdc++.h>
using namespace std;
int P[1000001];
int P2[1000001];
int L[1000001];
int L2[1000001];
int C[1000001];
int V[1000001];
int ans[1000001];
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
	adj[w].push_back(v);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
  	P[s]=-1;
  	L[s]=0;
    while(!queue.empty())
    {
        s = queue.front();
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
             	P[*i]=s;
			    L[*i]=L[s]+1;
				visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	set < pair < int,int > > s;
	set < pair < int,int > >:: iterator it; 
	int n,k,i;	cin>>n>>k;
   	int A[n];
   	Graph g(n);
   	for(i=0;i<n;i++)	cin>>A[i];
    for(i=0;i<n-1;i++)
    {
    	int u,v;	cin>>u>>v;
		g.addEdge(u-1,v-1);
   	}
    g.BFS(0);
    for(i=0;i<n;i++)
    {
    	s.insert(make_pair(L[i],i));
    }
    i=0;
    for(it=s.begin();it!=s.end();it++)
    {
    	L2[i]=it->second;
		i++;
    }
    for(i=0;i<=1000000;i++)		C[i]=-1;
    for(i=0;i<n;i++)
    {
		ans[i]=-2;
		V[i]=-1;
		/*if(C[A[i]]==-1)		C[A[i]]=L[i];
		else
		{
			if(C[A[i]]>L[i])
				C[A[i]]=L[i];
		}*/
    }
    for(i=0;i<n;i++)
    {
    	int temp=L2[i];
    	int c=A[temp];
		if(C[c]==-1)		C[c]=temp;
		else
		{
			P[C[c]]=temp;
			C[c]=temp;
		}
	}
    for(i=0;i<n;i++)	
	{
		int c=A[i];
		int l=L[i];
		int kc=k;
		int ans=-2;
		int temp=i;
		while(kc)
		{
			temp=P[temp];
			kc--;
			if(kc==0)
			{
				ans=temp;
				break;
			}	
			if(P[temp]==C[c] || P[temp]==-1 )	break;
		}
		cout<<ans+1<<" ";
	}	
    return 0;
}
