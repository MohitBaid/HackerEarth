#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int n;	scanf("%d",&n);
	int un=1,i;
	int A[n];
	for(i=0;i<n;i++)
			scanf("%d",&A[i]);
	qsort(A,n,sizeof(int),cmpfunc);
	for(i=0;i<n-1;i++)
	{
		if(A[i]!=A[i+1])
			un++;
	}		
	//printf("%d",un);
	long long int ans=1;
	for(i=un;i>=1;i--)
	{
		//printf("%lld\n", ans);
		ans=ans*i;
	}	
	printf("%lld",ans);			
	return 0;		
}
