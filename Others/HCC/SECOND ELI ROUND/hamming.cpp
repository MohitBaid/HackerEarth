#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,i,j,k,r=0;
	scanf("%d %d",&n,&m);
	char a[n][m+1];
	int b[26];
	for(i=0;i<n;i++)
	{
	    scanf("%s",a[i]);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<26;j++)
			b[j]=0;
		for(j=0;j<n;j++)
		{
			int d=(int)a[j][i];
			b[d-97]++;
		}
		int p=0;
		int max=b[0];
		for(j=0;j<26;j++)
		{
			if(max<b[j])
			{
				max=b[j];
				p=j;
			}
		}
		printf("%c",(char)(p+97));		
	}
	printf("\n");
	return 0;
}	
