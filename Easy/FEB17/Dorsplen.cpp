#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	long long int A[3],max,min,ans=0,d,i,j;
		scanf("%lld %lld %lld",&A[0],&A[1],&A[2]);
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			if(A[j]>A[j+1])
				{
					d=A[j];
					A[j]=A[j+1];
					A[j+1]=d;
				}	
	ans=A[0];
	A[1]-=A[0];
	A[2]-=A[0];		
	ans=(A[2]+A[1]+1)/2;
		printf("%lld",ans);
}

