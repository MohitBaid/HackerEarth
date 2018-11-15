#include<bits/stdc++.h>
using namespace std;
int check(int A[],int B[])
{
	int i;
	for(i=0;i<10;i++)
		if(A[i]>B[i])
			return 0;
	return 1;		
}
void print(string s,int a,int b)
{
	int i;
	printf("--  %d -- %d --",a,b);
	for(i=0;i<a;i++)			printf("*");
	for(i=a;i<=b;i++)			printf("%c",s[i]);
	for(i=b+1;i<s.size();i++)		printf("*");
	printf("\n");
}
int main()
{
	string s;			cin>>s;
	int n,i,j=0;		cin>>n;
	int A[n];
	long long int ans=0;
	for(i=0;i<n;i++)		cin>>A[i];
	int C[10]={0},B[10]={0};
	for(i=0;i<n;i++)		C[A[i]]++;
	for(i=0;i<s.size();i++)
	{
		B[s[i]-'0']++;
		if(check(C,B))		
		{
			ans+=(s.size()-i);
			while(j<=i)
			{
				B[s[j]-'0']--;
				j++;
				if(check(C,B))	ans+=(s.size()-i);
				else break;
			}
		}
		//cout<<ans<<" "<<i<<endl;
	}
	//if(check(C,B))		ans++;
	cout<<ans<<endl;
}
