#include<stdio.h>
int main()
{
	int n,k,q,i;	scanf("%d %d %d",&n,&k,&q);
	int A[n],parent[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	parent[0]=-1;	
	for(i=1;i<n;i++)
	{
		scanf("%d",&parent[i]);
		parent[i]--;
	}	
	for(i=0;i<q;i++)
	{
		int s,e;	scanf("%d %d",&s,&e);
		int n=0;
		s--;
		e--;
		int p=1;
		while(e!=s)
		{
			n=n+(A[e])*p;
			e=parent[e];
			p=p*10;
		}
		n=n+A[e]*p;
		if(n%k==0)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	return 0;	
}
