#include<stdio.h>
int main()
{
	long long int a,b;
	int i,j,k,f,m,l=0,flag,flag1,flag2=0,flag4;
	long int n;
	int rems[16];
	for(i=1;i<16;i++)
		scanf("%d",&rems[i]);
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%lld %lld",&a,&b);
		m=a;
		long long int p=1;
		while(m>0)
			{
				p=p*10;
				l++;
				m=m/10;
			}	
		i=a%l;
		j=rems[l]-i;
		if(j>=0)		a=a+j;
		else 		a=a+j+l;				
		int res=0;
		for(i=a;i<=b;i=i+l)
		{	
			int num[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			int d=0,q=i;m=i;
			int u=0;
			flag=0;
			flag1=0;
			flag4=0;
			while(m>0)
			{
				d++;
				m=m/10;
			}
			int h=d+1;
			while(q>0)
			{
				num[d--]=q%10;
				q=q/10;
			}
			f=num[1];	
			for(j=2;j<h;j++)
			{
				u=num[j-1]*10+num[j];
				if(u==11||u==13||u==17||u==19||u==23||u==29||u==31||u==37||u==41||u==43||u==47||u==53||u==59||u==61||u==67||u==71||u==73||u==79||u==83||u==89||u==97)
				{
						flag1=1;
						break;
				}		
				f=num[j]+f*10;		
				if(f%j!=rems[j])
				{
					flag=1;
					break;
				}			
			}
			if(flag==0&&flag1==1)
					res++;
		}	
		printf("%d\n",res);
	}	
}
