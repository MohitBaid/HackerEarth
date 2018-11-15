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
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,m,i,g=0,r;	scanf("%d %d",&n,&m);
		int num=9*m;
		int den=(8*n)+m;
		g=gcd(den,num);
		printf("%d/%d\n",num/g,den/g); 	
	}
	return 0;
}
