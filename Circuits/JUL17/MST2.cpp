//http://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
#include<bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> iPair;
int E[300000][3];
int M[300000];
int lev[300000];
int m2=0;
stack <int> s;
list< pair<int, int> > *adj;
map < pair <int,int> ,int > mp;
class Graph
{
public:
    int V;   
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
    void DFS(int ,int ,bool viited[]);
    void DFSUtil(int v, bool visited[]);
	void DFSUtil2(int v, bool visited[],int );
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
    list< pair<int, int> >::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
		if(!visited[(*i).first])
            DFSUtil((*i).first, visited);
	}
}
void Graph::DFSUtil2(int v, bool visited[],int g)
{
	visited[v] = true;
    list< pair<int, int> >::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
	    if (!visited[(*i).first])
        {
            s.push((*i).first);
            visited[(*i).first]=true;
			lev[(*i).first]=m2;
			m2++;
			DFSUtil2((*i).first, visited,g);
			if(m2==lev[(*i).first] && (*i).first!=g)		s.pop();
		}
		if((*i).first==g)			return;
	}
	m2--;
}
void Graph::DFS(int v,int g,bool visited[])
{
    for (int i = 0; i < V; i++)
        visited[i] = false;
    s.push(v);
    m2=0;
	DFSUtil2(v, visited,g);
}
void Graph::primMST()
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    int src = 0; 
    pair <int,int> p;
	vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        p=pq.top();
		pq.pop();
        inMST[u] = true;  
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for(int i=0;i< V;i++)
    {
    	int u=E[i][0];
    	int v=E[i][1];
    	if(u==parent[v]||v==parent[v])			M[i]=0;
	}
}
int main()
{
	int i,n,q;	cin>>n>>q;
	Graph g(n);
	for(i=0;i<n;i++)
	{
		int u,v,c;	cin>>u>>v>>c;
		u--;	v--;
		if(u>v)	
		{
			int temp=u;
			u=v;
			v=u;
		}
		g.addEdge(u,v,c);
		E[i][0]=u;
		E[i][1]=v;
		E[i][2]=c;
		mp[make_pair(u,v)]=c;
		M[i]=1;
	}
	g.primMST();
	int tempu,tempv,tempc;
	long long int sum=0,ans=0;
	for(i=0;i<n;i++)
		if(M[i]==1)
		{
			tempu=E[i][0],tempv=E[i][1],tempc=E[i][2];
			adj[tempu].remove(make_pair(tempv,tempc));
			adj[tempv].remove(make_pair(tempu,tempc));
		}
		else
			sum+=E[i][2];	
	while(q--)
	{
		int x1,x2,x3,x4,x5;		cin>>x1>>x2>>x3>>x4>>x5;
		int a=x1+ans%100 -1;
		int b=x2+ans%100 -1;
		int u=x3+ans%100 -1;
		int v=x4+ans%100 -1;
		int c=x5+ans%100;
		int c1;
		
		/*removing a,b*/
		if(a<b)			c1=mp[make_pair(a,b)];
		else			c1=mp[make_pair(b,a)];
		adj[a].remove(make_pair(b,c1));
		adj[b].remove(make_pair(a,c1));
		if(a<b)			mp.erase(make_pair(a,b));
		else			mp.erase(make_pair(b,a));
		
								
		if( !((a==tempu && b==tempv) || (a==tempv && b==tempu)))				//removed edge from mst
		{
			bool visited[n];	int flag=1;
			for(i=0;i<n;i++)	visited[i]=false;
			g.DFSUtil(a, visited);
			if(visited[tempu]!=visited[tempv] && visited[u]!=visited[v] )		//both edges can be added
			{
				if(tempc<c)		sum+=tempc,flag=0;
				else			sum+=c;										
			}
			else if(visited[tempu]!=visited[tempv])		sum+=tempc,flag=0;
			else										sum+=c;	
			sum-=c1;
			if(flag)
			{
				g.addEdge(u,v,c);
				if(u<v)			mp[make_pair(u,v)]=c;					
				else			mp[make_pair(v,u)]=c;	
			}
			else
			{
				g.addEdge(tempu,tempv,tempc);
				if(tempu<tempv)		mp[make_pair(tempu,tempv)]=tempc;
				else				mp[make_pair(tempv,tempc)]=tempc;
				tempu=u,tempv=v,tempc=c;
			}
		}
		else																	//removed edge not from mst
		{
			bool visited[n];
			for(i=0;i<n;i++)	visited[i]=false;
			g.DFS(u,v,visited);
			int temp=s.top();
    		s.pop();
    		int max=-1;
			while(s.size()>0)
    		{
				if(temp<s.top())		tempc=mp[make_pair(temp,s.top())];
				else					tempc=mp[make_pair(s.top(),temp)];	
				if(tempc>max)
				{
					max=tempc;
					tempu=temp;
					tempv=s.top();
				}
				temp=s.top();
				s.pop();
    		}	
    		if(max>c)
    		{
    			sum+=c;
    			sum-=max;
    			tempc=max;
    			g.addEdge(u,v,c);
    			if(u<v)			mp[make_pair(u,v)]=c;					
				else			mp[make_pair(v,u)]=c;
				adj[tempu].remove(make_pair(tempv,tempc));
				adj[tempv].remove(make_pair(tempu,tempc));	
			}
    		else
    		{
    			g.addEdge(tempu,tempv,tempc);
				if(tempu<tempv)		mp[make_pair(tempu,tempv)]=tempc;
				else				mp[make_pair(tempv,tempc)]=tempc;
				tempu=u;
    			tempv=v;
    			tempc=c;
    		}
    		
		}
		ans=sum;
		cout<<ans<<endl;
		
	}			
}
