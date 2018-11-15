#include<bits/stdc++.h>
using namespace std;
int main()
{
	string ch,ch3,ch4;			cin>>ch;
	string ch2=string(ch.rbegin(),ch.rend());
	int l=ch.size(),i;
	int ans=0;
	for(i=0;i<l;i++)
	{
		if(ch[i]==ch2[i]);
		else		ans++;
	}
	int ans2=ans/2,j,ans3=0;
	ch3=ch[0];
	int k=l;
	for(j=0;j<k;j++)
	{
		ans3=0,ans=0;
		ch4=ch+ch3;
		l++;
		ch2=string(ch4.rbegin(),ch4.rend());
		ans=j+1;
		for(i=0;i<l;i++)
		{
			if(ch4[i]==ch2[i]);
			else		ans3++;
		}
		ans=ans+ans3/2;
		ans2=min(ans,ans2);
		ch3=ch[j+1]+ch3;
	}
	cout<<min(ans,ans2)<<endl;
}
