#include<stdio.h>
int gcd(int n1, int n2)
{
    if (n2!=0)
       return gcd(n2, n1%n2);
    else 
       return n1;
}
int main()
{
	/*int A[1011],i,j;
	A[0]=0;
	A[1]=1;
	for(i=2;i<=1010;i++)
			A[i]=2*(i-1);
	for(i=3;i<=1010;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				A[i]=A[i]-2;
			}	
		}
	}*/
	long long int l,r,g,ans=0,i,j;
	scanf("%lld %lld %lld",&l,&r,&g);
	long long int lp,up;
	for(lp=l;lp%g!=0;lp++);
	for(up=r;up%g!=0;up--);
	lp=lp/g;
	up=up/g;
	for(i=lp;i<=up;i++)
	{
		for(j=lp;j<=up;j++)
		{
			if(gcd(j,i)==1)
			{
				//printf("%lld %lld\n",j,i);
				ans++;
			}	
		}
	}
	/*printf("\n\n\n");
	for(i=lp;i<=up;i++)
	{
		printf("%lld--> %lld\n",i,A[i]);
	}*/			
	printf("%lld",ans);		
}
