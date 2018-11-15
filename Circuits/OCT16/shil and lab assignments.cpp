#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int A[100001];
int main()
{
	int n,m,i,j,c=0;	scanf("%d %d",&n,&m);
	int B[n];
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	qsort(B,n,sizeof(int),cmpfunc);		
	for(i=0;i<n;i++)
	{	
		if(B[i]<=m&&A[B[i]]==0)
		{
			A[B[i]]=1;
			c++;
			//printf("-----%d---%d-----\n",B[i],B[i]);	
		}
		else
		{
			int flag=0;
			for(j=1;j<=m;j++)
			{
				if(B[i]%j==0)
				{
					if(A[j]==0)
					{
						A[j]=1;
						c++;	
			//			printf("-----%d---%d-----\n",j,B[i]);	
						break;
					}
					else
					{
						int k=B[i]/j;
						if(A[k]==0&&k<=m)
						{
							A[k]=1;
							c++;	
			//				printf("-----%d----%d----\n",k,B[i]);
							break;
						}
					}	
				}
			}	
		}
	}		
	printf("%d\n",c);
}
