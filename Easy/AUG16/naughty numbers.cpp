#include<stdio.h>
#include<math.h>
int main()
{
	int Q;	scanf("%d",&Q);
	while(Q--)
	{
		int a,b,i,m,d=0,p=1,res,c=0,j,k;scanf("%d %d",&a,&b);
		m=a;
		while(m>0)
		{
			m=m/10;
			d++;
			p=p*10;
		}
		for(i=a;i<=b;i++)
		{
			if(i==p)
			{
				d++;
				p=p*10;
			}
			m=i;res=0;
			int flag1=0;
			if(i==1)
				res++;
			while(m%2==0)
				{
					flag1=1;
					m=m/2;
				}	
			if(flag1==1)
				{
					res++;
					flag1=0;	
				}	
			for(j=3;j<=sqrt(m);j=j+2)
			{
				while(m%j==0)
				{
					flag1=1;
					m=m/j;
				}
				if(flag1==1)
				{
					res++;
					flag1=0;	
				}	
			}
			if(m>2)
				res++;
			if(res==d)
				c++;		
		}
		printf("%d\n",c);
	}
	return 0;
}
