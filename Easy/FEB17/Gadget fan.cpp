#include<stdio.h>
#include<stdlib.h>
long long int c(long long int k)
{
	return k/2+k%2;
}	
int main()
{
	int t;	scanf("%d",&t);
	while(t--)
	{
		long long int a,k,d;	scanf("%lld %lld",&a,&k);
		long long int i,j,ans=0;
		if(a>=k)
			a=k-1;
		ans=((k)*(k))/4;
		if(a==k-1)	        
			printf("%lld\n",ans);
		else
		{
			d=k-1-a;
			if(d<=c(k-1))
				ans=ans-((d)*(d+1))/2;
			else
				{
					ans-=((c(k-1))*(c(k-1)+1))/2;
					d=d-c(k-1)-1;
					k=k-c(k-1)-1;
					ans-=(((k)*(k+1))/2-((k-d)*(k-(d+1)))/2);
				}
			printf("%lld\n",ans);		
		}				
	}
}
