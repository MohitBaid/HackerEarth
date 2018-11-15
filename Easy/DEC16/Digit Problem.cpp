#include<stdio.h>
int main()
{
	long long int x,m,p=1,s=0;
	int k,ans=0,pos=0,t=0;
	scanf("%lld %d",&x,&k);
	m=x;
	int A[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	while(m>0)
	{
		t=m%10;
		A[pos++]=t;
		m=m/10;
	}
	for(int i=0;i<pos;i++)
		printf("%d ",A[i] );
	while(pos>0)
	{
		pos--;
		if(ans<k)
		{
			if(A[pos]!=9)
				ans++;
			s=s*10+9;	
		}
		else
		{
			s=s*10+A[pos];
		}	
	}	
	printf("%lld",s);
}
