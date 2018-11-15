#include<stdio.h>
int  main()
{
	char ch[3100],s[3100];		scanf("%s",ch);
	int n,i,nos=0;				scanf("%d",&n);
	int c,ans=0,j;
	for(i=0;ch[i]!='\0';i++)
		if(ch[i]=='*')
			nos++;
	int l=i;		
	int A[l];
	for(i=0;i<l;i++)		A[i]=0;		
	for(i=0;i<n;i++)
	{
		scanf("%s",s);	c=0;int p=0;
		for(j=0;ch[j]!='\0';j++)
		{	
			if(ch[j]=='*');
			else if(ch[j]!=s[j])
			{
					c++;
					p=j;
			}		
		}			
		if(c==1)
			A[p]++;
		else if(c==0)
			for(j=0;j<l;j++)
				A[j]++;		
	}
	ans=A[0];
	for(i=0;i<l;i++)
		if(A[i]>ans)
			ans=A[i];
	printf("%d",ans);
	return 0;
}
