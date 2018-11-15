#include<stdio.h>
struct fighter
{
	int num;
	int str;	
};
int main()
{
	int n,q,i,m,d,j;
	scanf("%d %d",&n,&q);
	struct fighter s[n],temp;	d=n;
	int ansque[q];
	int mat[n];
	for(i=0;i<n;i++)
	{
		s[i].num=i+1;
		mat[i]=0;
		scanf("%d",&s[i].str);
	}
	for(i=0;i<q;i++)
		scanf("%d",&ansque[i]);	
	while(n>1)
	{
		m=0;
		for(i=0;i<n;i=i+2)
		{
			if(m==(n/2)&&(n)%2!=0)
			{
				temp=s[m];
				s[m]=s[n-1];
				s[n-1]=temp;
				m++;
				break;
			}
			mat[s[i].num-1]++;
			mat[s[i+1].num-1]++;
			if(s[i].str>s[i+1].str)
			{
				temp=s[m];
				s[m]=s[i];
				s[i]=temp;
				m++;
			}
			else
			{
				temp=s[m];
				s[m]=s[i+1];
				s[i+1]=temp;
				m++;
			}
		}
		n=m;
	}	
	for(i=0;i<q;i++)
		printf("%d\n",mat[ansque[i]-1]);			
	return 0;
}
