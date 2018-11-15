#include<stdio.h>
int P[25]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216};
int A[1000001];
int main()
{
	A[0]=0;int i,j;
	for(i=1;i<=1000000;i++)
	{
		for(j=0;j<25;j++)
		{
			if(i<=P[j+1]&&i>=P[j])
				A[i]=j+1;
		}
	}
	int N,Q,l,r;	scanf("%d %d",&N,&Q);
	int B[N];
	int sol[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&B[i]);
		sol[i]=A[B[i]];
	}
	while(Q--)
	{
		scanf("%d %d",&l,&r);
		int ans=0;
		l--;
		r--;
		for(i=l;i<=r;i++)
			ans+=sol[i];
		if(ans%2!=0)
			printf("Mishki\n");
		else
			printf("Hacker\n");		
	}
	return 0;
}
