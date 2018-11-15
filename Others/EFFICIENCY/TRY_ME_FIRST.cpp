#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
char ch[10000002];
int main()
{
		scanf("%s",ch);
		int A[26],B[26];
		long long int k=0,i;
		for(i=0;i<26;i++)
		{
			A[i]=0;
			B[i]=0;
		}
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]>=97 && ch[i]<=122)
			{
				if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u')
						k++;
				A[ch[i]-97]++;
			}
			else if(ch[i]>=65 && ch[i]<=90)
			{
				if(ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U')
						k++;
				B[ch[i]-65]++;
			}
		}
		printf("%lld ",k*k);
		k=0;
		for(i=0;i<26;i++)
		{
				if(A[i]!=0)
					k++;
				if(B[i]!=0)
					k++;	
		}
		printf("%lld",k);
}
