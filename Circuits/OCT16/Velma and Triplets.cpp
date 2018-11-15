#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
		/*int n,i,j,k,ans=0;	scanf("%d",&n);
		int A[n];
		for(i=0;i<n;i++)
				scanf("%d",&A[i]);
		qsort(A,n-1,sizeof(int),cmpfunc);
		int l;
		l=n;
		if(n>100)
			l=400;
		for(i=0;i<l;i++)
		{
			for(j=i+1;j<l;j++)
			{
				for(k=j+1;k<l;k++)
				{
					int s=A[i]+A[j]+A[k];
					int p=A[i]*A[j]*A[k];
					int t=s/p;
					//printf("%d %d %d \n",A[i],A[j],A[k]);
					ans+=t;
				}
			}
		}
		printf("%d\n",ans);	*/
		int i,j,k,c=0;
		for(i=1;i<=100;i++)
		{
			for(j=i;j<=100;j++)
			{
				for(k=j;k<=100;k++)
				{
					int s=i+j+k;
					int p=i*j*k;
					int t=s/p;
					if(t==1)
					{
						printf("%d-%d-%d-----> %d\n",i,j,k,t);
						c++;
					}	
				}
			}
		}
		printf("----NNNN-%d-NNNNN------\n",c);
		return 0;		
}
