#include<bits/stdc++.h>
#define int long long int 
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		int k[n];	char ch[n];
		int ca=0,cb=0;
		for(int i=0;i<n;i++)
		{
			cin>>k[i]>>ch[i];
			if(ch[i]=='A')		ca+=k[i];
			else				cb+=k[i];	
		}
		if(ca ==0 || cb == 0)
		{
			cout<<ca+cb<<endl;
			continue;
		}
		//cout<<ca<<" "<<cb<<endl;
		int g = __gcd(ca,cb);
		ca/=g;		
		cb/=g;
		int a=0,b=0,ans=0;
		for(int i=0;i<n;i++)
		{	
			//cout<<i<<" "<<ch[i]<<" "<<k[i]<<" "<<a<<" "<<b<<" "<<ans<<endl;
			if(ch[i]=='A')
			{
				int k1 = 1LL*ca*b;
				int k2 = 1LL*cb*a;
				//cout<<k1<<" "<<k2<<endl;
				if(k1 == k2 && k1!=0)
				{
					ans++;
					a = 0;
					b = 0;
				}
				else
				{
					if( k1>k2 && k1 <= ( k2 + 1LL*k[i]*cb ) )
					{
						int add =	1LL*ca*b;
						//cout<<add<<" "<<cb<<endl;
						if(add%cb!=0)
						{
							a+=k[i];
							continue;	
						}
						ans++;
						add/=cb;
						add-=a; 
						b = 0;
						a = k[i] - add;
					}		
					else
					{
						a+=k[i];
					}
				}	
			}
			else
			{
				int k1 = ca*b;
				int k2 = cb*a;
				//cout<<k1<<" "<<k2<<endl;
				if(k1 == k2 && k1!=0)
				{
					ans++;
					a = 0;
					b = 0;
				}
				else
				{
					if( k2>k1  && k2 <= (k1 + 1LL*k[i]*ca) )
					{
						int add =	1LL*cb*a;
						if(add%ca!=0)
						{
							b+=k[i];
							continue;	
						}	
						ans++;
						add/=ca;
						add-=b; 
						a = 0;
						b = k[i] - add;
					}
					else
					{
						b+=k[i];
					}
				}
			}
			//cout<<i<<" "<<ch[i]<<" "<<k[i]<<" "<<a<<" "<<b<<" "<<ans<<endl;
		}
		if(a!=0 || b!=0)	ans = 1;
		cout<<ans<<endl;
	}
}
