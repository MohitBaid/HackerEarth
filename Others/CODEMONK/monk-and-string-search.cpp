#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct string
{
	char ch[100005];
	int l;
};
int cmpfunc(const void *p, const void *q) 
{
    int l = ((struct string *)p)->l;
    int r = ((struct string *)q)->l; 
    return (l - r);
}
int main()
{
	int n,i,j,k;	scanf("%d",&n);
	string s[n];
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i].ch);
		for(j=0;s[i].ch[j]!='\0';j++);
		s[i].l=j;
	}
	qsort(s,n,sizeof(struct string),cmpfunc);
	char str[100005];
	int max=0;
	for(i=0;s[0].ch[i]!='\0';i++)
	{
		for(j=i;s[0].ch[j]!='\0';j++)
		{
			for(k=i;k<=j;k++)
			{
				str[k-i]=s[0].ch[k];			
			}
			str[k-i]='\0';
			int c=0;
			for(k=1;k<n;k++)
			{
				if(strstr(s[k].ch,str)!=NULL)
				{
					c++;
				}	
				else	break;
			}
			if(c==n-1)
			{
				int t=j-i+1;
				if(t>max)
					max=t;	
			}	
		}
	}
	printf("%d",max);
	
}
