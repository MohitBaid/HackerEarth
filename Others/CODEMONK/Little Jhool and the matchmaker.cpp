#include<stdio.h>
#include<stdlib.h>
struct name
{
	char ch[30];
	int k;
};
int cmpfunc(const void *p, const void *q) 
{
    int l = ((struct name *)p)->k;
    int r = ((struct name *)q)->k; 
    return (l - r);
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,k,i,j;	scanf("%d %d",&n,&k);
		struct name na[n];
		for(i=0;i<n;i++)
		{
			scanf("%s",na[i].ch);
			int m=0;
			int A[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			for(j=0;na[i].ch[j]!='\0';j++)
			{
				if(na[i].ch[j]=='l'||na[i].ch[j]=='i'||na[i].ch[j]=='t'||na[i].ch[j]=='e'||na[i].ch[j]=='j'||na[i].ch[j]=='h'||na[i].ch[j]=='o'||na[i].ch[j]=='L'||na[i].ch[j]=='I'||na[i].ch[j]=='T'||na[i].ch[j]=='E'||na[i].ch[j]=='J'||na[i].ch[j]=='H'||na[i].ch[j]=='O')
				{
					int d=(int)na[i].ch[j];
					if(d>=97)
					{
						if(A[d-97]==0)
						{
							m++;
							A[d-97]++;
						}
					}
					else
					{
						if(A[d-65]==0)
						{
							m++;
							A[d-65]++;
						}
					}	
				}
			}	
			na[i].k=m;	
		}
		qsort(na,n,sizeof(struct name),cmpfunc);
		for(i=0;i<n;i++)
		{
			printf("%s  %d\n",na[i].ch,na[i].k);
		}
		printf("\n");
	}
}
