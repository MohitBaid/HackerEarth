#include<stdio.h>
long long int nCr(long long int n,long long int r)
{
	if(n==r||r==0)	return 1;
	else if(r==1)	return n;
	return nCr(n-1,r)+nCr(n-1,r-1);
}
int main()
{
	long long int n,i,f,ans=0,temp;int k;	scanf("%lld %ld",&n,&k);
	for(i=n;;i--)
	{
		if(i%k==0)
		{
			f=i;
			break;
		}	
	}
	printf("--%lld---",f);
	for(i=f;i>=0;i=i-k)
	{
		printf("TTTTTT\n");
		ans=ans+nCr(n,i);
		printf("-------%lld------\n",ans);
	}		
	ans=ans%100000;
	printf("%lld\n",ans);
	return 0;	
}
