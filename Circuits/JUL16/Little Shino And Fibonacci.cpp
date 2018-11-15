#include<stdio.h>
# define M 1000000007
int main()
{
	int i,j,d;
	int t;
	unsigned long long int a,b,g;
	long long int s=0;
	long int fib[15000];
	long int sum[15000];
	fib[0]=0;
	fib[1]=1;
	sum[0]=0;
	sum[1]=1;
	for(i=2;i<15000;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		sum[i]=sum[i-1]+(fib[i])%10000;
	}
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%I64d %I64d",&a,&b);
		a--;
		b--;
		if(b-a>15000)
		{
				g=(b-a)/15000;
				s+=sum[14999]*g;
				printf("%I64d     %I64d       %I64d\n",g,s,sum[14999]);
		}		
		a=a%15000;
		b=b%15000;
		if(a>b)
			s+=sum[14999]+sum[b]-sum[a-1];		
		else
		{
			if(a==0)
				s+=sum[b];
			else
				s+=sum[b]-sum[a-1];
		}			
		printf("%d\n",(s%M));
	}	
	return 0;
}

