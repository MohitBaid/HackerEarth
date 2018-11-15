#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;    cin>>n>>m;
    set < pair <int,int> > s;
    map <int,int> mp;
    for(i=0;i<n;i++)    
    {
        int temp;
        cin>>temp;
        mp[temp]++;
        s.insert(make_pair(temp,i+1));
    }
	set < int > div;
	for(i=1;i*i<=m;i++)
	{
		if(m%i==0)
		{
			div.insert(i);
			div.insert(m/i);
		}
	}    
    set < pair <int,int> >:: iterator it;
    set < int> :: iterator jt;
    int flag=1;
    for(jt=div.begin();jt!=div.end();jt++)
    {
    	int k=*jt;
    	int f=m/k;
    	if(mp[f]>=k)
    	{
    		cout<<f<<endl;
    		cout<<k<<" ";
    		int c=0;
    		for(it=s.begin();c<k;it++,c++)
    		{
    			if(it->first==f)
    				cout<<it->second<<" ",c++;
    		}
    		flag=0;
    		break;
    	}
    }
    if(flag)
    {
    	int m2=0,c2=0;
		int T[n+2];
		for(i=0;i<=n;i++)	T[i]=0;
		for(it=s.begin();it!=s.end();it++)    
		{
			m2+=it->first;
			if(m2>m)	
			{ m2-=it->first;break;}
			c2++;
			T[it->second]++;
		}
	    cout<<m2<<endl;
		cout<<c2<<" ";
		for(i=1;i<=n;i++)	if(T[i])		cout<<i<<" ";	cout<<endl;
	}
	return 0;
}

