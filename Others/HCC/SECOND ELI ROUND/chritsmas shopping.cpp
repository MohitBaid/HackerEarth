#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int n,k,i,p=0;	scanf("%d %d",&n,&k);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);	
	qsort(A,n-1,sizeof(int),cmpfunc);
	long long int ans=0;
	i=n-1;
	while(i>=0)
	{	
		int m=k;
		p++;
		while(m--&&i>=0)
		{
			int x=A[i]*p;
			ans+=x;
			i--;
		}
	}
	printf("%lld\n",ans);
}
