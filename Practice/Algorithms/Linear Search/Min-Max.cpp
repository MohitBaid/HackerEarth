#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i;	cin>>n;
	long long int sum=0,min=1000000000000000,max=-1,temp;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		if(temp>max)		max=temp;
		if(temp<min)		min=temp;
		sum+=temp;
	}
	cout<<sum-max<<" "<<sum-min<<endl;
}

