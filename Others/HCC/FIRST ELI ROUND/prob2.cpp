#include<stdio.h>
int main()
{
	int t;	scanf("%d",&t);
	while(t--)
	{
			int n,i,ans=0;	scanf("%d",&n);
			char ch[n+2];
			scanf("%s",ch);
			for(i=0;ch[i]!='\0';i++)
			{
				if(ch[i]==49)
					ans++;
			}
			printf("%d\n",ans);
	}
}
