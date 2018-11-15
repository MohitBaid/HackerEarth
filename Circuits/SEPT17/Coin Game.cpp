#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		long long int ans=0,temp;
		while(n--)
		{
			cin>>temp;
			while(temp%2==0)
			{
				temp=temp/2;
				ans++;
			}
		}
		if(ans%2)		cout<<"Charlie\n";
		else			cout<<"Alan\n";
	}
}
