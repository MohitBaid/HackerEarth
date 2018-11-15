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
		int z=l;		
		i=a%l;
		j=rems[l]-i;
		if(j>=0)		a=a+j;
		else 		a=a+j+l;				
		int res=0;
		for(i=a;i<=b;i=i+z)
		{	
			int num[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			if(i%p<9)
			{
				l++;
				p=p*10;
			}
			int p1=p/10;
			int p2=p/100;
			int d=l,q1=i,q2=i;
			int u;
			flag=0;
			flag1=0;
			flag4=0;
			int h=d+1;
			int v=1;
			while(p2>1)
			{
				u=q1/p2;
				if(u==11||u==13||u==17||u==19||u==23||u==29||u==31||u==37||u==41||u==43||u==47||u==53||u==59||u==61||u==67||u==71||u==73||u==79||u==83||u==89||u==97)
				{
						flag1=1;
						break;
				}
				m=q1/(p2*10);	
				q1=q1-(p2*10)*m;
				p2=p2/10;
			}	
			while(q2>0)
			{
				f=q2/p1+f*10;
				if(f%v!=rems[v])
				{
					flag=1;
					break;
				}			
				v++;
				m=q2/p1;	
				q2=q2-p1*m;
			}
			if(flag==0&&flag1==1)
					res++;
		}	
		printf("%d\n",res);
	}	
}
