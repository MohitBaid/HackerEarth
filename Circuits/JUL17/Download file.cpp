#include<bits/stdc++.h>
using namespace std;
int T[1000001];
int main()
{
	int n,s,i;	cin>>n>>s;
	long long int D[n],t[n];
	for(i=0;i<n;i++)		cin>>t[i]>>D[i];
	int j=0;
	for(i=0;i<=1000000;i++)
	{
			
			T[i]=D[j];
			if(j<n-1 && i+1==t[j+1])
					j++;
	}
	for(i=0;i<10;i++)		cout<<T[i]<<" ";
	int st=0;
	int a=-1,b=-1;
	int temp=0,atemp,btemp,flag=0;
	for(i=0;i<=1000000;i++)
	{
		if(st>=n)	break;
		temp+=T[i];
		if(temp==s)
		{
			atemp=i-st+1;
			btemp=1;	
			temp-=T[st];
			st++;
			flag=1;
		}
		else if(temp>s)
		{
			int diff=temp-s;
			while(diff>=T[st])
			{
				temp-=T[st];
				diff-=T[st];
				st++;
			}
			if(T[st]>T[i])
			{
				btemp=T[i];
				atemp=(i-st+1)*T[i]-diff;
				flag=1;
			}
			else
			{
				btemp=T[st];
				atemp=(i-st+1)*T[st]-diff;
				flag=1;
			}
			int m=__gcd(atemp,btemp);
			atemp/=m;
			btemp/=m;
			temp-=T[st];
			st++;
		}
		if(flag && a==-1 && b==-1)
		{
			a=atemp;
			b=btemp;
		}	
		if(a>0 && 1LL*a*btemp<1LL*atemp*b)
		{
			a=atemp;
			b=btemp;
		}
	}
	cout<<a<<"/"<<b<<endl;
}
