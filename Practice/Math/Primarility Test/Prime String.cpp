#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	if(n==1)		return 0;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;		
}
int main()
{
	int T,i;		scanf("%d",&T);
	while(T--)
	{
		int A[26]={0};
		char ch[100005];	scanf("%s",ch);
		for(i=0;ch[i]!='\0';i++)
			A[ch[i]-'a']++;
		int flag=1;
		int temp=0;
		for(i=0;i<26;i++)
		{
			if(A[i]>0)
			{
				temp++;
				if(!isprime(A[i]))
				{
					flag=0;
					break;
				}
			}
		}	
		if(!isprime(temp))	flag=0;
		if(flag)	printf("YES\n");
		else		printf("NO\n");
	}
}
