#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j;	cin>>n>>m;
	int A[n][m],C[100]={0},pc=0,F[100]={0};
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>A[i][j];	
	long long int ans=n*m,c,f=0;
	for(i=0;i<n;i++)
	{
		int flag=-1;c=0;
		for(j=0;j<m;j++)
		{
			if(flag==-1)
			{
				c++;
				flag=A[i][j];
			}
			else
			{
				if(flag==A[i][j])	c++;
				else				
				{
					F[pc]=A[i][j-1];
					C[pc++]=c;
					c=1;
					if(flag==0)		flag=1;
					else			flag=0;
				}
			}
		}
		F[pc]=A[i][j-1];
		C[pc++]=c;
		if(F[0]==F[pc-1]&&pc>1)
			C[0]+=C[pc-1],pc--;
		for(j=0;j<pc;j++)				ans+=(C[j]-1)*C[j]/2;			
		if(pc==1&&m==3)					ans++;
		pc=0;
	}
	pc=0;
	for(i=0;i<m;i++)
	{
		int flag=-1;c=0;
		for(j=0;j<n;j++)
		{
			if(flag==-1)
			{
				c++;
				flag=A[j][i];
			}
			else
			{
				if(flag==A[j][i])	c++;
				else				
				{
					F[pc]=A[j-1][i];
					C[pc++]=c;
					c=1;
					if(flag==0)		flag=1;
					else			flag=0;
				}
			}
		}
		F[pc]=A[j-1][i];
		C[pc++]=c;
		//for(j=0;j<pc;j++)				cout<<C[j]<<" "<<F[j]<<"---->"<<endl;		cout<<endl;
		if(F[0]==F[pc-1]&&pc>1)
			C[0]+=C[pc-1],pc--;
		for(j=0;j<pc;j++)				ans+=(C[j]-1)*C[j]/2;
		if(pc==1&&n==3)					ans++;
		pc=0;
	}
	cout<<ans<<endl;		
}
