#include <bits/stdc++.h>
using namespace std;
int n,level=0;
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s,int parent[],int lev[]);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to vâ??s list.
}
 
void Graph::BFS(int s,int parent[],int lev[])
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        //cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                parent[*i]=s;
                lev[*i]=lev[s]+1;
                level=max(level,lev[*i]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k;
    cin>>n>>k;
    Graph g(n);
    int a[n],b[n],d[k+1];
    for(i=0;i<=k;i++)
    d[i]=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=-1;
   //     d[a[i]]++;
    }
   // for(i=0;i<n;i++)
   // cout<<a[i]<<" ";
    //cout<<endl;
    int k1;
    for(i=0;i<n-1;i++)
    {
        
        cin>>k1>>j;k1--;j--;
        //cout<<k1<<j<<endl;
        g.addEdge(k1,j);
        g.addEdge(j,k1);
        //cout<<"mk";
    }
    //cout<<"yoyoy";
    int parent[n],lev[n];
    for(i=0;i<n;i++)
    parent[i]=-1,lev[i]=0;
    g.BFS(0,parent,lev);
    
    /*for(i=0;i<n;i++)
    cout<<parent[i]<<" ";
    cout<<endl;*/
    /*for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;*/
    int r1=0;
    for(i=n-1;i>=0;i--)
    {
        j=i;
        if(lev[i]>=k)
        if(b[i]==-1&&i>0)
        {
            r1=0;
            while(parent[j]!=-1||j!=-1)
            {
            //	cout<<j<<endl;
                if(a[i]==a[j]&&r1==k)
                {
                    b[i]=j+1;
                    break;
                }
                r1++;
                j=parent[j];
                if(r1>k||j==-1)
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    cout<<b[i]<<" ";
    cout<<"\n";
    return 0;
}
