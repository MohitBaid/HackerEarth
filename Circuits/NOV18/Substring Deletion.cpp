#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int p[26];
	p[0] = 1;
	for(int i=1;i<26;i++)		p[i] = p[i-1]*2;
	string str;
	while(!cin.eof())
	{
		cin>>str;
		set < char > ch;
		vector < int > v;
		int i;
		
		int r[str.size()],val=0,temp = 0;
		
		for(int i=0;i<str.size();i++)
		{
			ch.insert( str[i] - 'a'  );
			v.push_back(0);
		}
	
		for(i=str.size()-1;i>=0;i--)
		{
			r[i] = temp;
			temp = temp | p[str[i] -'a'];
		}
	
		for(set < char > :: iterator mt = ch.begin();mt!=ch.end();mt++)
		{
				val = val | (p[(*mt)]);
		}
		
		int prev = 0;
		while(ch.size()>0)
		{
			for( set < char > :: iterator mt = ch.begin();mt!=ch.end();mt++)
			{
				int  k  = (*mt);
				char c = k + 'a';
				bool find  = false; 
				for(i=prev;i<str.size();i++)
				{
					if(str[i]==c)
					{
						if( ((p[c-'a'] | r[i]) == val) || p[c-'a'] == val)
						{
							v[i] = 1;
							find = true;
							prev = i+1;
							break;		
						}
					}
				}
				if(find)
				{
					for(i=prev;i<str.size();i++)
					{
						if( (r[i] & p[c-'a']) == p[c-'a'])
						{
							r[i]-=p[c-'a'];
						}
					}
					val-=p[c-'a'];
					ch.erase(c - 'a');
					break;
				}
			}
		}
		
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==1)
				cout<<str[i];
		}
		cout<<"\n";
	}
}
