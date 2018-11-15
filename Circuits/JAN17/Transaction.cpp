#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int T,Q;	scanf("%d %d",&T,&Q);
	int i,A[T],B[T];
	for(i=0;i<T;i++)
	{
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
	qsort(B,T,sizeof(int),cmpfunc);
	/*for(i=0;i<T;i++)
		printf("%d ",B[i]);*/
	while(Q--)
	{
		int n,m;	scanf("%d %d",&n,&m);
		int flag=0;
		/*for(i=0;i<(T-m+1);i++)
			if(B[i]==n)
				{
					flag=1;
					break;
				}
		if(flag)
		{*/
			i=0;
			while( m && i<=T )
			{
				if(A[i]>=n)
					m--;
				i++;	
			}
		if(i<=T)	
			printf("%d\n",A[i-1]);
		//}
		else
			printf("-1\n");		
	}
		
			
}
