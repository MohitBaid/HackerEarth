#include<stdio.h>
int main()
{
	int t,i;	scanf("%d",&t);
	int A[26];
	
	while(t--)
	{
		int l=0;
		double ans=0.000000;
		for(i=0;i<26;i++)
			A[i]=0;
		char ch[100002];
		scanf("%s",ch);
		for(i=0;ch[i]!='\0';i++)
		{
			int d=ch[i]-65;
			A[d]++;
		}
		l=i;
		for(i=0;i<26;i++)
		{
			if(A[i]>0)
				ans+=((double)(A[i])/l)*A[i];
		}
		printf("%.6lf\n",ans);
	}
}
