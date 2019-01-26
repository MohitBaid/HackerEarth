#include<bits/stdc++.h>
using namespace std;
bool check(int m , string s)
{
	if(m>s.size())
		return false;
	int i,j,n = s.size();
	vector < int > c;
	c.resize(26);
	for(i=0;i<26;i++)	c[i]=0;
	for(i=0;i<m;i++)
	{
		c[s[i]-'a']++;
	}
	for(i=0;i<26;i++)
		if(c[i]>=(m/2))
			return true;
	for(i=m;i<n;i++)
	{
		c[s[i-m]-'a']--;
		c[s[i]-'a']++;
		for(j=0;j<26;j++)
		{
			if(c[j]>=(m/2))
				return true;
		}
	}
	return false;
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		string s;	cin>>s;
		int l = 0,u = n;
		while(l<u)
		{
			int m = ceil((l + u)/2.0);
			if(check(m,s))
				l = m;
			else
			{
				if(check(m+1,s))
					l=m+1;
				else
				{
					if(check(m+2,s))
						l=m+2;
					else
					{
						if(check(m+3,s))
							l=m+3;
						else
						{
							if(check(m+4,s))
								l=m+4;			
							else
							{
								if(check(m+5,s))
								    l=m+5;
								else    
								{
								    if(check(m+6,s))
								        l=m+6;
							    	else    
								    {
								       if(check(m+6,s))
								           l=m+6;
								        else    
								        {
								            if(check(m+7,s))
								               l=m+7;
            								else    
            								{
            								    if(check(m+8,s))
                								    l=m+8;
                								else    
                								{
                								    if(check(m+9,s))
                    								    l=m+9;
                    								else    
                    								{
                    								    if(check(m+10,s))
                            							    l=m+10;
                            							else    
                            							{
                            							    if(check(m+11,s))
                            								    l=m+11;
                            								else    
                            								{
                            								    if(check(m+12,s))
                                								    l=m+12;
                                								else    
                                								{
                                								    if(check(m+13,s))
                                    								    l=m+13;
                                    								else    
                                    								{
                                    								    u = m-1;
                                    						        }
                                						        }
                            						        }
                            					        }
                    						        }
                						        }
                            			     }
						                }
						            }
						        }
							}
						}
					}
				}
			}
		}
		cout<<l<<endl;
	}
}
