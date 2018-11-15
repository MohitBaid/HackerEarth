#include<stdio.h>
int main()
{
	int n,q,c,m=0,i;	scanf("%d %d",&n,&q);
	long long int A[q][4];
	int r[3],R[3];
	long long int tot=0,res=0;
	while(q--)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%lld %lld %lld %lld",&A[m][0],&A[m][1],&A[m][2],&A[m][3]);
			tot+=A[m][3];
			m++;
		}
		else
		{
			scanf("%d %d %d %d %d %d",&r[0],&r[1],&r[2],&R[0],&R[1],&R[2]);
			res=0;
			for(i=0;i<m;i++)
			{
				if(A[i][0]>=r[0]&&A[i][0]<=R[0])
				{
					if(A[i][1]>=r[1]&&A[i][1]<=R[1])
					{
						if(A[i][2]>=r[2]&&A[i][2]<=R[2])
						{
							res+=A[i][3];
						}
					}
				}
			}
			printf("%lld\n",tot-res);
		}
		
	}
}
