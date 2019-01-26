#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		//int n;	cin>>n;
		string s;	cin>>s;
		int n = s.size();
		set < char > ch;
		int A[11][101][11][11]={0};
		int B[11][101]={0};
		int i,j,k,l;
		for(i=0;i<n;i++)
		{
			A[1][i][s[i]-'0'][s[i]-'0']=1;
			B[1][i]=1;
			ch.insert(s[i]);
		}
		for(i=2;i<=ch.size();i++)
		{
			//cout<<"size  "<<i<<endl;
			for(j=0;j<n;j++)
			{
				int C[10]={0};
				C[s[j]-'0']=1; 
				//cout<<"starting with "<<j<<endl;
				for(k=j+1;k<n;k++)
				{
					if(C[s[k]-'0']==0)
					{
						//cout<<"Adding "<<k<<endl;
						C[s[k]-'0']=1;
						B[i][j]+=(B[i-1][k]-A[i-1][k][s[j]-'0'][s[j]-'0']);
						for(l=0;l<10;l++)
						{
							if(l!=(s[j]-'0'))
								A[i][j][l][l]+=A[i-1][k][l][l];
						}
						for(l=0;l<10;l++)
						{
							A[i][j][l][l]-=A[i][j][s[j]-'0'][l];
						}
					}
				}
				A[i][j][s[j]-'0'][s[j]-'0'] = B[i][j];
			}
		}
		for(i=1;i<=ch.size();i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<B[i][j]<<" ";
			}
			cout<<endl;
		}
		for(i=1;i<=ch.size();i++)
		{
			cout<<"size -->"<<i<<endl;
			for(j=0;j<n;j++)
			{
				for(k=0;k<10;k++)
					cout<<A[i][j][k]<<" ";
				cout<<endl;	
			}
			cout<<endl;
		}
		cout<<ch.size()<<endl;
		int ans = 0;
		int C[10]={0};
		for(i=0;i<n;i++)
		{
			if(C[s[i]-'0']==0)
			{
				ans += B[ch.size()][i];
				C[s[i]-'0']=1;
			}
		}
		cout<<ans<<endl;	
	}
}
