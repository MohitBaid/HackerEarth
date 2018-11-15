#include<bits/stdc++.h>
using namespace std;
int E[100000][2];
int e=0;
int P[100000];
int f=1000000;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q	,i;		cin>>n>>q;
	for(i=0;i<100000;i++)	P[i]=-1;
	while(q--)
	{
		int q,u,v;	cin>>q>>u>>v;
		u--;		v--;
		if(q==1)
		{
			E[e][0]=u;
			E[e++][1]=v;
		}
		else
		{
			if(P[u]==-1&&P[v]==-1)
				P[u]=f,P[v]=f,f++;
			else
			{
				if(P[u]!=-1&&P[v]==-1)
					P[v]=P[u];
				else if(P[v]!=-1&&P[u]==-1)
					P[u]=P[v];
				else if(P[u]!=-1&&P[v]!=-1)
				{
					int temp=P[v];
					for(i=0;i<n;i++)
						if(P[i]==temp)
							P[i]=P[u];
				}		
			}
		}
		int flag=1;
		for(i=0;i<e;i++)
		{
			//cout<<E[i][0]<<" ->"<<P[E[i][0]]<<" "<<E[i][1]<<" ->"<<P[E[i][1]]<<endl;
			if(P[E[i][0]]!=P[E[i][1]] || P[E[i][0]]==-1)
			{
				flag=0;
				break;
			}	
		}
		if(flag) cout<<"YES"<<endl,e=0;
		else	 cout<<"NO"<<endl;
		//cout<<"\n\n\n";
	}
}
