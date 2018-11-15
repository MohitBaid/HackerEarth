#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int  main()
{
		int k,f=1,i;		scanf("%d",&k);
		long long int N=1;
		int a,p;
		while(k--)
		{
				scanf("%d %d",&p,&a);
				f=f*(a+1);
				for(i=0;i<a;i++)
					N=N*p;	
		}			
		int A[f];
		int j=0;
		for(i=1;i*i<=N;i++)
		{
			if(N%i==0)
			{
				A[j++]=i;
				A[j++]=(N/i);
			}			
		}
		qsort(A,f,sizeof(int), cmpfunc);
		int B[f];
		B[0]=A[0];
		B[1]=A[1];
		B[f-1]=A[2];
		for(i=2;i<f-1;i++)
				B[i]=A[i+1];
		int flag=1;		
		for(i=0;i<f-1;i++)	
		{
			int p=B[i]%B[i+1];
			int q=B[i+1]%B[i];
			if(p==0||q==0);
			else
				flag=0;
				
		}	
		if(flag)
			for(i=0;i<f;i++)
				printf("%d ",B[i]);
		else
			printf("No");			
		return 0;	
}
