#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T,i;	cin>>T;
	while(T--)
	{
		string a,b;	
		cin>>a>>b;
		string ans="",exp="";
		if(a.size()>b.size())
		{
			int diff = a.size() - b.size();
			for(i = 0;i<diff; i++)
			{
				b = '0' + b;
			}
			//cout<<a<<" "<<b;
		}
		else if(b.size()>a.size())
		{
			int diff = b.size() - a.size();
			for(i = 0;i<diff; i++)
			{
				a = '0' + a;
			}
			//cout<<a<<" "<<b;
		}
		ans.resize(a.size()+1);
		exp.resize(a.size()+1);
		int carry = 0;
		for(i=a.size()-1;i>=0;i--)
		{
			int x = a[i] + b[i]  - '0' - '0';
			int y = x%10;
 			int a = x+carry;
			ans[i+1] = y + '0';
			exp[i+1] = a%10 + '0';
			carry =  a/10;	
		}
		ans[0] = '0';
		exp[0] = carry + '0';	
		//cout<<ans<<" "<<exp<<endl;
		char** ch;
		int t1 = strtoll(ans.c_str(),ch,10);
		int t2 = strtoll(exp.c_str(),ch,10);
		int t3 = t1-t2;
		cout<<abs(t1-t2)<<endl;
	}
}
